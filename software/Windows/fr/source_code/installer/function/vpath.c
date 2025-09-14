#include ".\..\header\installer.h"
#define MAX_SETXPATH_LENGHT 1024

void viderBuffer(void)
{
    int c;
    while((c=getchar()) != EOF && c != '\n');

}


void errorr(char *msg)
{
    fprintf(stderr, "\nCODE ERREUR : ERRNO %d", errno);
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
    printf("\nFichier %s d%cplac%c dans %s!", ProgramName, é, é, NewPath);
    char *instruction = malloc(strlen("setx Path \"%Path%;") + 1 + strlen(NewPath) + 1 + strlen("\"") + 1);
    strcpy(instruction, "setx Path \"%Path%;");
    strcat(instruction, NewPath);
    strcat(instruction, "\"");

    int c = system(instruction);
    free(instruction);

    if(c == 0)
    {
        printf("\nLe logiciel a correctement %ct%c t%cl%ccharg%c!", é, é, é, é, é);
        viderBuffer();
        return 1;
    }
    else
    {
        errorr("\nUne erreur est survenue");
        return 0;
    }
}

int make_bin_dir(char *NewPath)
{
    printf("\nCr%cation du dossier \\bin ...", é);
    strcat(NewPath, "\\bin");

    int c = mkdir(NewPath);

    if (c == 0)
    {
        printf("\nDossier \\bin correctement cr%c%c", é, é);
        return 1;
    }
    else
    {
        errorr("\nDossier \\bin ne peut pas être cree");
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
        printf("\nCr%cation du dossier programme \\%s...", é, ProgramName);

        c = mkdir(instruction);
        free(instruction);
    }
    else
    {
        closedir(d);
        printf("\nLe dossier %s existe d%cj%c ou est inaccessible.", ProgramName, é, à);
        printf("\nS'il vous pla%ct, v%crifiez s'il existe d%cj%c dans C:\\Programmes", î, é, é, à);
        printf("\nS'il existe, s'il vous pla%ct supprimez le.", î);
        getchar();
        exit(EXIT_FAILURE);
    }

    if (c == 0)
    {
        printf("\nLe dossier \\%s a été correctement cr%c%c", ProgramName, é, é);
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
        printf("\nVotre variable d'envrionnement PATH est trop charg%c pour que cette op%cration sois r%calis%c de mani%cre automatique.\nS'il vous pla%ct, r%calisez cette action de façon manuelle en ajoutant le dossier suivant %c votre variable d'environnement utilisateur nomm%c PATH. Le chemin : C:\\Program Files\\<your_folder_name> (si vous n'avez rien modifi%c c'est : GestionnaireDeFichierMT)\\bin.\nSi vous avez besoin d'aide, consultez sur google : https://www.malekal.com/variables-environnement-windows/#Modifier_les_variables_drsquoenvironnement ", é, é, é, é, è, î, é, à, é, é);
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
            errorr("\nLe fichier n'a pas pu %ctre d%cplac%c dans le dossier.");
        }
    }
    else
    {
        errorr("\nUne erreur est survenue.\nS'il vous plait, verifiez que l'installer a été lancé en tant qu'administrateur (faites CTRL+clic sur le fichier)");
    }

    return 0;
}
