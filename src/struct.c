//
// Created by Samuel Raoul on 17/11/2020.
//

#include "../include/struct.h"
#include <stdlib.h>

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

void free_tab_briques(Brique **tabBriques, int nbLignes){
    for(int i = 0; i < nbLignes;i++){
        free(tabBriques[i]);
    }
    free(tabBriques);
}

Raquette *alloc_raquette(){
    Raquette *raquette = NULL;

    raquette = (Raquette *)malloc(sizeof(Raquette));

    if(raquette != NULL){
        return raquette;
    } else {
        return NULL;
    }
}

void free_raquette(Raquette *raq){
    free(raq);
}

Balle *alloc_balle(){
    Balle *balle = NULL;

    balle = (Balle *)malloc(sizeof(Balle));

    if(balle != NULL){
        return balle;
    } else {
        return NULL;
    }
}

void free_balle(Balle *balle){
    free(balle);
}