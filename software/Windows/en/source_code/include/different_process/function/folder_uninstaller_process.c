#include ".\..\..\include.h"

void clear_folder()
{
    struct dirent *dir;

    DIR *d = opendir("."); 
        if (d)
        {
            dir = readdir(d);
            dir = readdir(d);

            while ((dir = readdir(d)) != NULL)
                if(strcmp(dir->d_name, "mtfm") != 0)
                    desinstall(dir->d_name);

            closedir(d);
        }
        else{
            error(3, NULL);
        }
        printf("\nDone !\n");
        stopRun();
}
