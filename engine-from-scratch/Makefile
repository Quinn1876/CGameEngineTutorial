TARGET = game

BUILD_DIR = ./build
OBJECTS_DIR = $(BUILD_DIR)/objs

SOURCES = $(shell find ./src -name "*.c")
HEADERS = $(shell find ./src -name "*.h")

INC = \
-I ../include \
-I ../linmath.h \
-I ./engine \
-I ./engine/render

LDFLAGS = 	$(shell pkg-config --libs sdl2) \
		   	$(shell pkg-config --libs SDL2_mixer) \
	      	$(shell pkg-config --libs opengl) \
			-ldl

CFLAGS = 	$(shell pkg-config --cflags sdl2) \
			$(shell pkg-config --cflags SDL2_mixer) \
			$(shell pkg-config --cflags opengl) \
			$(INC) \
			-ggdb \
			-Werror -Wall -Wextra

CC = gcc

all: $(BUILD_DIR)/$(TARGET)
.PHONY: all

OBJECTS = $(addprefix $(OBJECTS_DIR)/,$(notdir $(SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(SOURCES)))

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
	mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: %.c $(HEADERS) | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@
	@echo ""

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

clean:
	rm -rf $(BUILD_DIR)
