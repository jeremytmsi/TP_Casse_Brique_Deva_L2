#include <stdio.h>

typedef struct {
    int x;
    int y;
    int visible;
} Brique;

Brique **alloc_tab_briques(int nbLignes, int nbColonnes);

void free_tab_briques(Brique **tabBriques, int nbLignes);