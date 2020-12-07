#include <stdio.h>
#include <SDL.h>
#include "../include/create_app.h"
#include "../include/render.h"
#include "../include/dessin.h"

int main(int argc, char *argv[]) {
    int continuer = 1;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event e;

    int nbLignes = 5, nbColonnes = 12;

    window = creerFenetre("Casse-brique",640,480,SDL_WINDOW_SHOWN);
    renderer = creerRendu(window);

    afficherRendu(renderer);

    char* mode = argv[1];

    Brique **tabBriques = alloc_tab_briques(nbLignes,nbColonnes);
    
    creer_briques(tabBriques,nbLignes,nbColonnes);

    while(continuer){
        dessin(tabBriques,nbLignes,nbColonnes,renderer);
        SDL_WaitEvent(&e);
        switch(e.type) {
            case SDL_QUIT:
                continuer = 0;
                free_tab_briques(tabBriques,nbLignes);
                close_app(window, renderer);
                break;
        }
        switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
                continuer = 0;
                free_tab_briques(tabBriques,nbLignes);
                close_app(window,renderer);
                break;
        }
    }

}
