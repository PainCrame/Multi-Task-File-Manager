#include "..\..\include.h"

int sub_folder = 0;

int file_already_exist(char *file_name)
{       
    FILE *f = fopen(file_name, "rb");

    if(f==NULL)
        return false;

    fclose(f);

    return true;
}

char *get_file_name(char *file_name)
{
    const char *separators = ".";

    char *file_name_copy = strdup(file_name);

    char *token = strtok(file_name_copy, separators );

    if(token == NULL)
        tell_error(0, NULL);

    char *new_name = malloc(strlen("..\\") + strlen(token) + 1);
    printf("%d", strlen("..\\"));

    if(new_name == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    strcpy(new_name, "..\\");
    strcat(new_name, token);

    return new_name;
}

char *add_letter_to_name(char *file_name)
{
    char *file_name_wtht_extension = get_file_name(file_name);
    char *new_name = malloc(strlen(file_name_wtht_extension) + strlen("a") + 1);

    if(new_name == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);
    
    strcpy(new_name, file_name_wtht_extension);
    strcat(new_name, "a");

    free(file_name_wtht_extension);

    return new_name;
}

char *get_file_name_in_back(char *file_name, char *file_name_with_letter)
{
    char *extension = get_extension(file_name);

    char *new_file_name = malloc(strlen(file_name_with_letter) +  strlen(".") + strlen(extension) + 1);
    
    if(file_name_with_letter == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);
    

    strcpy(new_file_name, file_name_with_letter);
    strcat(new_file_name, ".");
    strcat(new_file_name, extension);

    free(extension);

    return new_file_name;
}

char *change_name(char *file_name)
{
    FILE *f;

    char *temporary_new_name = add_letter_to_name(file_name);

    char *temporary_file_name = get_file_name_in_back(file_name, temporary_new_name);

    while((f = fopen(temporary_file_name, "rb")) != NULL)
    {
        temporary_new_name = realloc(temporary_new_name, strlen(temporary_new_name) + sizeof(char) + 1);

        if(temporary_new_name == NULL)
            tell_error(__ALLOCATION__ERROR__, NULL);

        strcat(temporary_new_name, "a");

        temporary_file_name = NULL;
        
        char *extension = get_extension(file_name);
        temporary_file_name = realloc(temporary_file_name, strlen(temporary_new_name) +  strlen(".") + strlen(extension) + 1);

        if(temporary_file_name == NULL)
            tell_error(__ALLOCATION__ERROR__, NULL);
        
        strcpy(temporary_file_name, temporary_new_name);
        strcat(temporary_file_name, ".");
        strcat(temporary_file_name, extension);


        free(extension);
        fclose(f);
    }

    char *new_name = malloc(strlen(temporary_new_name) + strlen(".") + strlen(get_extension(file_name) + 1));

    if(new_name == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    strcpy(new_name, temporary_new_name);
    strcat(new_name, ".");
    strcat(new_name, get_extension(file_name));

    free(temporary_file_name);
    free(temporary_new_name);

    return new_name;
}

void print_current_dir(void)
{
    char *path = malloc(1024);

    if(path == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);
    
    path = getcwd(path, 1024);

    if(path == NULL)
        tell_error(__GET__DIR__ERROR__, NULL);

    printf("\nExtraction depuis le dossier %s", path);

    free(path);
}


void move_file_back(char *file_name)
{
    errno = 0;

    char *new_name = malloc( strlen(file_name) + strlen("..\\") + 1);
    strcpy(new_name, "..\\");
    strcat(new_name, file_name);
        
    if(new_name == NULL)
        tell_error(__FILE__OPENNING__ERROR__, new_name);
        
                
    if(file_already_exist(new_name))
    {
        free(new_name);
        new_name = change_name(file_name);    
    }

    if(new_name == NULL)
        tell_error(__FILE__MOVE__ERROR__, new_name);
        
    errno = 0;
    rename(file_name, new_name);
    
    if(errno != 0)
        tell_error(__FILE__MOVE__ERROR__, new_name);

    printf("\nFichier %s "GREEN"d%cplac%c"RESET, file_name, é, é);

    free(new_name);
}

int remove_dir(char *folder)
{
    if(chdir("..\\") != 0)
        tell_error(__FOLDER__OPENNING__ERROR__, "..\\");

    return rmdir(folder);
}

void scan_folder(char *folder)
{
    DIR *d = opendir(folder);
    
    if(d==NULL)
        tell_error(__FOLDER__OPENNING__ERROR__, folder);

    closedir(d);

    if(chdir(folder) != 0)
        tell_error(__FOLDER__OPENNING__ERROR__, folder);

    extract_files(folder);
}

void extract_files(char *folder)
{
    DIR *d;
    struct dirent *dir;

    print_current_dir();

    d = opendir(".");

    dir = readdir(d);
    dir = readdir(d);

    while((dir = readdir(d)) != NULL)
    {
        if(isFolder(dir->d_name))
        {
            scan_folder(dir->d_name);
            extract_files(folder);
            return;
        }
        
        move_file_back(dir->d_name);            
    }

    closedir(d);
    
    sub_folder = 0;

    if(remove_dir(folder) == 0)
        return;

    fprintf(stderr, YELLOW"\nLe dossier %s n'a pas pu %ctre supprim%c"RESET, folder, ê, é);
    perror("ERROR ");
}

void extract_main_folder()
{
    DIR *d = opendir(".");
    struct dirent *dir;

    if(d==NULL)
        tell_error(__FOLDER__OPENNING__ERROR__, ".");

    dir = readdir(d);
    dir = readdir(d);

    while ((dir = readdir(d)) != NULL)
    {
        if(!isFolder(dir->d_name))
            continue;
            
        scan_folder(dir->d_name);
    }
}
