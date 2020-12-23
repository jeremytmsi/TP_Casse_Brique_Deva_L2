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
    int longueur = 25, largeur = 10;

    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
            tabBriques[i][j].x = x;
            tabBriques[i][j].y = y;
            tabBriques[i][j].visible = 1;
            tabBriques[i][j].longueur = longueur;
            tabBriques[i][j].largeur = largeur;
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
    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
                if(tabBriques[i][j].visible){
                    SDL_Rect rect = {tabBriques[i][j].x,tabBriques[i][j].y, tabBriques[i][j].longueur, tabBriques[i][j].largeur};
                    SDL_FillRect(ecran,&rect,SDL_MapRGB(ecran->format,255,255,255));
                    SDL_UpdateWindowSurface(window);
                }
        }
    }
}

void dessin_balle(Balle balle,SDL_Surface *ecran,SDL_Window *window){
    SDL_Rect balleRect;

    balleRect.x = balle.x;
    balleRect.y = balle.y;
    balleRect.w = balle.longueur;
    balleRect.h = balle.largeur;

    SDL_FillRect(ecran,&balleRect,SDL_MapRGB(ecran->format,255,0,0));
    SDL_UpdateWindowSurface(window);
}

void moveBalle(Balle *balle){
    balle->x += balle->dx;
    balle->y -= balle->dy;
}

void detect_collision(Brique **tabBriques,Balle *balle,Raquette raquette,int nbLignes, int nbColonnes){
    int centerPointX = (balle->x + balle->longueur);
    int posYBalle = balle->y;
    int centerMiddleY = (posYBalle + balle->largeur) / 2;
    int downPointY = posYBalle + balle->largeur;
    int rightPointX = balle->x + balle->longueur;

    if(balle->x <= 0 || balle->x + balle->longueur >= 640){
        balle->dx = -balle->dx;
    }

    if(posYBalle <= 0){
        balle->dy = -balle->dy;
    }

    if(centerPointX >= raquette.x && centerPointX <= raquette.x + raquette.longueur && downPointY >= raquette.y && downPointY <= raquette.y + raquette.largeur){
        balle->dy = -balle->dy;
    }

    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
            Brique briqueCourante = tabBriques[i][j];
            Brique briqueSuivante = tabBriques[i][j+1];

            if(centerPointX > briqueCourante.x && rightPointX < briqueCourante.x + briqueCourante.longueur && briqueCourante.visible && posYBalle <= briqueCourante.y + briqueCourante.largeur){
                balle->dy = -balle->dy - balle->vitesse;
                briqueCourante.visible = 0;
            }

            if(balle->x < briqueCourante.x + briqueCourante.longueur && centerMiddleY < briqueCourante.y + briqueCourante.largeur && centerMiddleY > briqueCourante.y && briqueCourante.visible && rightPointX > briqueCourante.x + briqueCourante.longueur){
                balle->dx = -balle->dx - balle->vitesse;
                briqueCourante.visible = 0;

            }

            if(rightPointX > briqueCourante.x && centerMiddleY < briqueCourante.y + briqueCourante.largeur && centerMiddleY > briqueCourante.y && briqueCourante.visible && rightPointX < briqueCourante.x + briqueCourante.longueur){
                balle->dx = -balle->dx - balle->vitesse;
                briqueCourante.visible = 0;
            }
        }
    }
}