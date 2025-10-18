#include ".\..\..\include.h"

void move(char* file_name)
{
    FILE *f;

    char *folder_name = get_extension(file_name);

    
    if(isFolder(folder_name))
    {
        if((f = fopen(file_name, "r+")) != 0)
        {
            char* new_name;
            if((new_name =  malloc( strlen(".\\") + strlen(folder_name) + strlen("\\") + strlen(file_name) + 1)) == NULL)
                tell_error(__ALLOCATION__ERROR__, NULL);
            
            strcpy(new_name, ".\\");
            strcat(new_name, folder_name);
            strcat(new_name, "\\");
            strcat(new_name, file_name);

            fclose(f);

            errno = 0;

            rename(file_name, new_name); //déplacement
            
            if(errno != 0)
                tell_error(__FILE__MOVE__ERROR__, file_name);

            return;
        }
        else
            tell_error(__FILE__OPENNING__ERROR__, file_name);

    }
    else
    {
        errno = 0;
        mkdir(folder_name);

        if(errno != 0)
            tell_error(__MAKE_FOLDER__ERROR__, folder_name);

        free(folder_name);
        move(file_name);
        return;
    }
}

void trier(void)
{
    DIR *d;
    struct dirent *dir;

    if((d = opendir(".")) == NULL)
        tell_error(__FOLDER__OPENNING__ERROR__, NULL);


    readdir(d);
    readdir(d);

    while((dir = readdir(d)) != NULL)
    {
        if(!isFolder(dir->d_name))       
            move(dir->d_name);
    }

    return;
}