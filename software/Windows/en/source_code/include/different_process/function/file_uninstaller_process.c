#include ".\..\..\include.h"

void desinstall(char *file_name)
{
    // Ouvre le fichier en mode lecture pour vérifier son existence

    FILE *file = fopen(file_name,"r");

    if(file == NULL)
    {
        if(!isFolder(file_name)) //si l'ouverture du fichier échoue, vérifie d'abord si c'est parce que il est un dossier
            tell_error(__FILE__OPENNING__ERROR__, file_name);
        else{
            return;
        }
    }

    fclose(file);

    // Si le fichier existe, procède à la désinstallation

    printf(YELLOW "\nUninstalling..." RESET);

    errno = 0;

    remove(file_name);
    
    if(errno != 0)
        tell_error(__FILE__MOVE__ERROR__, file_name);

    printf(GREEN "\nSuccessful" RESET " uninstallation of" BLUE " %s "RESET"!", file_name);
}

void process_uninstall_file(void)
{

    // Demander à l'utilisateur les noms des fichiers à désinstaller
    printf("\n Enter the  name of the files to uninstall, with his "BLUE"extension"RESET" (like document"YELLOW".txt"RESET" or image"YELLOW".png"RESET") (separated by "BOLDWHITE"comas"RESET") : ");
    char instruction[255];

    fgets(instruction, sizeof(instruction) + sizeof(char), stdin);
    instruction[strcspn(instruction, "\n")] = '\0';

    if(instruction == NULL)
        tell_error(0, NULL);

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

    printf("\nDone !\n");
    stopRun(EXIT_SUCCESS);

}
