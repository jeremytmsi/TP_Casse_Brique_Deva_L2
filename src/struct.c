//
// Created by Samuel Raoul on 17/11/2020.
//

#include "../include/struct.h"

// Crée un objet pour chaque brique
int nbLines=5;
int nbBricks=12;
for (int l = 0; l < nbLines; l++) {
    int bricks[][];
for (int b = 0; b < nbBricks; b++) {
    int bricks[l][b] = {x: 0, y: 0, visible: true, couleur: null};
}
}

// Permet de dessiner les briques
typedef struct{
    int x=2;
    int y=20;
    int couleur;
} brique;
