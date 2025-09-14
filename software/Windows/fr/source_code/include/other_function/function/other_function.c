#include ".\..\..\include.h"

void allocation_error(void)
{
    fprintf(stderr, "Erreur d'allocation de m%cmoire", é);

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
        fprintf(stderr, RED"\nERREUR : Le fichier"RESET WHITE" %s" RESET RED " n'existe pas"RESET, file_name);
        fprintf(stderr, YELLOW"\nFin de la supression."RESET);
        fprintf(stderr, "\nS'il vous pla%ct, v%crifiez si le fichier existe, ou n'est pas d%cj%c ouvert, puis r%cessayez.\n", î, é, é, à, é); 
        stopRun();
    }

    case 2:
    {
        fprintf(stderr, "\n"RED"ERREUR : Option invalide."RESET" S'il vous pla%ct, r%cessayez.\n", î, é);
        stopRun();
    }

    case 3:
    {
        fprintf(stderr, RED"ERREUR : L'ouverture du dossier est impossible"RESET);
        stopRun();
    }

    case 4:
    {
        fprintf(stderr, RED"ERREUR : L'ouverture du dossier est impossible"RESET);
        stopRun();
    }
    }

        

    return 1;
}