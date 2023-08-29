#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>



// chemin absolut d'installation du programme
char * cheminSource = "C:/Users/Tshek/Documents/cours c/cpi-main/cpi/packages";




// structure packages

typedef struct package{
    char *name;         // nom de la structure
    char *path;         // adresse de la structure 
}package;


// fonction utils
char * cheminCourant();      // le dossier depuis lequel on appelle cpi 



DIR * ouvrirDossier(char * chemin);     // ouvrir un dossier
int fermerDossier(DIR * chemin);        // fermer un dossier
int copier(char *source, char *destination);
int recherchePackage(char *path, char *namePackage);
int supprimer(char *path, char *namePackage);
int checkDossier(char *path, char *namePackage);        // verifier l'existence d'un package dans le depot
int creerDossier(char * chemin);
int copierDossier(DIR * package, char * destination);


// fonction argument de ligne de commande
void install(char *path, char *namePackage);
    // prendre le dossier qui a le nom 'namepackage' le copier dans path
void uninstall(char *path, char *namePackage);
    // aller dans path/packages chercher le dossier namepackage supprime
void listPackage(DIR * dossier);







