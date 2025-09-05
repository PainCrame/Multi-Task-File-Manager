#include ".\..\header\installer.h"
#define MAX_SETXPATH_LENGHT 1024

void errorr(char *msg)
{
    printf("\nCODE ERREUR : ERRNO %d", errno);
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
    printf("\nFichier %s d%dplac%d dans %s!", ProgramName, é, é, NewPath);
    char *instruction = malloc(strlen("setx Path \"%Path%;") + 1 + strlen(NewPath) + 1 + strlen("\"") + 1);
    strcpy(instruction, "setx Path \"%Path%;");
    strcat(instruction, NewPath);
    strcat(instruction, "\"");

    int c = system(instruction);
    free(instruction);

    if(c == 0)
    {
        printf("\nLe logiciel a correctement %dt%d t%dl%dcharg%d!", é, é, é, é, é);
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
    printf("\nCr%dation du dossier \\bin ...", é);
    strcat(NewPath, "\\bin");

    int c = mkdir(NewPath);

    if (c == 0)
    {
        printf("\nDossier \\bin correctement cr%d%d", é, é);
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
        printf("\nCr%dation du dossier programme \\%s...", é, ProgramName);

        c = mkdir(instruction);
        free(instruction);
    }
    else
    {
        closedir(d);
        printf("\nLe dossier %s existe d%dj%d ou est inaccessible.", ProgramName, é, à);
        printf("\nS'il vous pla%dt, v%drifiez s'il existe d%dj%d dans C:\\Programmes", î, é, é, à);
        printf("\nS'il existe, s'il vous pla%dt supprimez le.", î);
        getchar();
        exit(EXIT_FAILURE);
    }

    if (c == 0)
    {
        printf("\nLe dossier \\%s a été correctement cr%d%d", ProgramName, é, é);
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
        printf("\nVotre variable d'envrionnement PATH est trop charg%d pour que cette op%dration sois r%dalis%d de mani%dre automatique.\nS'il vous pla%dt, r%dalisez cette action de façon manuelle en ajoutant le dossier suivant %d votre variable d'environnement utilisateur nomm%d PATH. Le chemin : C:\\Program Files\\<your_folder_name> (si vous n'avez rien modifi%d c'est : GestionnaireDeFichierMT)\\bin.\nSi vous avez besoin d'aide, consultez sur google : https://www.malekal.com/variables-environnement-windows/#Modifier_les_variables_drsquoenvironnement ", é, é, é, é, è, î, é, à, é, é);
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
            errorr("\nLe fichier n'a pas pu %dtre d%dplac%d dans le dossier.");
        }
    }
    else
    {
        errorr("\nUne erreur est survenue.\nS'il vous plait, verifiez que l'installer a été lancé en tant qu'administrateur (faites CTRL+clic sur le fichier)");
    }

    return 0;
}
