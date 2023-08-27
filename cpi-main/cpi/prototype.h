#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>



// structure packages

typedef struct package{
    char *name;         // nom de la structure
    char *path;         // adresse de la structure 
}package;



// fonction utils
int cheminCourant();

int copier(char *source, char *destination);
int recherchePackage(char *path, char *namePackage);
int supprimer(char *path, char *namePackage);




// fonction argument de ligne de commande
int install(char *path, char *namePackage);
    // prendre le dossier qui a le nom 'namepackage' le copier dans path
int uninstall(char *path, char *namePackage);
    // aller dans path/packages chercher le dossier namepackage supprime
int list(char *path);