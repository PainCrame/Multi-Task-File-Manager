#include ".\..\..\include.h"

void move(char* file_name)
{
    FILE *f;
    char *folder_name = get_extension(file_name);

    
    if(isFolder(folder_name)) //si le dossier existe
    {
        if((f = fopen(file_name, "r+")) == NULL) //si le fichier s'ouvre
            tell_error(__FILE__OPENNING__ERROR__, file_name);
        
        char* new_name;
        
        if((new_name =  malloc( strlen(".\\") + strlen(folder_name) + strlen("\\") + strlen(file_name) + 1)) == NULL) //allocation
            tell_error(__ALLOCATION__ERROR__, NULL);
        
        strcpy(new_name, ".\\"); //nouveau path
        strcat(new_name, folder_name);
        strcat(new_name, "\\");
        strcat(new_name, file_name);

        fclose(f);

        errno = 0;
        rename(file_name, new_name); //déplacement
        
        if(errno == EEXIST) //si le fichier existe dans la destination
            tell_error(__FILE__MOVE__ERROR__, file_name);

        return;
        


    }

    else //sinon le créer -> récurisvité
    {
        errno = 0;
        mkdir(folder_name);

        if(errno !=0)
            tell_error(__MAKE_FOLDER__ERROR__, folder_name);
        
        free(folder_name);
        move(file_name);
        return;
    }
}

void trier(void)
{
    DIR *d;
    FILE *f;
    struct dirent *dir;

    if((d = opendir(".")) == NULL) //ouvre le dossier courrant
        tell_error(__FOLDER__OPENNING__ERROR__, NULL);
    

    readdir(d); //pour enlever les "."
    readdir(d);

    while((dir = readdir(d)) != NULL) //tant qu'on a pas lu tout le dossier
    {
        if(!isFolder(dir->d_name) && ((f = fopen(dir->d_name, "r")) != NULL)) //si l'élément n'est pas un dossier
        {
            fclose(f);
            move(dir->d_name);
        }
    }

    return;
}