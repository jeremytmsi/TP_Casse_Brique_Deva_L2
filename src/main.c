#include <stdio.h>
#include <SDL.h>
#include "../include/create_app.h"
#include "../include/render.h"

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    window = creerFenetre("Casse-brique",1920,1080,SDL_WINDOW_FULLSCREEN);
    renderer = creerRendu(window);

    afficherRendu(renderer);

    SDL_Delay(3000);

    close_app(window,renderer);
}
