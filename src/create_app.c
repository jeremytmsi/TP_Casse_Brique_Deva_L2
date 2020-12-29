#include "../include/create_app.h"
#include <stdio.h>
#include <SDL.h>

/**
 * Crée la fenêtre de l'application
 * @param titreFenetre Le titre de la fenêtre
 * @param longueur La longueur de la fenêtre
 * @param largeur La largeur de la fenêtre
 * @param modeAffichage Le mode d'affichage de la fenêtre (consulter la doc de la SDL pour plus d'info)
 * @return
 */
SDL_Window *creerFenetre(char *titreFenetre, int longueur, int largeur, Uint32 modeAffichage){
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

/**
 * Quitte l'application
 * @param window Pointeur contenant la fenêtre
 * @param surface Surface de l'écran
 */
void close_app(SDL_Window *window,SDL_Surface *surface){
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * Crée le fond de l'application
 * @param longueur La longueur de la fenêtre
 * @param largeur La largeur de la fenêtre
 * @param ecran Le pointeur qui contient l'adresse de l'écran
 * @param window Le pointeur qui contient l'adresse de la fenêtre
 */
void creer_fond(int longueur, int largeur,SDL_Surface *ecran, SDL_Window *window){
    SDL_Surface *fond = NULL;

    fond = SDL_CreateRGBSurface(0,longueur,largeur,32,0,0,0,0);

    if(fond != NULL){
        // On copie le fond de la fenêtre sur l'écran
        SDL_BlitSurface(fond,NULL,ecran,NULL);

        // On libère le fond de la fenêtre car on en a plus besoin
        SDL_FreeSurface(fond);

        // On met à jour la surface de la fenêtre
        SDL_UpdateWindowSurface(window);
    }
}