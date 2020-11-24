//
// Created by Samuel Raoul on 17/11/2020.
//

#include "../include/struct.h"


int nbLines=5;
int nbBricks=12;
int bricks[0][0];
int couleur;

// Crée un objet pour chaque brique
for (int l = 0; l < nbLines; l++) {
for (int b = 0; b < nbBricks; b++) {
    int bricks[l][b] = {x: 0, y: 0, visible: 1, couleur: null};
}
}

// Permet de dessiner les briques
typedef struct{
    // Position x de la brique
    int x=2;
    // Position y de la brique
    int y=20;
    // Couleur de la rangée de brique
    int couleur;

} brique;

// Couleur de la rangée de brique
for (int c = 0; c < nbLines; c++) {
if (c !== 0) {
x = 2;
y = y + 30;
}

// Couleur des briques
switch (c) {
case 0:
couleur = "black"
break
case 1:
couleur = "purple"
break
case 2:
couleur = "red"
break
case 3:
couleur = "orange"
break
case 4:
couleur = "yellow"
break
}

