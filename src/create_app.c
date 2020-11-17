#include "../include/create_app.h"
#include <stdio.h>
#include <SDL.h>


SDL_Window *createWindow(char *titreFenetre, int longueur, int largeur, Uint32 modeAffichage){
    SDL_Window *window = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) == 0) {
        window = SDL_CreateWindow("Casse-brique", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, longueur, largeur,
                                  modeAffichage);

        if(window == NULL){
            fprintf(stderr,"Erreur creation fenetre : %s",SDL_GetError());
        }
    } else {
        fprintf(stderr,"Erreur init SDL : %s",SDL_GetError());
    }

    return window;
}