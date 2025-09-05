#include "..\include\include.h"

int main(int argc, char *argv[])
{
    DIR *d;
    if(!(argc == 2 && (d = opendir(argv[1]))))
    {
        printf("%d", argc);
        printf("\nUtilisez la commande comme ceci : mtfm <chemin_complet_vers_le_dossier_que_vous_voulez>.\nPar exemple : \"mtfm C:\\utilisateurs\\Bureau\\Telechargements\"");
        getchar();
        exit(EXIT_FAILURE);
    }
    closedir(d);

    int c = chdir(argv[1]);
    if(! c==0)
    {
        perror("Erreur dans l'ouverture du fichier, s'il vous plait essayez plus tard.\nError ");
        getchar();
        exit(EXIT_FAILURE);
    }

    
    while(1)
    {
        int instruction;
        char buffer[PATH_MAX];

        printf("\nBienvenue dans le Gestionnaire de Fichier Multi-fonction !\n");
        printf("\nVous %dtes dans le dossier : %s\n(CTRL+C si vous souhaitez stopper le programme)\n", ê, getcwd(buffer, PATH_MAX));
        printf("\nSouhaitez vous : "BLUE "SUPPRIMER CERTAINS FICHIERS (0)"RESET" or "BLUE"NETTOYER LE DOSSIER (1) : "RESET);
        scanf("%d", &instruction);
        viderBuffer();
        
        if(instruction == 1)
        {
            printf(RED"ATTENTION"RESET": %dtes vous s%dre ? L'entieret%d du dossier va-t-%dtre supprim%d (%d l'exception des sous-dossiers). " BLUE "CONTINUER (0)" RESET " or" BLUE " RETOUR (1)"RESET " : ", ê, û, é, ê, é, à);
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
        else if(instruction == 0){
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
        else{
            error(2, NULL);
        }
    }

    return 0;
}