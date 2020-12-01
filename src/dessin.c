#include <stdio.h>
#include <SDL.h>
#include "../include/struct.h"


Brique **creer_briques(int nbLignes, int nbColonnes){
    Brique **tabBriques = NULL;
    int x = 0, y = 0;

    tabBriques = alloc_tab_briques(nbLignes,nbColonnes);

    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
            tabBriques[i][j].x = x;
            tabBriques[i][j].y = y;
            tabBriques[i][j].taux_couleur_rouge = 255;
            tabBriques[i][j].taux_couleur_bleu = 255;
            tabBriques[i][j].taux_couleur_vert = 255;
            x += 30;
            y += 15;
        }
    }
    return tabBriques;
}

void dessin(Brique **tabBriques, int nbLignes, int nbColonnes, SDL_Renderer *renderer){
    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
            if(SDL_SetRenderDrawColor(renderer,255,255,255,1) == 0){
                SDL_Rect rect = {tabBriques[i][j].x,tabBriques[i][j].y, 25,10};
                SDL_RenderFillRect(renderer,&rect);
                SDL_RenderPresent(renderer);
            } else {
                fprintf(stderr,"Erreur changement couleur a la brique [%d] [%d] \n",i,j);
            }
        }
    }
}

