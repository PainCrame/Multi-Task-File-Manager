#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "all_function.h"
#include "file_uninstaller_process.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define BLUE    "\033[34m"      /* Blue */

void uninstall_extension(char *exe_name_path)
{
    int decision;
    char instruction[255];
    char exception[255] = "!NULL!";
    struct dirent *dir;
    int wait;

    char *exe_path_cpy = strdup(exe_name_path);
    char *actual_exe_name = get_exe_name(exe_path_cpy);
    free(exe_path_cpy);

    printf("\n Enter the name of the extension: ");
    scanf("%d", &wait);
    fgets(instruction, sizeof(instruction), stdin);

    printf("Any file exception ?"BLUE" YES (0)"RESET BLUE" or NO (1) "RESET);
    scanf("%d", &decision);

    if(decision==0){
        printf("Enter"BOLDWHITE" complete names"RESET" of files (separed by "BOLDWHITE"comas"RESET") : ");
        scanf("%d", &wait);
        // fgets(exception, sizeof(exception), stdin);
        fgets(exception, sizeof(exception), stdin);
    }
    
    instruction[strcspn(instruction, "\n")] = '\0'; //pour supprimer le caractère de fin
    exception[strcspn(exception, "\n")] = '\0';

    char **list_instruction = calloc(get_nb_element_in_string(instruction), sizeof(char)*100); //alloue ynamiquemenet un tableau 2D qui va contenir les instructions + le caractère de fin
    char **list_exception = calloc(get_nb_element_in_string(exception), sizeof(char)*100); //alloue ynamiquemenet un tableau 2D qui va contenir les exception + le caractère de fin

    strarr(list_instruction, instruction, " ,/:-_."); //remplie le tableau à partir des instructions
    strarr(list_exception, exception, " ,"); //remplie le tableau à partir des exceptions
    
    // opendir() renvoie un pointeur de type DIR. 
    DIR *d = opendir(".");
    
    readdir(d); //pour enlever le fichier "." et ".." qui corespondent aux dossiers
    readdir(d);
    
    if (d)
    {
        while ((dir = readdir(d)) != NULL )
        {
            if( (haveExtension(dir->d_name, list_instruction)==1) && (isException(dir->d_name, list_exception)==0) && (strcmp(actual_exe_name, dir->d_name)!=0) ) //si le fichier possède l'extension, n'est pas une exception, et n'est pas l'exe
            {
                desinstall(dir->d_name);
            }
        }       
        
        closedir(d);
    }

    printf("\nDone !\n");
    system("PAUSE");
    exit(0);
}
