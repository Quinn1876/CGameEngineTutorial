#pragma once
#include "input.h"
#include "types.h"

typedef struct config {
    u8 keybinds[NUM_KEYS];
} Config_State;

void config_init(void);
void config_key_bind(Input_Key key, const char *key_name);
