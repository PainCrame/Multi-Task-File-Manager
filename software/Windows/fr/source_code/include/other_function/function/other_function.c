#include ".\..\..\include.h"

void viderBuffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

void stopRun(int code)
{
    printf("Appuyez sur ENTREE pour SORTIR");
    getchar();
    exit(code);
}

int tell_error(int error_code, char *_Str)
{
    switch (error_code)
    {
        case 0:
        {
            fprintf(stderr, "Une erreur est survenue.\nCode erreur ERRNO : %d", errno);
            perror("\nERROR ");
            fprintf(stderr, "\nLancer le programme en tant qu'administrateur peut r%csoudre lr probl%cme.", é, è);
            stopRun(EXIT_FAILURE);
        } 
        
        case __FILE__OPENNING__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : L'ouverture du fichier"RESET WHITE" %s" RESET RED " à échoué"RESET, _Str);
            fprintf(stderr, YELLOW"\nFin de la supression."RESET);
            fprintf(stderr, "\nS'il vous pla%ct, v%crifiez si le fichier existe, ou n'est pas d%cj%c ouvert, puis r%cessayez.\n", î, é, é, à, é);
            perror("\nERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __INVALID__OPTIONN__:
        {
            fprintf(stderr, "\n"RED"ERREUR : Option invalide."RESET" S'il vous pla%ct, r%cessayez.\n", î, é);
            perror("\nERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __FOLDER__OPENNING__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR :  L'ouverture du dossier est impossible"RESET);
            perror("\nERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __ARGUMENT__ERROR__:
        {
            fprintf(stderr, "\nERREUR : Arguments d'appels insufisant.\nPour plus d'aide, utiliser \"gfmt --help\"");
            stopRun(EXIT_FAILURE);
        }

        case __ALLOCATION__ERROR__:
        {
            fprintf(stderr, "\nERREUR : Erreur d'allocation de m%cmoire", é);
            perror("\nERROR ");
            stopRun(EXIT_FAILURE);
        }

        case __PATH__LENGTH__ERROR__:
        {
            fprintf(stderr, "\nERREUR : Votre variable d'envrionnement PATH est trop charg%c pour que cette op%cration sois r%calis%c de mani%cre automatique.\nS'il vous pla%ct, r%calisez cette action de façon manuelle en ajoutant le dossier suivant %c votre variable d'environnement utilisateur nomm%c PATH. Le chemin : C:\\Program Files\\<your_folder_name> (si vous n'avez rien modifi%c c'est : GestionnaireDeFichierMT)\\bin.\nSi vous avez besoin d'aide, consultez sur google : https://www.malekal.com/variables-environnement-windows/#Modifier_les_variables_drsquoenvironnement ", é, é, é, é, è, î, é, à, é, é);
            stopRun(EXIT_FAILURE);
        }

        case __FILE__MOVE__ERROR__:
        {
            fprintf(stderr, "\nERREUR : Erreur dans le d%cplacement du fichier %s.", é, _Str);
            fprintf(stderr, "\nRenommer ce fichier peut r%csoudre l'erreur.", é);
            perror("\nERROR "); 
            stopRun(EXIT_FAILURE);
        }

    }

    return 1;
}