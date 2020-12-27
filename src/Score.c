#include <stdio.h>
#include "../include/score.h"

/**
 * Enregistre le score à l'intérieur d'un fichier nommé score.txt
 * @param scoreAEnregistrer Le score à enregistrer
 */
void enregister_score(int scoreAEnregistrer){
    FILE *f = NULL;

    f = fopen("score.txt","w");

    if(f != NULL){
        fprintf(stdout,"Votre score : %d",scoreAEnregistrer);
        fprintf(f,"Votre score : %d",scoreAEnregistrer);
    }

    fclose(f);

}