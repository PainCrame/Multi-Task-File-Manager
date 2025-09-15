#include "..\include\include.h"

int main(int argc, char *argv[])
{
    DIR *d;
    if(!(argc == 2))
    {
        fprintf(stderr, "\nUtilisez la commande comme ceci : mtfm <chemin_complet_vers_le_dossier_que_vous_voulez>.\nPar exemple : \"gfmt C:\\Users\\<Votre_Nom>\\Downloads\"");
        getchar();
        exit(EXIT_FAILURE);
    }

    if(strcmp(argv[1], "hello") == 0)
    {
        printf("\nBien le bonjour depuis le Gestionnaire de Fichiers Multi-fonction !\n");
        getchar();
        exit(EXIT_SUCCESS);
    }

    if((d = opendir(argv[1])) == NULL)
    {
        perror("\nDossier inexistant ou inacessible\nERROR : ");
        getchar();
        exit(EXIT_FAILURE);
    }

    if(chdir(argv[1]) != 0)
    {
        perror("Erreur dans l'ouverture du dossier specifie, s'il vous plait essayez plus tard.\nError ");
        getchar();
        exit(EXIT_FAILURE);
    }


    printf("\nBienvenue dans le Gestionnaire de Fichier Multi-fonction !\n");
    
    while(1)
    {
        int instruction;
        char buffer[PATH_MAX];

        printf("\nVous %ctes dans le dossier : %s\n(CTRL+C si vous souhaitez stopper le programme)\n", ê, getcwd(buffer, PATH_MAX));
        printf("\nSouhaitez vous : "BLUE "SUPPRIMER CERTAINS FICHIERS (0)"RESET" or "BLUE"NETTOYER LE DOSSIER (1) : "RESET" or "BLUE"TRIER LE DOSSIER (2) : "RESET);
        scanf("%d", &instruction);
        viderBuffer();
        
        if(instruction == 1)
        {
            printf(RED"ATTENTION"RESET": %ctes vous s%cre ? L'entieret%c du dossier va-t-%ctre supprim%c (%c l'exception des sous-dossiers). " BLUE "CONTINUER (0)" RESET " or" BLUE " RETOUR (1)"RESET " : ", ê, û, é, ê, é, à);
            scanf("%d", &instruction);
            viderBuffer();

            if(instruction==0)
            {  
                clear_folder();

            }else if( instruction == 1){

                continue;
                
            }else{
                error(2, NULL);
            }
            return 1;
        }

        else if(instruction == 0)
        {
            instruction = 3;

            printf("\nSouhaitez vous supprimer les fichiers par leur :"BLUE" NOM (0)"RESET" or"BLUE" EXTENSION (1)"RESET" : ");
            scanf("%d", &instruction);
            viderBuffer();

            if(instruction == 0)
            {
                process_uninstall_file();
            }
            else if(instruction == 1)
            {
                uninstall_extension(argv[0]);
            }
            else
            {
                error(2, NULL);
            }
        }

        else if(instruction == 2)
        {
            instruction = 3;

            trier();

            printf("\nLe dossier a %ct%c correctement tri%c !\n", é, é, é);
        }

        else
        {
            error(2, NULL);
        }
    }

    return 0;
}