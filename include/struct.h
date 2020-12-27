#include <stdio.h>
#include <SDL.h>

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
    double dx;
    double dy;
} Balle;

Brique **alloc_tab_briques(int nbLignes, int nbColonnes);
void free_tab_briques(Brique **tabBriques, int nbLignes);
Raquette *alloc_raquette();
Balle *alloc_balle();
void free_balle(Balle *balle);
void free_raquette(Raquette *raq);
Raquette *creer_raquette();
void creer_briques(Brique **tabBriques,int nbLignes, int nbColonnes);
void capturer_event_keyboard(SDL_Event e, Raquette *raq);