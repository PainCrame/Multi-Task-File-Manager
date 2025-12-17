#include "..\include\include.h"

int main(int argc, char *argv[])
{
    check_option(argc, argv);

    DIR *d;

    if((d = opendir(argv[1])) == NULL)
    {
        perror("\nDossier inexistant ou inacessible\nERROR ");
        stopRun(EXIT_FAILURE);
    }
    
    if(chdir(argv[1]) != 0)
        tell_error(__FOLDER__OPENNING__ERROR__, NULL);    
    
    log_info("INFO.log", "a+", __PROGRAM__LAUNCHED__LOG__, __FILE__, __LINE__, argv[1]);
    
    printf("\nBienvenue dans le Gestionnaire de Fichier Multi-fonction !\n");
    
    while(1)
    {
        int instruction;
        char buffer[PATH_MAX];

        printf("\nVous %ctes dans le dossier : %s\n(CTRL+C si vous souhaitez stopper le programme)\n", ê, getcwd(buffer, PATH_MAX));
        printf("\nSouhaitez vous : "BLUE "SUPPRIMER CERTAINS FICHIERS (0)"RESET" ou "BLUE"NETTOYER LE DOSSIER (1) : "RESET" ou "BLUE"TRIER LE DOSSIER (2)"RESET" ou "BLUE"EXTRAIRE LES FICHIERS ET SOUS FICHIERS (3) : "RESET);
        scanf("%d", &instruction);
        viderBuffer();
        
        if(instruction == 1)
        {
            printf(RED"ATTENTION"RESET": %ctes vous s%cre ? L'entieret%c du dossier va-t-%ctre supprim%c (%c l'exception des sous-dossiers). " BLUE "CONTINUER (0)" RESET " or" BLUE " RETOUR (1)"RESET " : ", ê, û, é, ê, é, à);
            scanf("%d", &instruction);
            viderBuffer();

            if(instruction != 0)
            {  
                instruction = 4;
                continue;
            }

            log_info(__INFO__LOG__, "a+", __FOLDER__CLEAR__MODE__LOG__, __FILE__, __LINE__, argv[1]);

            clear_folder();
            instruction = 4;
        }

        else if(instruction == 0)
        {
            instruction = 4;

            printf("\nSouhaitez vous supprimer les fichiers par leur :"BLUE" NOM (0)"RESET" or"BLUE" EXTENSION (1)"RESET" : ");
            scanf("%d", &instruction);
            viderBuffer();

            if(instruction == 0)
            {
                log_info(__INFO__LOG__, "a+", __FILE__SUPPRESSION__MODE__LOG__, __FILE__, __LINE__, argv[1]);

                process_uninstall_file();

                instruction = 4;
            }
            else if(instruction == 1)
            {
                log_info(__INFO__LOG__, "a+", __EXTENSION__SUPPRESSION__MODE__LOG__, __FILE__, __LINE__, argv[1]);

                uninstall_extension(argv[0]);

                instruction = 4;
            }
            else
            {
                tell_error(__INVALID__OPTIONN__, NULL);
            }
        }

        else if(instruction == 2)
        {
            instruction = 4;

            log_info(__INFO__LOG__, "a+", __FOLDER__SORT__MODE__LOG__, __FILE__, __LINE__, argv[1]);
            
            trier();

            printf("\nLe dossier a %ct%c correctement tri%c !\n", é, é, é);

            instruction = 4;
        }

        else if(instruction == 3)
        {
            // printf(RED"\nATTENTION : Les sous dossiers une fois vid%c seront supprim%cs."RESET" \nSouhaitez vous continuer ? Oui (0) / Non (1) : ", é, é);
            // scanf("%d", &instruction);
            // viderBuffer();

            // if(instruction != 0)
            //     continue;

            log_info(__INFO__LOG__, "a+", __FOLDER__EXTRACT__MODE__LOG__, __FILE__, __LINE__, argv[1]);

            extract_main_folder();

            printf("\nTous les sous fichiers ont correctement %ct%c extraits", é, é);

            instruction = 4;
        }

        else
        {
            tell_error(__INVALID__OPTIONN__, NULL);
        }
    }

    return 0;
}