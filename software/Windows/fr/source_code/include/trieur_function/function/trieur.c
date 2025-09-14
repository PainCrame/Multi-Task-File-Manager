#include ".\..\..\include.h"



void errorr(char *msg)
{
    printf("\nCODE ERREUR : ERRNO %d", errno);
    perror(msg);
    getchar();
    exit(EXIT_FAILURE);
}

//Conerti du texte minuscule en majuscule
char* toUperCase(char* text)
{
    char *returned_text;

    if( (returned_text = malloc(strlen(text) + 1)) == NULL )//allocation
        allocation_error();    

    for(int i = 0 ; i < strlen(text) ; i++)
    {
        int ch = text[i];
        
        if(strchr("1234567890", ch) == NULL) //si y'a pas de nombre, met en majuscule
        {
            returned_text[i] = (char)((int)text[i] + __UPER_CASE__);
            continue;
        }
        else //sinon touche pas
        {
            returned_text[i] = text[i];
        }
    }

    returned_text[strlen(text)] = '\0'; //caractère de fin

    return returned_text;
}

char* toLowerCase(char* text)
{
    char *returned_text;

    if((returned_text = malloc(strlen(text) + 1)) == NULL)
        allocation_error();


    for(int i = 0 ; i < strlen(text) ; i++)
    {
        int ch = text[i];

        if(strchr("1234567890", ch) == NULL)
        {
            returned_text[i] = (char)((int)text[i] + __LOWER_CASE__);
            continue;
        }
            returned_text[i] = (int)text[i];
    }

    returned_text[strlen(text)] = '\0';

    return returned_text;
}

char* get_folder_name(char* extension_file)
{
    char *folder_name;
    if((folder_name  = strdup( toUperCase(extension_file))) == NULL) //renvoie un nom de dossier en fonction du fichier
        allocation_error();
    
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
                allocation_error();
            
            strcpy(new_name, ".\\"); //nouveau path
            strcat(new_name, folder_name);
            strcat(new_name, "\\");
            strcat(new_name, file_name);

            fclose(f);

            int error = rename(file_name, new_name); //déplacement
            if(error != 0)
            {
                perror(" ");
                exit(EXIT_FAILURE);
            }

            return;
        }
        else
        {
            fprintf(stderr, "Erreur d'ouverture du fichier %s", file_name);
            exit(EXIT_FAILURE);
        }
    }
    else //sinon le créer -> récurisvité
    {
        mkdir(folder_name);
        free(extension);
        free(folder_name);
        move(file_name);
        return;
    }
}

void trier(void)
{
    DIR *d;
    struct dirent *dir;

    if((d = opendir(".")) == NULL) //ouvre le dossier courrant
    {
        errorr("Erreur d'ouverture du dossier courrant");
        exit(EXIT_FAILURE);
    }

    readdir(d); //pour enlever les "."
    readdir(d);

    while((dir = readdir(d)) != NULL) //tant qu'on a pas lu tout le dossier
    {
        if(!isFolder(dir->d_name)) //si l'élément n'est pas un dossier
            move(dir->d_name);
    }

    return;
}
