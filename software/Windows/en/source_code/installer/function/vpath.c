#include ".\..\header\installer.h"
#define MAX_SETXPATH_LENGHT 1024

int SETXPATH_LENGHT_GOOD(char *NewPath)
{
    return strlen("setx Path \"%%Path%%;") + strlen(NewPath) + strlen("\\bin") + strlen(getenv("Path")) < MAX_SETXPATH_LENGHT;
}

int vpath_setx(char *ProgramName, char *NewPath)
{
    printf("\nFile %s moved to %s!", ProgramName, NewPath);
    char *instruction = malloc(strlen("setx Path \"%Path%;") + 1 + strlen(NewPath) + 1 + strlen("\"") + 1);
    
    if(instruction == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);
    
    strcpy(instruction, "setx Path \"%Path%;");
    strcat(instruction, NewPath);
    strcat(instruction, "\"");

    int c = system(instruction);
    free(instruction);

    if(c == 0)
    {
        printf("\nThe software was successfully downloaded!");
        viderBuffer();
        return 1;
    }
    else
    {
        tell_error(0, NULL);
        return 0;
    }
}

int make_bin_dir(char *NewPath)
{
    printf("\nCreating \\bin folder...");
    strcat(NewPath, "\\bin");

    int c = mkdir(NewPath);

    if (c == 0)
    {
        printf("\n\\bin folder successfully created");
        return 1;
    }
    else
    {
        tell_error(0, NULL);
        return 0;
    } 
}

int make_program_dir(char *ProgramName, char *NewPath)
{
    int c;

    char *instruction = malloc(strlen("C:\\Program Files\\") + 1 + strlen(ProgramName) + 1);
    
    if(instruction == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);
    
    strcpy(instruction, "C:\\Program Files\\");
    strcat(instruction, ProgramName);

    DIR *d = opendir(NewPath);

    if (!d)
    {
        printf("\nCreating program folder \\%s...", ProgramName);

        c = mkdir(instruction);
        free(instruction);
    }
    else
    {
        fprintf(stderr, "\nThe %s folder already exist or is inaccessible.", ProgramName, é, à);
        fprintf(stderr, "\nCheck whether it exists in the folder C:\\Programs");
        fprintf(stderr, "\nif it exists, please delete it.");
        getchar();
        exit(EXIT_FAILURE);
    }

    if (c == 0)
    {
        printf("\n\\%s folder successfully created", ProgramName);
        return make_bin_dir(NewPath);
    }
    else
    {
        return 0;
    }
}

int move_in_VPATH(char *ProgramName, char *ProgramPath, char *file_name)
{
    char *NewPath = malloc(strlen("C:\\Program Files\\") + 1 + strlen(ProgramName) + 1 + strlen("\\bin") + 1);
    strcpy(NewPath, "C:\\Program Files\\");
    strcat(NewPath, ProgramName);
    
    if(!SETXPATH_LENGHT_GOOD(NewPath))
        tell_error(__PATH__LENGTH__ERROR__, NULL);


    if(make_program_dir(ProgramName, NewPath))
    {
        char *Complete_NewPath = malloc(strlen(NewPath) + 1 + strlen("\\") + 1 + strlen(file_name) + 1);
        
        if(Complete_NewPath == NULL)
            tell_error(__ALLOCATION__ERROR__, NULL);
        
        strcpy(Complete_NewPath, NewPath);
        strcat(Complete_NewPath, "\\");
        strcat(Complete_NewPath, file_name);

        errno = 0;

        int move_file = rename(ProgramPath, Complete_NewPath);
        
        if(errno == EEXIST)
            tell_error(__FILE__MOVE__ERROR__, ProgramPath);
        
        free(Complete_NewPath);

        if(move_file == 0)
        {
            if(vpath_setx(ProgramName, NewPath))
                return 0;
        }
        else
            tell_error(0, NULL);
    }
    else
        tell_error(0, NULL);


    return 0;
}