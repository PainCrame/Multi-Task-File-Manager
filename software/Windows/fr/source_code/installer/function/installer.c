#include ".\..\header\installer.h"

int main(int argc, char *argv[])
{

    if(!admin_mode())
        tell_error(__PRIVILEGE__ERROR__, NULL);
        
    printf("Avez vous d%cplac%c un des fichiers/dossiers, que vous venez de t%cl%ccharger ? (o/n) ", é, é, é, é);

    char *answer = malloc(sizeof(char) + 1);
    char *CodePath = malloc(sizeof(char)*300);

    if((answer == NULL) || (CodePath == NULL))
        tell_error(__ALLOCATION__ERROR__, NULL);

    char *CodePath_cpy;
    fgets(answer, sizeof(answer), stdin);
    viderBuffer();

    if(strcmp(answer, "o\n") == 0)
    {
        free(answer);
        printf("\nEntrez le chemin complet vers le dossier où se situe le fichier \"gfmt.exe\" (%ca ressemble %c \"C:\\Utilisateur\\<votre_nom>\\T%cl%cchargements\"): ", ç, à, é, é);
        fgets(CodePath, sizeof(CodePath), stdin);
        viderBuffer();
        CodePath_cpy = strdup(CodePath);
        CodePath = realloc(CodePath, strlen(CodePath) + 1 + strlen("\\gfmt.exe") + 1);

        if(CodePath_cpy == NULL)
            tell_error(__ALLOCATION__ERROR__, NULL);

        strcat(CodePath, "\\gfmt.exe");
    }
    else
    {
        getcwd(CodePath, sizeof(char)*300);
        CodePath_cpy = strdup(CodePath);

        if(CodePath_cpy == NULL)
            tell_error(__ALLOCATION__ERROR__, NULL);

        strcat(CodePath, "\\gfmt.exe");
    }
    
    move_in_VPATH("GestionnaireDeFichierMT", CodePath, "gfmt.exe");

    return 0;
}
