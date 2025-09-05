#include ".\..\header\installer.h"

int main(int argc, char *argv[])
{
    printf("Avez vous d%dplac%d un des fichiers/dossiers, que vous venez de t%dl%dcharger ? (o/n) ", é, é, é, é);

    char *answer = malloc(sizeof(char) + 1);
    char *CodePath = malloc(sizeof(char)*300);
    char *CodePath_cpy;
    fgets(answer, sizeof(answer), stdin);
    viderBuffer();

    if(strcmp(answer, "o") == 0)
    {
        free(answer);
        printf("\nEntrez le chemin complet vers le dossier \"source_code\" (%da ressemble %d \"C:\\Utilisateur\\<votre_nom>\\T%dl%dchargements\\source_code\"): ", ç, à, é, é);
        fgets(CodePath, sizeof(CodePath), stdin);
        viderBuffer();
        CodePath_cpy = strdup(CodePath);
        CodePath = realloc(CodePath, strlen(CodePath) + 1 + strlen("\\bin\\gfmt.exe") + 1);
        strcat(CodePath, "\\bin\\gfmt.exe");
    }
    else
    {
        getcwd(CodePath, sizeof(char)*300);
        CodePath_cpy = strdup(CodePath);
        strcat(CodePath, "\\source_code\\bin\\gfmt.exe");
    }
    
    move_in_VPATH("GestionnaireDeFichierMT", CodePath, "gfmt.exe");

    char *dossier = malloc(strlen(CodePath_cpy) + 1 + strlen("\\source_code\\bin") + 1);
    strcpy(dossier, CodePath_cpy);
    strcat(dossier, "\\source_code\\bin");
    rmdir(dossier);
    free(dossier);

    char *dossier2 = malloc(strlen(CodePath_cpy) + 1 + strlen("\\source_code") + 1);
    strcpy(dossier2, CodePath_cpy);
    strcat(dossier2, "\\source_code");
    rmdir(dossier2);

    return 0;
}
