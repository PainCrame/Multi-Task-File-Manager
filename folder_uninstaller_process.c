#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_uninstaller_process.h"

#if  _WIN32 
    #define get_exe_name get_exe_name_antislash
#elif defined __linux__ || defined __APPLE__
    #define get_exe_name get_exe_name_slash
#endif
    
char *get_exe_name_antislash(char *path)
{
    char *token;
    char *token_save;
    char *separator = "\\";

    token = strtok(path, separator);

    while(token != NULL)
    {
        token_save = token;
        token = strtok(NULL, separator);
    }

    char *exe_name = strdup(token_save);
    return exe_name;
}

char *get_exe_name_slash(char *path)
{
    char *token;
    char *token_save;
    char *separator = "/";

    token = strtok(path, separator);

    while(token != NULL)
    {
        token_save = token;
        token = strtok(NULL, separator);
    }

    char *exe_name = strdup(token_save);
    return exe_name;
}

void clear_folder(char *exe_path)
{
    struct dirent *dir;

    DIR *d = opendir("."); 
        if (d)
        {
            dir = readdir(d);
            dir = readdir(d);

            char *exe_path_cpy = strdup(exe_path);
            char *actual_exe_name = get_exe_name(exe_path_cpy);
            free(exe_path_cpy);

            while ((dir = readdir(d)) != NULL)
                if(strcmp(dir->d_name,actual_exe_name) != 0)
                    desinstall(dir->d_name);

            closedir(d);
        }
        printf("\nDone !\n");
        system("PAUSE");
        exit(1);
}
