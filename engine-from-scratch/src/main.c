#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>

#define SDL_MAIN_HANDLED /* Do this so that SDL doesn't try to add a main function*/
#include <SDL2/SDL.h>

#include "engine/global.h"
#include "engine/render/render.h"

int main(int argc, char *argv[]) {
    render_init();

    bool should_quit = false;

    while (!should_quit) {
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

        render_begin();

        render_quad(
            (vec2){global.render.width * 0.5, global.render.height * 0.5 },
            (vec2){50, 50},
            (vec4){1,1,1,1}
        );

        render_end();
    }

    return 0;
}
