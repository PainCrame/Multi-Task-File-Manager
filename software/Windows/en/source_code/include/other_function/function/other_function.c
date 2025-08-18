#include ".\..\..\include.h"

void viderBuffer(void)
{
    int c;
    while((c=getchar()) != EOF && c != '\n');

}

void stopRun(void)
{
    printf("Press Enter to EXIT");
    getchar();
    exit(0);
}

int error(int error_code, char *file_name)
{
    switch (error_code)
    {
    case 0:
        break;
    
    case 1:
    {
    // Si le fichier n'existe pas, affiche un message d'erreur et quitte
        printf(RED"\nERROR : File"RESET WHITE" %s" RESET RED " don't exist"RESET, file_name);
        printf(YELLOW"\nEnd of uninstallation."RESET);
        printf("\nPlease check the file name or if the file is not already open, and try again.\n"); 
        stopRun();
    }

    case 2:
    {
        printf( "\n"RED"ERROR : Invalid option."RESET" Please try again.\n");
        stopRun();
    }

    case 3:
    {
        printf(RED"ERROR : Failed to open the folder"RESET);
        stopRun();
    }

    case 4:
    {
        printf(RED"ERROR : Failed to open the folder"RESET);
        stopRun();
    }
    }

        

    return 1;
}