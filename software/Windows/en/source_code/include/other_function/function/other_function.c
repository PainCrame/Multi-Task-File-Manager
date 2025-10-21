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
            fprintf(stderr, "\nERROR : The folder %s already exists or is inaccessible.", _Str);
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
            fprintf(stderr, RED"\nERROR : Failed to open the folder %s"RESET, _Str);
            perror("ERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __ARGUMENT__ERROR__:
        {
            fprintf(stderr, "\nERROR : Insufficient call arguments.\nFor more help, use \"mtfm --help\"");
            stopRun(EXIT_FAILURE);
        }

        case __ALLOCATION__ERROR__:
        {
            fprintf(stderr, "\nERROR : Memory allocation error");
            perror("ERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __PATH__LENGTH__ERROR__:
        {
            fprintf(stderr, "\nERROR : Your PATH environment variable is too full to complete this operation automatically.\nPlease do this manually by adding the following to your user environment variable named PATH: C:\\Program Files\\<your_folder_name> (suggested: GestionnaireDeFichierMT)\\bin.\nIf you need help, see: https://www.malekal.com/variables-environnement-windows/#Modifier_les_variables_drsquoenvironnement ");
            stopRun(EXIT_FAILURE);
        }

        case __FILE__MOVE__ERROR__:
        {
            fprintf(stderr, "\nERROR : Error moving %s file.", _Str);
            fprintf(stderr, "\nRename the file, or launch the program as administrator, can resolve the problem.");
            perror("\nERROR "); 
            stopRun(EXIT_FAILURE);
        }

        case __MAKE_FOLDER__ERROR__:
        {
            fprintf(stderr, "\nFailed to create the folder");
            perror("\nERROR ");
            stopRun(EXIT_FAILURE);
        }

        case __FILE__DELETE__ERROR__:
        {
            fprintf(stderr, RED"\nERROR: Deletion of %s file failed.", _Str);
        }

    }

    return 1;
}