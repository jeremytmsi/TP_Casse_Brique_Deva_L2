#include <stdio.h>
#include <SDL.h>
#include "../include/struct.h"


void creer_briques(Brique **tabBriques,int nbLignes, int nbColonnes){
    int x = 0, y = 0;

    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
            tabBriques[i][j].x = x;
            tabBriques[i][j].y = y;
            tabBriques[i][j].visible = 1;
            x += 30;
        }
        y += 15;
        x = 0;
    }
}

void dessin(Brique **tabBriques, int nbLignes, int nbColonnes, SDL_Renderer *renderer){
    int longueur_brique = 25, largeur_brique = 10;
    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
            if(SDL_SetRenderDrawColor(renderer,255,255,255,255) == 0){
                if(tabBriques[i][j].visible){
                    SDL_Rect rect = {tabBriques[i][j].x,tabBriques[i][j].y, longueur_brique,largeur_brique};
                    SDL_RenderFillRect(renderer,&rect);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }
}

