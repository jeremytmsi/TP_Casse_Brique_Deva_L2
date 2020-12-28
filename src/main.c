#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include "../include/create_app.h"
#include "../include/render.h"
#include "../include/dessin.h"
#include "../include/score.h"

int main(int argc, char *argv[]) {
    int continuer = 1;
    SDL_Window *window = NULL;
    SDL_Surface *ecran = NULL, *fond = NULL;
    SDL_Event e;

    int longueur = 640, largeur = 480;
    int nbLignes = 5, nbColonnes = 12;
    int score = 0;
    int nbVies = 3;

    int x = 100, y = 50;

    char* mode = argv[1];

    // On crée la fenêtre
    window = creerFenetre("Casse-brique",longueur,largeur,SDL_WINDOW_SHOWN);

    // On crée la surface de la fenêtre
    ecran = creerSurface(window);

    // Crée le fond de la fenêtre
    fond = SDL_CreateRGBSurface(0,longueur,largeur,32,0,0,0,0);

    if(fond != NULL){
        // On copie le fond de la fenêtre sur l'écran
        SDL_BlitSurface(fond,NULL,ecran,NULL);

        // On libère le fond de la fenêtre car on en a plus besoin
        SDL_FreeSurface(fond);

        // On met à jour la surface de la fenêtre
        SDL_UpdateWindowSurface(window);
    }

    // On alloue l'espace mémoire nécessaire pour le tableau de briques
    Brique **tabBriques = alloc_tab_briques(nbLignes,nbColonnes);

    // On alloue l'espace mémoire nécessaire pour la raquette
    Raquette *raquette = creer_raquette(100,300);
    Raquette *raq2 = NULL;

    if(strcmp(mode,"duo") == 0){
        raq2 = creer_raquette(250,300);
    }

    Balle *balle = alloc_balle();

    // On crée les briques dans le tableau
    creer_briques(tabBriques,nbLignes,nbColonnes,x,y);

    // Boucle de jeu
    while(continuer) {
        // Nombre de briques détruites
        int briquesDetruites = 0;
        // On attend le prochain événement
        if(SDL_PollEvent(&e)){
            // On capture l'événement au niveau du clavier pour pouvoir bouger la raquette
            capturer_event_keyboard(e, raquette,raq2);
        }

        // Dessine du noir afin de rafraîchir l'écran
        SDL_FillRect(ecran,NULL,0x00000);

        // Dessine la balle sur l'écran
        dessin_balle(*balle,ecran,window);

        // On dessine la raquette
        if(strcmp(mode,"solo") == 0){
            dessiner_raquette(*raquette,ecran,window);
        } else if(strcmp(mode,"duo") == 0){
            dessiner_raquette(*raquette,ecran,window);
            dessiner_raquette(*raq2,ecran,window);
        }

        // On dessine les briques
        dessin(tabBriques,nbLignes,nbColonnes,ecran,window);

        // Détecte les collisions entre la balle, les briques et les bordures de la fenêtre
        detect_collision(tabBriques,balle,*raquette,raq2,nbLignes,nbColonnes,&score,&nbVies);

        for(int i = 0; i < nbLignes;i++){
            for(int j = 0; j < nbColonnes;j++){
                if(tabBriques[i][j].visible == 0){
                    briquesDetruites += 1;
                }
            }
        }

        // Redessine des briques mais avec une hauteur moins importante
        if(briquesDetruites == (nbLignes * nbColonnes)){
            y += 20;
            creer_briques(tabBriques,nbLignes,nbColonnes,x,y);
        }

        // Si le joueur n'a pas perdu toutes ses vies
        if(nbVies > 0){
            moveBalle(balle);
            fprintf(stdout,"Score : %d \n",score);
            fprintf(stdout,"Nombre de vies : %d \n",nbVies);
        }


        // Actions de fin de partie
        if(nbVies == 0){
            enregister_score(score);
            fprintf(stdout,"Votre score a bien ete enregistre !");
            nbVies = -1;
        }

        // Détecte l'appui clavier sur le bouton de fermeture
        switch (e.type) {
            case SDL_QUIT:
                continuer = 0;
                free_tab_briques(tabBriques, nbLignes);
                free_raquette(raquette);
                free_balle(balle);
                close_app(window, ecran);
                break;
        }
    }
}
