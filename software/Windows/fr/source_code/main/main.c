#include "..\include\include.h"

int main(int argc, char *argv[])
{

    check_option(argc, argv);

    DIR *d;

    if((d = opendir(argv[1])) == NULL)
    {
        perror("\nDossier inexistant ou inacessible\nERROR : ");
        getchar();
        exit(EXIT_FAILURE);
    }

    if(chdir(argv[1]) != 0)
    {
        tell_error(__FOLDER__OPENNING__ERROR__, NULL);
    }

    printf("\nBienvenue dans le Gestionnaire de Fichier Multi-fonction !\n");
    
    while(1)
    {
        int instruction;
        char buffer[PATH_MAX];

        printf("\nVous %ctes dans le dossier : %s\n(CTRL+C si vous souhaitez stopper le programme)\n", ê, getcwd(buffer, PATH_MAX));
        printf("\nSouhaitez vous : "BLUE "SUPPRIMER CERTAINS FICHIERS (0)"RESET" ou "BLUE"NETTOYER LE DOSSIER (1) : "RESET" ou "BLUE"TRIER LE DOSSIER (2) : "RESET);
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
                tell_error(__INVALID__OPTIONN__, NULL);
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
                tell_error(__INVALID__OPTIONN__, NULL);
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
            tell_error(__INVALID__OPTIONN__, NULL);
        }
    }

    return 0;
}