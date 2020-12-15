#include <stdio.h>
#include <SDL.h>
#include "../include/struct.h"

/**
 * Permet de créer les briques dans le tableau
 * @param tabBriques Le tableau de briques à remplir
 * @param nbLignes Le nombre de lignes qu'on veut dans notre jeu
 * @param nbColonnes Le nombre de colonnes qu'on veut dans notre jeu
 */
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

/**
 * Permet de créer la raquette
 * @return raq La raquette créée
 */
Raquette *creer_raquette(){
    Raquette *raq = alloc_raquette();
    raq->x = 100;
    raq->y = 300;
    raq->longueur = 100;
    raq->largeur = 10;

    return raq;
}

/**
 * Permet de faire bouger la raquette selon la touche appuyée sur le clavier
 * @param e La liste des événements
 * @param raq La raquette à faire bouger
 */
void capturer_event_keyboard(SDL_Event e, Raquette *raq){
    switch(e.key.keysym.sym){
        case SDLK_LEFT:
            raq->x -= 10;
            break;
        case SDLK_RIGHT:
            raq->x += 10;
            break;
    }
    SDL_Delay(100);
}

/**
 * Permet de dessiner la raquette
 * @param raquette La raquette à dessiner
 * @param ecran La surface de l'écran sur laquelle dessiner
 * @param window La fenêtre de l'application
 */
void dessiner_raquette(Raquette raquette, SDL_Surface *ecran,SDL_Window *window){
    SDL_Rect raqRect;

    raqRect.x = raquette.x;
    raqRect.y = raquette.y;
    raqRect.w = raquette.longueur;
    raqRect.h = raquette.largeur;

    SDL_FillRect(ecran,&raqRect,SDL_MapRGB(ecran->format,255,255,255));
    SDL_UpdateWindowSurface(window);
}

/**
 * Permet de dessiner les briques
 * @param tabBriques Le tableau de briques à dessiner
 * @param nbLignes Le nombre de lignes à dessiner
 * @param nbColonnes Le nombre de colonnes à dessiner
 * @param ecran La surface de l'écran à dessiner
 * @param window La fenêtre de l'application
 */
void dessin(Brique **tabBriques, int nbLignes, int nbColonnes, SDL_Surface *ecran, SDL_Window *window){
    int longueur_brique = 25, largeur_brique = 10;
    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
                if(tabBriques[i][j].visible){
                    SDL_Rect rect = {tabBriques[i][j].x,tabBriques[i][j].y, longueur_brique,largeur_brique};
                    SDL_FillRect(ecran,&rect,SDL_MapRGB(ecran->format,255,255,255));
                    SDL_UpdateWindowSurface(window);
                }
        }
    }
}

