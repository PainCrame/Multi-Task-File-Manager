#include ".\..\..\include.h"

void errorr(char *msg)
{
    printf("\nCODE ERREUR : ERRNO %d", errno);
    perror(msg);
    getchar();
    exit(EXIT_FAILURE);
}

char* toUperCase(char* text)
{
    char *returned_text;

    if( (returned_text = malloc(strlen(text) + 1)) == NULL )
        allocation_error();    

    for(int i = 0 ; i < strlen(text) ; i++)
    {
        int ch = text[i];
        
        if(strchr("1234567890", ch) == NULL)
        {
            returned_text[i] = (char)((int)text[i] - 32);
            continue;
        }
        else
        {
            returned_text[i] = text[i];
        }
    }

    printf("\n%s", returned_text);

    returned_text[strlen(text)] = '\0';

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
            returned_text[i] = (char)((int)text[i] + 32);
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
    if((folder_name  = strdup( toUperCase(extension_file))) == NULL)
        allocation_error();
    
    return folder_name;
    
}

void move(char* file_name)
{
    FILE *f;
    char *extension = get_extension(file_name);
    char *folder_name = get_folder_name(extension);

    
    if(isFolder(folder_name))
    {
        if((f = fopen(file_name, "r+")) != 0)
        {
            char* new_name;
            if((new_name =  malloc( strlen(".\\") + strlen(folder_name) + strlen("\\") + strlen(file_name) + 1)) == NULL)
                allocation_error();
            
            strcpy(new_name, ".\\");
            strcat(new_name, folder_name);
            strcat(new_name, "\\");
            strcat(new_name, file_name);

            fclose(f);
            int c = rename(file_name, new_name);
            if(c != 0)
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
    else
    {
        mkdir(folder_name);
        free(extension);
        free(folder_name);
        move(file_name);
        printf("%s", file_name);
        return;
    }
}

void trier(void)
{
    DIR *d;
    struct dirent *dir;

    if((d = opendir(".")) == NULL)
    {
        errorr("Erreur d'ouverture du dossier courrant");
        exit(EXIT_FAILURE);
    }

    readdir(d);
    readdir(d);

    while((dir = readdir(d)) != NULL)
    {
        if(!isFolder(dir->d_name))       
            move(dir->d_name);
    }

    return;
}

int main(void)
{
    chdir("C:\\Users\\Hugo C\\Downloads");

    trier();

    return 0;
}