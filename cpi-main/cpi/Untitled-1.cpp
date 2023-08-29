    // chemin vers le dossier pacckages, packages/
    // python-open-cv2-3


    // recuper le chemin absolue , on le stocke dans la variable path
    char buffer[1024];
    char *pathPackage = getcwd(buffer, sizeof(buffer));

    // chemin vers notre depot de packages
    char packagesDir[10] = "/packages";
    strcat(pathPackage, packagesDir);
    // dossier package
    DIR *packages;
    struct dirent *ent;
    struct stat statbuf;

    packages = opendir(pathPackage);
    if(packages == NULL){
        return 3;
    }

    while((ent = readdir(packages))!= NULL){
        stat(ent->d_name, &statbuf);
       // printf("%s \n", ent->d_name);
    }
    printf("%d \n",argc);

    if (argc > 0){
        if ( strcmp (argv[1], "install") == 0){
            char *namePackage = argv[2];
            // on doit chercher le namepackage dans le dossier packages
                 printf("installer \n");
            
            

        }
        else if( strcmp (argv[1], "uninstall")== 0){
                 printf("desinstaller \n");
        }
         else if( strcmp(argv[1],"list") ==0){
             printf("lister \n");

         }
          else if( strcmp (argv[1],"list  all") == 0){
                 printf("Tout lister \n");
          }
          else{
            printf("erreur");
          }
    }

    printf("%s", argv[0]);

    closedir(packages);


