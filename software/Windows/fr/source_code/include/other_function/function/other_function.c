#include ".\..\..\include.h"

void viderBuffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

void stopRun(int code)
{
    system("PAUSE");
    exit(code);
}

int tell_error(int error_code, char *_Str)
{
    switch (error_code)
    {
        case 0:
        {
            fprintf(stderr, RED"Une erreur est survenue.\nCode erreur ERRNO : %d"RESET, errno);
            perror("\nERROR ");
            fprintf(stderr, "\nLancer le programme en tant qu'administrateur peut r%csoudre lr probl%cme.", é, è);
            log_info(__FATAL__ERROR__LOG__, "a+", 0, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        } 
        
        case __FILE__OPENNING__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : L'ouverture du fichier"RESET WHITE" %s" RESET RED " %c %cchou%c"RESET, _Str, à, é, é);
            fprintf(stderr, "\nS'il vous pla%ct, v%crifiez si le fichier existe, ou n'est pas d%cj%c ouvert, puis r%cessayez.\n", î, é, é, à, é);
            perror("\nERROR "); 
            log_info("FATAL_ERROR.log", "a+", __OPENING__ERROR__LOG__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __INVALID__OPTIONN__:
        {
            fprintf(stderr, "\n"RED"ERREUR : Option invalide."RESET" S'il vous pla%ct, r%cessayez.\n", î, é);
            perror("\nERROR "); 
            log_info(__FATAL__ERROR__LOG__, "a+", __INVALID__OPTIONN__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }


        case __FOLDER__OPENNING__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR :  L'ouverture du dossier %s est impossible"RESET, _Str);
            perror("\nERROR "); 
            log_info("FATAL_ERROR.log", "a+", __OPENING__ERROR__LOG__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __ARGUMENT__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : Arguments d'appels insufisant.\nPour plus d'aide, utiliser \"gfmt --help\""RESET);
            log_info(__FATAL__ERROR__LOG__, "a+", __ARGUMENT__ERROR__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __ALLOCATION__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : Erreur d'allocation de m%cmoire"RESET, é);
            perror("\nERROR ");
            stopRun(EXIT_FAILURE);
            log_info(__FATAL__ERROR__LOG__, "a+", __ALLOCATION__ERROR__, __FILE__, __LINE__, NULL);
            break;
        }

        case __PATH__LENGTH__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : Votre variable d'envrionnement PATH est trop charg%c pour que cette op%cration sois r%calis%c de mani%cre automatique.\nS'il vous pla%ct, r%calisez cette action de façon manuelle en ajoutant le dossier suivant %c votre variable d'environnement utilisateur nomm%c PATH. Le chemin : C:\\Program Files\\<your_folder_name> (si vous n'avez rien modifi%c c'est : GestionnaireDeFichierMT)\\bin.\nSi vous avez besoin d'aide, consultez sur google :"RESET" https://www.malekal.com/variables-environnement-windows/#Modifier_les_variables_drsquoenvironnement ", é, é, é, é, è, î, é, à, é, é);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __FILE__MOVE__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : Erreur dans le d%cplacement du fichier %s."RESET, é, _Str);
            fprintf(stderr, "\nRenommer ce fichier peut r%csoudre l'erreur.", é);
            perror("\nERROR ");
            log_info(__FATAL__ERROR__LOG__, "a+", __FILE__MOVE__ERROR__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __MAKE_FOLDER__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : La cr%cation du dossier %s a %cchou%c."RESET, é, _Str, é, é);
            perror("\nERROR ");
            log_info(__FATAL__ERROR__LOG__, "a+", __MAKE_FOLDER__ERROR__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __FILE__DELETE__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : La suppression du fichier"RESET WHITE" %s" RESET RED " %c %cchou%c"RESET, _Str, à, é, é);
            fprintf(stderr, "\nLancer le programme en tant qu'administrateur peut r%csoudre le probl%cme", é, è);
            perror("\nERROR ");
            log_info(__FATAL__ERROR__LOG__, "a+", __FILE__DELETE__ERROR__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __FOLDER__DELETE__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : La suppression du dossier"RESET WHITE" %s" RESET RED " %c %cchou%c"RESET, _Str, à, é, é);
            fprintf(stderr, "Lancer le programme en tant qu'administrateur peut r%csoudre le probl%cme", é, è);
            perror("\nERROR ");
            log_info(__FATAL__ERROR__LOG__, "a+", __FOLDER__DELETE__ERROR__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __GET__DIR__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : La lecture du chemin courant %c %cchou%c"RESET, à, é, é);
            fprintf(stderr, "\nLancer le programme en tant qu'administrateur peut r%csoudre le probl%cme", é, è);
            perror("\nERROR ");
            log_info(__FATAL__ERROR__LOG__, "a+", __GET__DIR__ERROR__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }

        case __PRIVILEGE__ERROR__:
        {
            fprintf(stderr, RED"\nERREUR : Le programme n'a pas %ct%c lanc%c en tant qu'administrateur"RESET, é, é, é);
            log_info(__FATAL__ERROR__LOG__, "a+", __PRIVILEGE__ERROR__, __FILE__, __LINE__, _Str);
            stopRun(EXIT_FAILURE);
            break;
        }
    }

    return 1;
}