#include <stdio.h>
#include <SDL.h>
#include "../include/struct.h"


void creer_briques(Brique **tabBriques,int nbLignes, int nbColonnes){
    int x = 100, y = 50;

    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
            tabBriques[i][j].x = x;
            tabBriques[i][j].y = y;
            tabBriques[i][j].visible = 1;
            x += 40;
        }
        y += 15;
        x = 100;
    }
}

Raquette *creer_raquette(){
    Raquette *raq = alloc_raquette();
    raq->x = 100;
    raq->y = 300;
    raq->longueur = 100;
    raq->largeur = 10;

    return raq;
}

void capturer_event_keyboard(SDL_Event e, Raquette *raq){
    switch(e.key.keysym.sym){
        case SDLK_LEFT:
            fprintf(stdout,"Appui fleche gauche\n");
            raq->x -= 10;
            break;
        case SDLK_RIGHT:
            fprintf(stdout,"Appui fleche droite\n");
            raq->x += 10;
            break;
    }
    SDL_Delay(100);
}

void dessiner_raquette(Raquette raquette, SDL_Surface *ecran,SDL_Window *window){
    SDL_Rect raqRect;
    raqRect.x = raquette.x;
    raqRect.y = raquette.y;
    raqRect.w = raquette.longueur;
    raqRect.h = raquette.largeur;

    SDL_FillRect(ecran,&raqRect,SDL_MapRGB(ecran->format,255,255,255));
    SDL_UpdateWindowSurface(window);
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

