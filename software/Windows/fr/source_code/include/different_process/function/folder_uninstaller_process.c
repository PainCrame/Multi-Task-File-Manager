#include ".\..\..\include.h"
int isFileManager(char *file_name)
{
    return strcmp(file_name, "mtfm");
}

void clear_folder()
{
    struct dirent *dir;

    DIR *d = opendir("."); 
    if (d == NULL)
        tell_error(__FOLDER__OPENNING__ERROR__, NULL);
    
    dir = readdir(d);
    dir = readdir(d);

    while ((dir = readdir(d)) != NULL)
        if(isFileManager(dir->d_name) != 0)
            desinstall(dir->d_name);

    closedir(d);
    
    printf("\nFait !\n");
    stopRun(EXIT_SUCCESS);
}
