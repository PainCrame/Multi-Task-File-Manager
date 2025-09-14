#include ".\..\..\include.h"

void desinstall(char *file_name)
{
    // Ouvre le fichier en mode lecture pour vérifier son existence

    FILE *file = fopen(file_name,"r");

    if(file == NULL)
    {
        if(!isFolder(file_name)) //si l'ouverture du fichier échoue, vérifie d'abord si c'est parce que il est un dossier
            error(1, file_name);
        else{
            return;
        }
    }

    fclose(file);

    // Si le fichier existe, procède à la désinstallation

    printf(YELLOW "\nSuppression..." RESET);

    remove(file_name);
    printf(GREEN "\nSuppression" RESET " de" BLUE " %s "RESET" r%cussi !", file_name, é);
}

void process_uninstall_file(void)
{

    // Demander à l'utilisateur les noms des fichiers à désinstaller
    printf("\n Entrez le nom des fichiers %c supprimer, avec leur "BLUE"extension"RESET" (par exemple : document"YELLOW".txt"RESET" ou image"YELLOW".png"RESET") (s%cpar%c par des "BOLDWHITE"virgules"RESET") : ", à, é, é);
    char instruction[255];

    // scanf("%s", &instruction);
    fgets(instruction, sizeof(instruction) + sizeof(char), stdin);
    instruction[strcspn(instruction, "\n")] = '\0';

    if(instruction == NULL)
        error(4, NULL);

    // Initialise les delimiteurs Tokenise la chaîne d'entrée pour extraire les noms de fichiers 
    const char *s = " ,;/";
    char *token;

    token = strtok(instruction, s);

    // Tant qu'il y a des tokens, désinstalle chaque fichier
    while (token != NULL)
    {
        desinstall(token);

        token = strtok(NULL, s);
    }

    printf("\nFait !\n");
    stopRun();

}
