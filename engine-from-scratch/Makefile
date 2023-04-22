TARGET = game

BUILD_DIR = ./build
OBJECTS_DIR = $(BUILD_DIR)/objs

SOURCES = $(shell find ./src -name "*.c")

INC = \
-I ../include \
-I ../linmath.h

LDFLAGS = 	$(shell pkg-config --libs sdl2) \
		   	$(shell pkg-config --libs SDL2_mixer) \
	      	$(shell pkg-config --libs freetype2) \
	      	$(shell pkg-config --libs opengl) \
			-ldl

CFLAGS = 	$(shell pkg-config --cflags sdl2) \
			$(shell pkg-config --cflags SDL2_mixer) \
			$(shell pkg-config --cflags freetype2) \
			$(shell pkg-config --cflags opengl) \
			$(INC)

CC = gcc

all: $(BUILD_DIR)/$(TARGET)

OBJECTS = $(addprefix $(OBJECTS_DIR)/,$(notdir $(SOURCES:.c=.o)))

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
	mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: ./src/%.c | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@
	@echo ""

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

clean:
	rm -rf $(BUILD_DIR)
