#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_uninstaller_process.h"
#include "all_function.h"

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
        else{
            error(3, NULL);
        }
        printf("\nDone !\n");
        stopRun();
}
