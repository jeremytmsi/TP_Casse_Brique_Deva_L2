#include <stdio.h>

typedef struct {
    int x;
    int y;
    int visible;
} Brique;

typedef struct {
    int x;
    int y;
    int longueur;
    int largeur;
} Raquette;

typedef struct {
    int rayon;
    int x;
    int y;
} Balle;

Brique **alloc_tab_briques(int nbLignes, int nbColonnes);

void free_tab_briques(Brique **tabBriques, int nbLignes);

Raquette *alloc_raquette();