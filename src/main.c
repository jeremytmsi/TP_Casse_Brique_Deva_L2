#include <stdio.h>
#include <SDL.h>
#include "../include/create_app.h"
#include "../include/render.h"
#include "../include/menu.h"

int main(int argc, char *argv[]) {
    int continuer = 1;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event e;

    window = creerFenetre("Casse-brique",640,480,SDL_WINDOW_SHOWN);
    renderer = creerRendu(window);

    afficherRendu(renderer);


    while(continuer){
        SDL_WaitEvent(&e);
        switch(e.type) {
            case SDL_QUIT:
                continuer = 0;
                close_app(window, renderer);
                break;
        }
        switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
                continuer = 0;
                close_app(window,renderer);
                break;
        }
    }

}
