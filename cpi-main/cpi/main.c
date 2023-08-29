#include "function.h"


int main(int argc, char *argv[]){

    char * cheminDestination = cheminCourant();    // chemin dans lequelle on appelle cpi

    if (argc  == 1){
        printf("aucun parametre n'a ete fourni");
    } else if (argc > 1){
      if (strcmp(argv[1], "list") == 0 ){
            if (argc == 2){
                DIR * dossier = ouvrirDossier(cheminSource);
                listPackage(dossier);
                fermerDossier(dossier);
            } else {
                if (strcmp(argv[2], "all") == 0){
                    DIR * dossier = ouvrirDossier(cheminSource);
                    listPackage(dossier);
                    fermerDossier(dossier);
                } else {
                    printf("parametre incorrect\n");
                }
            
            }
        } else {
            printf("commande inconnue");
        }
    };
    return 0;
}
