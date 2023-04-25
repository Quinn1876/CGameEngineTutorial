#include <stdlib.h>
#include <string.h>

#include "../types.h"
#include "../array_list.h"
#include "../util.h"

#define ARRAY_LIST_ERROR_MEMORY "Could not allocate memory for Array_List\n"

/// @brief Create a new Array List of items with size item_size and an initial capacity of initial_capacity.
/// @param item_size
/// @param initial_capacity
/// @return pointer to the allocated Array_List. User is responsible for deallocating the memory.
Array_List *array_list_create(usize item_size, usize initial_capacity) {
    Array_List *list = malloc(sizeof(Array_List));
    if (!list)
        ERROR_RETURN(NULL, ARRAY_LIST_ERROR_MEMORY);
    list->item_size = item_size;
    list->capacity = initial_capacity;
    list->len = 0;
    list->items = malloc(item_size * initial_capacity);
    if (!list->items) {
        free(list);
        ERROR_RETURN(NULL, ARRAY_LIST_ERROR_MEMORY);
    }
    return list;
}

/// @brief Add an item to the end of the list
/// @param list
/// @param item
/// @return the index of the item added, -1 on failure
usize array_list_append(Array_List *list, void *item) {
    if (list->len == list->capacity) {
        list->capacity = list->capacity > 0 ? list->capacity * 2 : 1;
        void *items = realloc(list->items, list->item_size * list->capacity);
        if (!items) {
            ERROR_RETURN(-1, ARRAY_LIST_ERROR_MEMORY);
        }
        list->items = items;

    }

    usize index = list->len;
    list->len++;

    memcpy((u8*)list->items + index *list->item_size, item, list->item_size);

    return index;
}

/// @brief Get pointer to element in the array
/// @param list
/// @param index
/// @return
void *array_list_get(Array_List *list, usize index) {
    if (index >= list->len) {
        ERROR_RETURN(NULL, "Index out of Bounds\n");
    }
    return (u8*)list->items + index * list->item_size;
}

/// @brief Remove item at index without preserving order
/// @param list
/// @param index
/// @return 0 on success 1 on failure
u8 array_list_remove(Array_List *list, usize index) {
    if (list->len == 0) {
        ERROR_RETURN(1, "List is empty\n");
    }
    if (index >= list->len) {
        ERROR_RETURN(1, "Index out of Bounds\n");
    }
    if (list->len == 1) {
        list->len = 0;
        return 0;
    }

    --list->len;

    u8* item_ptr = (u8*)list->items + index * list->item_size;
    u8 *end_ptr = (u8*)list->items + list->len * list->item_size;
    memcpy(item_ptr, end_ptr, list->item_size);/* Copy the last item into the place of the item being removed */

    return 0;
}
