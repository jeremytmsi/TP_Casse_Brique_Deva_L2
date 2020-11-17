#include <SDL.h>
#include <stdio.h>


void afficherRendu(SDL_Renderer *renderer){
    SDL_RenderPresent(renderer);
}

SDL_Renderer *creerRendu(SDL_Window *window){
    SDL_Renderer *renderer = NULL;

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        fprintf(stderr,"Erreur creation renderer : %s",SDL_GetError());
    }

    return renderer;
}