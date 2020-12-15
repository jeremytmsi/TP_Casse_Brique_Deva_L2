#include <SDL.h>
#include <stdio.h>

/**
 * Permet de créer une surface
 * @param window La fenêtre de l'application
 * @return La surface créée
 */
SDL_Surface *creerSurface(SDL_Window *window){

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    if(surface == NULL){
        fprintf(stderr,"Erreur creation surface : %s",SDL_GetError());
    }

    return surface;
}