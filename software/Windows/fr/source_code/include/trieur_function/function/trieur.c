#include ".\..\..\include.h"

char* get_folder_name(char* extension_file)
{
    char *folder_name;
    if((folder_name  = strdup( toUperCase(extension_file))) == NULL) //renvoie un nom de dossier en fonction du fichier
        tell_error(__ALLOCATION__ERROR__, NULL);
    
    return folder_name;
    
}

void move(char* file_name)
{
    FILE *f;
    char *extension = get_extension(file_name);
    char *folder_name = get_folder_name(extension);

    
    if(isFolder(folder_name)) //si le dossier existe
    {
        if((f = fopen(file_name, "r+")) != 0) //si le fichier s'ouvre
        {
            char* new_name;
            if((new_name =  malloc( strlen(".\\") + strlen(folder_name) + strlen("\\") + strlen(file_name) + 1)) == NULL) //allocation
                tell_error(__ALLOCATION__ERROR__, NULL);
            
            strcpy(new_name, ".\\"); //nouveau path
            strcat(new_name, folder_name);
            strcat(new_name, "\\");
            strcat(new_name, file_name);

            fclose(f);

            int error = rename(file_name, new_name); //déplacement
            if(error != 0)
                tell_error(0, NULL);

            return;
        }
        else
            tell_error(__FILE__OPENNING__ERROR__, file_name);

    }

    else //sinon le créer -> récurisvité
    {
        errno = 0;
        mkdir(folder_name);

        if(errno !=0)
            tell_error(0, NULL);
        
        free(extension);
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
        errno = 0;

        if(!isFolder(dir->d_name) && ((f = fopen(dir->d_name, "r")) != NULL)) //si l'élément n'est pas un dossier
            move(dir->d_name);

        if(errno == EEXIST) //si le fichier existe dans la destination
            tell_error(__FILE__MOVE__ERROR__, dir->d_name);
    }

    return;
}