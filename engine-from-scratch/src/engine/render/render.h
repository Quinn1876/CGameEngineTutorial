#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <linmath.h>

#include "../type.h"

typedef struct render_state {
    SDL_Window *window;
    f32 width;
    f32 height;
} Render_State;

void render_init(void);
void render_begin(void);
void render_end(void);

#endif
