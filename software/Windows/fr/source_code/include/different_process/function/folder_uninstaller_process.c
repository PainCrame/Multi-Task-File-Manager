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
            tell_error(__FOLDER__OPENNING__ERROR__, NULL);
        }
        printf("\nFait !\n");
        stopRun(EXIT_SUCCESS);
}
