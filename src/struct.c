//
// Created by Samuel Raoul on 17/11/2020.
//

#include "../include/struct.h"
#include <stdlib.h>

/**
 * Permet d'allouer l'espace mémoire nécessaire pour le tableau de briques
 * @param nbLignes Le nombres de lignes à allouer
 * @param nbColonnes Le nombre de colonnes à allouer
 * @return Le tableau de briques alloué
 */
Brique **alloc_tab_briques(int nbLignes, int nbColonnes){
    Brique** tabBriques = NULL;

    tabBriques = (Brique**)malloc(nbLignes * sizeof(Brique *));

    if(tabBriques != NULL){
        for(int i = 0; i < nbLignes;i++){
            tabBriques[i] = (Brique*)malloc(nbColonnes * sizeof(Brique));
        }
    }

    return tabBriques;
}

/**
 * Permet de libérer l'espace mémoire du tableau de briques
 * @param tabBriques Le tableau de briques à libérer
 * @param nbLignes Le nombre de lignes du tableau de briques
 */
void free_tab_briques(Brique **tabBriques, int nbLignes){
    for(int i = 0; i < nbLignes;i++){
        free(tabBriques[i]);
    }
    free(tabBriques);
}

/**
 * Permet d'allouer l'espace mémoire nécessaire pour la raquette
 * @return La raquette allouée
 */
Raquette *alloc_raquette(){
    Raquette *raquette = NULL;

    raquette = (Raquette *)malloc(sizeof(Raquette));

    if(raquette != NULL){
        return raquette;
    } else {
        return NULL;
    }
}

/**
 * Permet de libérer l'espace mémoire de la raquette
 * @param raq La raquette à libérer
 */
void free_raquette(Raquette *raq){
    free(raq);
}

/**
 * Permet d'allouer l'espace mémoire nécessaire pour la balle
 * @return La ballé avec son espace allouée
 */
Balle *alloc_balle(){
    Balle *balle = NULL;

    balle = (Balle *)malloc(sizeof(Balle));

    if(balle != NULL){
        balle->x = 150;
        balle->y = 250;
        balle->longueur = 5;
        balle->largeur = 5;
        balle->dx = 1;
        balle->dy = 1;
        balle->vitesse = 0.05;
        return balle;
    } else {
        return NULL;
    }
}

/**
 * Permet de libérer l'espace mémoire de la balle
 * @param balle Balle qui doit être libérée
 */
void free_balle(Balle *balle){
    free(balle);
}

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
            if(raq->x > 0){
                raq->x -= 10;
            }
            break;
        case SDLK_RIGHT:
            if((raq->x + raq->longueur) < 640){
                raq->x += 10;
            }
            break;
    }
}