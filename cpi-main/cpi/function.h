#include "prototype.h"

char * cheminCourant(){
    // recuper le chemin absolue , on le stocke dans la variable path
    char buffer[10024];
    char *path = getcwd(buffer, sizeof(buffer));
    return path;
}




DIR * ouvrirDossier(char * chemin){
    // ouvrir le dossier
    DIR *dossier = opendir(chemin);
    if (dossier == NULL){
        printf("Erreur lors de l'ouverture du dossier : ouverture\n");
        exit(1);
    }
    return dossier;
}


int fermerDossier(DIR * dossier){
    // fermer le dossier
    int fermer = closedir(dossier);
    if (fermer == -1){
        printf("Erreur lors de la fermeture du dossier\n");
        exit(1);
    }
    return fermer;
}

int checkDossier(char *path, char *namePackage){
    // verifier si le package existe
    DIR *dossier = ouvrirDossier(path);
    struct dirent *lecture;
    int check = 0;
    while ((lecture = readdir(dossier))) {
        if (strcmp(lecture->d_name, namePackage) == 0){
            check = 1;
        }
    }
    fermerDossier(dossier);
    return check;
}



void listPackage(DIR * dossier){
    // afficher le contenu du dossier
    struct dirent *lecture;


    printf("Liste des packages disponibles :\n");
    while ((lecture = readdir(dossier))) {

        if (strlen(lecture->d_name) > 2){
            printf("%s\n", lecture->d_name);
        }
    }
}

int copierDossier(const char * package,const char * destination){


    // Ouvrir le dossier source
    DIR *source_directory = opendir(package);
    if (source_directory == NULL) {
        printf("Le dossier source n'existe pas.\n");
        return 1;
    }

    // Créer le dossier de destination
    mkdir(destination);

    // Parcourir les fichiers du dossier source
    struct dirent *entry;
    while ((entry = readdir(source_directory)) != NULL) {
        // Sauter les répertoires
        if (entry->d_type == DT_DIR) {
        // Copier le répertoire récursivement
        
        copierDossier(package + "/" + entry->d_name, package + "/" + entry->d_name);
        continue;
        }

        // Obtenir le nom du fichier
        char *file_name = entry->d_name;

        // Copier le fichier
        int success = copy(package + "/" + file_name, destination + "/" + file_name);
        if (success == -1) {
        printf("Erreur lors de la copie du fichier %s.\n", file_name);
        return 1;
        }
    }

    // Fermer le dossier source
    closedir(source_directory);

    return 0;
}



int creerDossier(char * chemin){
    // creer un dossier
    int creer = mkdir(chemin);
    if (creer == -1){
        printf("Erreur lors de la creation du dossier\n");
        exit(1);
    }
    return creer;
}

void install(char *path, char *namePackage){

}