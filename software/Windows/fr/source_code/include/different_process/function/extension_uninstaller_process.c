#include ".\..\..\include.h"

void uninstall_extension(char *exe_name_path)
{
    int decision;
    char instruction[255];
    char exception[255] = "!NULL!";
    struct dirent *dir;

    char *exe_path_cpy = strdup(exe_name_path);

    if(exe_path_cpy == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    char *actual_exe_name = get_exe_name(exe_path_cpy);
    free(exe_path_cpy);

    printf("\n Entrez le nom des extensions : ");
    fgets(instruction, sizeof(instruction), stdin);

    printf("Souhaitez vous conserver tout de m%cme queques fichiers ?"BLUE" OUI (0)"RESET BLUE" or NON (1) "RESET, ê);
    scanf("%d", &decision);
    viderBuffer();

    if(decision==0){
        printf("Entrez"BOLDWHITE" les noms complets"RESET" des fichiers (s%cpar%c par des "BOLDWHITE"virgules"RESET") : ", é, é);

        fgets(exception, sizeof(exception), stdin);
    }
    
    instruction[strcspn(instruction, "\n")] = '\0'; //pour supprimer le caractère de fin
    exception[strcspn(exception, "\n")] = '\0';

    char **list_instruction = calloc(get_nb_element_in_string(instruction), sizeof(char)*100); //alloue ynamiquemenet un tableau 2D qui va contenir les instructions + le caractère de fin
    char **list_exception = calloc(get_nb_element_in_string(exception), sizeof(char)*100); //alloue ynamiquemenet un tableau 2D qui va contenir les exception + le caractère de fin

    if((list_instruction ==NULL) || (list_exception == NULL))
        tell_error(__ALLOCATION__ERROR__, NULL);

    strarr(list_instruction, instruction, " ,/:-_."); //remplie le tableau à partir des instructions
    strarr(list_exception, exception, " ,"); //remplie le tableau à partir des exceptions
    
    // opendir() renvoie un pointeur de type DIR. 
    DIR *d;
    
    if (d == NULL)
        tell_error(__FOLDER__OPENNING__ERROR__, NULL);

    readdir(d); //pour enlever le fichier "." et ".." qui corespondent aux dossiers
    readdir(d);

    while ((dir = readdir(d)) != NULL )
    {
        if( (haveExtension(dir->d_name, list_instruction)==1) && (isException(dir->d_name, list_exception)==0) && (strcmp(actual_exe_name, dir->d_name)!=0) ) //si le fichier possède l'extension, n'est pas une exception, et n'est pas l'exe
            desinstall(dir->d_name);
    }       
    
    closedir(d);

    free(list_exception);
    free(list_instruction);

    printf("\nFait !\n");
    stopRun(EXIT_SUCCESS);
}
