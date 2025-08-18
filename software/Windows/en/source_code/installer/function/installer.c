#include ".\..\header\installer.h"

int main(int argc, char *argv[])
{
    printf("Did you move any of the files you just downloaded? (y/n) ");

    char *answer = malloc(sizeof(char) + 1);
    char *CodePath = malloc(sizeof(char)*300);
    char *CodePath_cpy;
    fgets(answer, sizeof(answer), stdin);
    viderBuffer();

    if(strcmp(answer, "y") == 0)
    {
        free(answer);
        printf("\nEnter the full access path to the \"source_code\" folder (it looks like \"C:Users\\<your_name>\\Downloads\\source_code\"): ");
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
