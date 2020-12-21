#include <stdio.h>

typedef struct {
    int x;
    int y;
    int visible;
    int longueur;
    int largeur;
} Brique;

typedef struct {
    int x;
    int y;
    int longueur;
    int largeur;
} Raquette;

typedef struct {
    int longueur;
    int largeur;
    int x;
    int y;
} Balle;

Brique **alloc_tab_briques(int nbLignes, int nbColonnes);

void free_tab_briques(Brique **tabBriques, int nbLignes);

Raquette *alloc_raquette();

Balle *alloc_balle();

void free_balle(Balle *balle);