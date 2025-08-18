#include ".\..\header\installer.h"
#define MAX_SETXPATH_LENGHT 1024

void errorr(char *msg)
{
    printf("\nError code: ERRNO %d", errno);
    perror(msg);
    getchar();
    exit(EXIT_FAILURE);
}

int SETXPATH_LENGHT_GOOD(char *NewPath)
{
    return strlen("setx Path \"%%Path%%;") + strlen(NewPath) + strlen("\\bin") + strlen(getenv("Path")) < MAX_SETXPATH_LENGHT;
}

int vpath_setx(char *ProgramName, char *NewPath)
{
    printf("\nFile %s moved to %s!", ProgramName, NewPath);
    char *instruction = malloc(strlen("setx Path \"%Path%;") + 1 + strlen(NewPath) + 1 + strlen("\"") + 1);
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
        errorr("\nAn error has occurred");
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
        errorr("\n\\bin folder could not be created");
        return 0;
    } 
}

int make_program_dir(char *ProgramName, char *NewPath)
{
    int c;

    char *instruction = malloc(strlen("C:\\Program Files\\") + 1 + strlen(ProgramName) + 1);
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
        closedir(d);
        printf("\nThe folder %s already exists or is inaccessible.", ProgramName);
        printf("\nPlease check if it exists in C:\\Program Files");
        printf("\nIf so, please delete it.");
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
    {
        printf("\nYour PATH environment variable is too full to complete this operation automatically.\nPlease do this manually by adding the following to your user environment variable named PATH: C:\\Program Files\\<your_folder_name> (suggested: GestionnaireDeFichierMT)\\bin.\nIf you need help, see: https://www.malekal.com/variables-environnement-windows/#Modifier_les_variables_drsquoenvironnement ");
        getchar();
        exit(EXIT_FAILURE);
    }

    if(make_program_dir(ProgramName, NewPath))
    {
        char *Complete_NewPath = malloc(strlen(NewPath) + 1 + strlen("\\") + 1 + strlen(file_name) + 1);
        strcpy(Complete_NewPath, NewPath);
        strcat(Complete_NewPath, "\\");
        strcat(Complete_NewPath, file_name);

        int move_file = rename(ProgramPath, Complete_NewPath);
        free(Complete_NewPath);
        
        if(move_file == 0)
        {
            if(vpath_setx(ProgramName, NewPath))
                return 0;
        }
        else
        {
            errorr("\nThe file could not be moved to the new directory");
        }
    }
    else
    {
        errorr("\nAn error has occurred.\nPlease make sure the program was launched as administrator");
    }

    return 0;
}
