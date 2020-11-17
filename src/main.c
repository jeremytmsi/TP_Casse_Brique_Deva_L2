#include <stdio.h>
#include <SDL.h>
#include "../include/create_app.h"

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;

    window = createWindow("Casse-brique",640,480,SDL_WINDOW_SHOWN);

    SDL_Delay(3000);
}
