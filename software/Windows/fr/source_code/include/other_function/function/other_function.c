#include ".\..\..\include.h"

void allocation_error(void)
{
    fprintf(stderr, "Erreur d'allocation de mémoire");

    exit(EXIT_FAILURE);
}


void viderBuffer(void)
{
    int c;
    while((c=getchar()) != EOF && c != '\n');

}

void stopRun(void)
{
    printf("Appuez sur ENTREE pour SORTIR");
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
        printf(RED"\nERREUR : Le fichier"RESET WHITE" %s" RESET RED " n'existe pas"RESET, file_name);
        printf(YELLOW"\nFin de la supression."RESET);
        printf("\nS'il vous pla%dt, v%drifiez si le fichier existe, ou n'est pas d%dj%d ouvert, puis r%dessayez.\n", î, é, é, à, é); 
        stopRun();
    }

    case 2:
    {
        printf( "\n"RED"ERREUR : Option invalide."RESET" S'il vous pla%dt, r%dessayez.\n", î, é);
        stopRun();
    }

    case 3:
    {
        printf(RED"ERREUR : L'ouverture du dossier est impossible"RESET);
        stopRun();
    }

    case 4:
    {
        printf(RED"ERREUR : L'ouverture du dossier est impossible"RESET);
        stopRun();
    }
    }

        

    return 1;
}