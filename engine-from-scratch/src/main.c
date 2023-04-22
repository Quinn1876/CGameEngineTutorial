#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>

#define SDL_MAIN_HANDLED /* Do this so that SDL doesn't try to add a main function*/
#include <SDL2/SDL.h>

#define WINDOW_TITLE "MyGame"

int main(int argc, char *argv[]) {
    /* Supply SDL the parameters for OPEN_GL */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *window_p = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_OPENGL
    );

    if (!window_p) {
        printf("Failed to initialize window: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_GL_CreateContext(window_p);

    /* Glad loads all the pointers into the right places in memory so that we can use them. */
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("Failed to load GL: %s\n", SDL_GetError());
        exit(1);
    }

    puts("OpenGL Loaded");
    printf("Vendor:\t%s\n", glGetString(GL_VENDOR));
    printf("Renderer:\t%s\n", glGetString(GL_RENDERER));
    printf("Version:\t%s\n", glGetString(GL_VERSION));

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
    }

    return 0;
}
