#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "all_function.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define WHITE   "\033[37m"      /* White */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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

    printf(YELLOW "\nUninstalling..." RESET);

    remove(file_name);
    printf(GREEN "\nSuccessful" RESET " uninstallation of" BLUE " %s "RESET"!", file_name);
}

void process_uninstall_file(void)
{

    // Demander à l'utilisateur les noms des fichiers à désinstaller
    printf("\n Enter the  name of the files to uninstall, with his "BLUE"extension"RESET" (like document"YELLOW".txt"RESET" or image"YELLOW".png"RESET") (separated by "BOLDWHITE"comas"RESET") : ");
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

    printf("\nDone !\n");
    stopRun();

}
