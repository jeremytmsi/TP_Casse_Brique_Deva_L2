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
        balle->longueur = 10;
        balle->largeur = 10;
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