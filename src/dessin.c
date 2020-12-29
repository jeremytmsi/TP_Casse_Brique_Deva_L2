#include <stdio.h>
#include <SDL.h>
#include "../include/struct.h"


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
                if(tabBriques[i][j].visible == 1){
                    SDL_Rect rect = {tabBriques[i][j].x,tabBriques[i][j].y, tabBriques[i][j].longueur, tabBriques[i][j].largeur};
                    SDL_FillRect(ecran,&rect,SDL_MapRGB(ecran->format,255,255,255));
                    SDL_UpdateWindowSurface(window);
                }
        }
    }
    SDL_Delay(20);
}

/**
 * Dessine la balle
 * @param balle Pointeur contenant l'adresse de la balle
 * @param ecran Pointeur contenant l'adresse de l'écran
 * @param window Pointeur contenant l'adresse de la fenêtre
 */
void dessin_balle(Balle balle,SDL_Surface *ecran,SDL_Window *window){
    SDL_Rect balleRect;

    balleRect.x = balle.x;
    balleRect.y = balle.y;
    balleRect.w = balle.longueur;
    balleRect.h = balle.largeur;

    SDL_FillRect(ecran,&balleRect,SDL_MapRGB(ecran->format,255,0,0));
    SDL_UpdateWindowSurface(window);
}

/**
 * Fait bouger la balle à travers l'écran
 * @param balle
 */
void moveBalle(Balle *balle){
    balle->x += balle->dx;
    balle->y -= balle->dy;
}

/**
 * Permet de détecter les collisions entre la balle et les briques
 * @param tabBriques Tableau de briques
 * @param balle Pointeur contenant l'adresse de la balle
 * @param raquette Pointeur contenant l'adresse de la raquette
 * @param nbLignes Nombre de lignes dans le tableau
 * @param nbColonnes Nombre de colonnes dans le tableau
 * @param score Pointeur contenant le score de la partie
 * @param nbVies Pointeur contenant le nombre de vies restantes de la partie
 */
void detect_collision(Brique **tabBriques,Balle *balle,Raquette raquette, Raquette *raq2,int nbLignes, int nbColonnes, int *score, int *nbVies){
    int centerPointX = (balle->x + balle->longueur);
    int posYBalle = balle->y;
    int downPointY = posYBalle + balle->largeur;
    int rightPointX = balle->x + balle->longueur;

    if(balle->x <= 0 || balle->x + balle->longueur >= 640){
        balle->dx = -balle->dx;
    }

    if(posYBalle <= 0){
        balle->dy = -balle->dy;
    }

    if((posYBalle + balle->longueur) > 480){
        fprintf(stdout,"Perte d'une vie ! \n");
        *nbVies = *nbVies - 1;
        balle->x = 150;
        balle->y = 250;
        balle->dx = 1;
        balle->dy = 1;
    }

    if(raq2 != NULL){
        if(centerPointX >= raq2->x && centerPointX <= raq2->x + raq2->longueur && downPointY >= raq2->y && downPointY <= raq2->y + raq2->largeur){
            balle->dy = -balle->dy;
        }
    }

    // Condition rebond sur la raquette
    if(centerPointX >= raquette.x && centerPointX <= raquette.x + raquette.longueur && downPointY >= raquette.y && downPointY <= raquette.y + raquette.largeur){
        balle->dy = -balle->dy;
    }

    for(int i = 0; i < nbLignes;i++){
        for(int j = 0; j < nbColonnes;j++){
            Brique *briqueCourante = *(tabBriques + i) + j;

            // Collision brique en bas
            if(balle->x > briqueCourante->x && rightPointX < (briqueCourante->x + briqueCourante->longueur + 15) && posYBalle == (briqueCourante->y + briqueCourante->largeur) && briqueCourante->visible){
                balle->dy = -balle->dy;
                balle->dx = -balle->dx;
                briqueCourante->visible = 0;

                if(balle->dx > 0){
                    balle->dx += balle->vitesse;
                } else if(balle->dx < 0){
                    balle->dx -= balle->vitesse;
                }

                *score += 1;
            }

            // Collision brique côté gauche
            if(rightPointX == briqueCourante->x && posYBalle >= briqueCourante->y && downPointY <= briqueCourante->y + briqueCourante->largeur && briqueCourante->visible){
                balle->dx = -balle->dx;
                balle->dy = -balle->dy;
                briqueCourante->visible = 0;

                if(balle->dx > 0){
                    balle->dx += balle->vitesse;
                } else if(balle->dx < 0){
                    balle->dx -= balle->vitesse;
                }

                *score += 1;
            }

            // Collision brique côté droit
            if(balle->x == briqueCourante->x && posYBalle >= briqueCourante->y && downPointY <= briqueCourante->y + briqueCourante->largeur && briqueCourante->visible){
                balle->dx = -balle->dx;
                balle->dy = -balle->dy;
                briqueCourante->visible = 0;

                if(balle->dx > 0){
                    balle->dx += balle->vitesse;
                } else if(balle->dx < 0){
                    balle->dx -= balle->vitesse;
                }

                *score += 1;
            }
        }
    }
}