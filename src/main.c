#include <stdio.h>
#include <SDL.h>
#include "../include/create_app.h"
#include "../include/render.h"
#include "../include/dessin.h"

int main(int argc, char *argv[]) {
    int continuer = 1;
    SDL_Window *window = NULL;
    SDL_Surface *ecran = NULL, *fond = NULL;
    SDL_Event e;

    int longueur = 640, largeur = 480;
    int nbLignes = 5, nbColonnes = 12;

    window = creerFenetre("Casse-brique",longueur,largeur,SDL_WINDOW_SHOWN);
    ecran = creerRendu(window);

    fond = SDL_CreateRGBSurface(0,longueur,largeur,32,0,0,0,0);

    if(fond != NULL){
        SDL_BlitSurface(fond,NULL,ecran,NULL);
        SDL_FreeSurface(fond);
        SDL_UpdateWindowSurface(window);
    }


    Brique **tabBriques = alloc_tab_briques(nbLignes,nbColonnes);

    Raquette *raquette = creer_raquette();

    creer_briques(tabBriques,nbLignes,nbColonnes);
    while(continuer) {
        //dessin(tabBriques, nbLignes, nbColonnes, renderer);
        SDL_PollEvent(&e);
        capturer_event_keyboard(e, raquette);
        dessiner_raquette(*raquette,ecran,window);
        dessin(tabBriques,nbLignes,nbColonnes,ecran,window);



        // Détecte l'appui clavier sur le bouton de fermeture
        switch (e.type) {
            case SDL_QUIT:
                continuer = 0;
                free_tab_briques(tabBriques, nbLignes);
                close_app(window, ecran);
                break;
        }
        switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
                continuer = 0;
                free_tab_briques(tabBriques, nbLignes);
                close_app(window, ecran);
                break;
        }
    }

}
