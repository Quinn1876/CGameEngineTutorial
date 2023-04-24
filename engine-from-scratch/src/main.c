#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>

#define SDL_MAIN_HANDLED /* Do this so that SDL doesn't try to add a main function */
#include <SDL2/SDL.h>

#include "engine/global.h"
#include "engine/render.h"
#include "engine/config.h"
#include "engine/input.h"
#include "engine/time.h"

#define GLOBAL_SPEED 500
static bool should_quit = false;
static vec2 pos;

// #define DEBUG_INPUT
static void input_handle(void) {
    #ifdef DEBUG_INPUT
    puts("Key State:");
    printf("Left Key: %d\n", global.input.left);
    printf("Right Key: %d\n", global.input.right);
    printf("Up Key: %d\n", global.input.up);
    printf("Down Key: %d\n", global.input.down);
    #endif
    if (global.input.left == KS_PRESSED || global.input.left == KS_HELD) {
        pos[0] -= GLOBAL_SPEED * global.time.delta;
    }
    if (global.input.right == KS_PRESSED || global.input.right == KS_HELD) {
        pos[0] += GLOBAL_SPEED * global.time.delta;
    }
    if (global.input.up == KS_PRESSED || global.input.up == KS_HELD) {
        pos[1] += GLOBAL_SPEED * global.time.delta;
    }
    if (global.input.down == KS_PRESSED || global.input.down == KS_HELD) {
        pos[1] -= GLOBAL_SPEED * global.time.delta;
    }
    if (global.input.escape == KS_PRESSED || global.input.escape == KS_HELD) {
        should_quit = true;
    }
}

int main() {
    time_init(60);
    config_init();
    render_init();

    pos[0] = global.render.width * 0.5;
    pos[1] = global.render.height * 0.5;

    while (!should_quit) {
        time_update();
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    should_quit = true;
                }   break;

                default: {

                }
            }
        }

        input_update();
        input_handle();

        render_begin();

        render_quad(
            pos,
            (vec2){50, 50},
            (vec4){0,1,0,1}
        );

        render_end();
        time_update_late();
    }

    return 0;
}
