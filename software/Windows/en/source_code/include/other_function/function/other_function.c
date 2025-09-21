#include ".\..\..\include.h"

void viderBuffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

void stopRun(int code)
{
    printf("Press Enter to EXIT");
    getchar();
    exit(code);
}

int tell_error(int error_code, char *_Str)
{
    switch (error_code)
    {
        case 0:
        {
            fprintf(stderr, RED"\nERROR : File"RESET WHITE" %s" RESET RED " don't exist"RESET, _Str);
            fprintf(stderr, YELLOW"\nEnd of uninstallation."RESET);
            fprintf(stderr, "\nPlease check the file name or if the file is not already open, and try again.\n"); 
            stopRun(EXIT_FAILURE);
        } 
        
        case __FILE__OPENNING__ERROR__:
        {
            fprintf(stderr, "\nThe folder %s already exists or is inaccessible.", _Str);
            fprintf(stderr, "\nPlease check if it exists in C:\\Program Files");
            fprintf(stderr, "\nIf so, please delete it.");
            perror("ERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __INVALID__OPTIONN__:
        {
            fprintf(stderr, "\n"RED"ERROR : Invalid option."RESET" Please try again.\n");
            perror("ERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __FOLDER__OPENNING__ERROR__:
        {
            fprintf(stderr, RED"ERROR : Failed to open the folder"RESET);
            perror("ERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __ARGUMENT__ERROR__:
        {
            fprintf(stderr, "\nInsufficient call arguments.\nFor more help, use \"gfmt --help\"");
            perror("ERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __ALLOCATION__ERROR__:
        {
            fprintf(stderr, "Allocation error");
            perror("ERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __PATH__LENGTH__ERROR__:
        {
            fprintf(stderr, "\nYour PATH environment variable is too full to complete this operation automatically.\nPlease do this manually by adding the following to your user environment variable named PATH: C:\\Program Files\\<your_folder_name> (suggested: GestionnaireDeFichierMT)\\bin.\nIf you need help, see: https://www.malekal.com/variables-environnement-windows/#Modifier_les_variables_drsquoenvironnement ");
            stopRun(EXIT_FAILURE);
        }

    }

    return 1;
}