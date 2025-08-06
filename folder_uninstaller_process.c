#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_uninstaller_process.h"

void clear_folder(void)
{
    struct dirent *dir;

    DIR *d = opendir("."); 
        if (d)
        {
            dir = readdir(d);
            dir = readdir(d);
            while ((dir = readdir(d)) != NULL)
                if(!strcmp(dir->d_name,"auto-uninstaller.exe") != 0)
                    desinstall(dir->d_name);
            
            closedir(d);
        }
        printf("\nDone !\n");
        system("PAUSE");
        exit(1);
}