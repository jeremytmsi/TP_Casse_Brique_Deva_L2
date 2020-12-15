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

    // On crée la fenêtre
    window = creerFenetre("Casse-brique",longueur,largeur,SDL_WINDOW_SHOWN);

    // On crée la surface de la fenêtre
    ecran = creerSurface(window);

    // Crée le fond de la fenêtre
    fond = SDL_CreateRGBSurface(0,longueur,largeur,32,0,0,0,0);

    if(fond != NULL){
        // On copie le fond de la fenêtre sur l'écran
        SDL_BlitSurface(fond,NULL,ecran,NULL);

        // On libère le fond de la fenêtre car on en a plus besoin
        SDL_FreeSurface(fond);

        // On met à jour la surface de la fenêtre
        SDL_UpdateWindowSurface(window);
    }

    // On alloue l'espace mémoire nécessaire pour le tableau de briques
    Brique **tabBriques = alloc_tab_briques(nbLignes,nbColonnes);

    // On alloue l'espace mémoire nécessaire pour la raquette
    Raquette *raquette = creer_raquette();

    Balle *balle = alloc_balle();

    // On crée les briques dans le tableau
    creer_briques(tabBriques,nbLignes,nbColonnes);

    // Boucle de jeu
    while(continuer) {
        // On remplit l'écran de noir pour actualiser le dessin
        SDL_FillRect(ecran,NULL,0x00000);

        // On attend le prochain événement
        if(SDL_PollEvent(&e)){
            // On capture l'événement au niveau du clavier pour pouvoir bouger la raquette
            capturer_event_keyboard(e, raquette);
        }

        // On dessine la raquette
        dessiner_raquette(*raquette,ecran,window);

        // On dessine les briques
        dessin(tabBriques,nbLignes,nbColonnes,ecran,window);


        // Détecte l'appui clavier sur le bouton de fermeture
        switch (e.type) {
            case SDL_QUIT:
                continuer = 0;
                free_tab_briques(tabBriques, nbLignes);
                free_raquette(raquette);
                free_balle(balle);
                close_app(window, ecran);
                break;
        }
    }
}
