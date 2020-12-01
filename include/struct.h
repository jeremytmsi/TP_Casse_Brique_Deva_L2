#include <stdio.h>

typedef struct {
    int x;
    int y;
    int taux_couleur_rouge;
    int taux_couleur_bleu;
    int taux_couleur_vert;
    int visible;
} Brique;

Brique **alloc_tab_briques(int nbLignes, int nbColonnes);

void free_tab_briques(Brique **tabBriques,int nbLignes,int nbColonnes);