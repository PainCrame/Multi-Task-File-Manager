#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_uninstaller_process.h"

void clear_folder(char *exe_name)
{
    struct dirent *dir;

    DIR *d = opendir("."); 
        if (d)
        {
            dir = readdir(d);
            dir = readdir(d);
            char *actual_exe_name = strdup(exe_name);

            while ((dir = readdir(d)) != NULL)
                if(strcmp(dir->d_name,actual_exe_name) != 0)
                    desinstall(dir->d_name);

            closedir(d);
        }
        printf("\nDone !\n");
        system("PAUSE");
        exit(1);
}