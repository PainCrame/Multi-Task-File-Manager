#include ".\..\header\installer.h"

int main(int argc, char *argv[])
{
    printf("Did you move any of the files you just downloaded? (y/n) ");

    char *answer = malloc(sizeof(char) + 1);
    char *CodePath = malloc(sizeof(char)*300);
    char *CodePath_cpy;
    fgets(answer, sizeof(answer), stdin);
    viderBuffer();

    if(strcmp(answer, "o") == 0)
    {
        free(answer);
        printf("\nEnter the full access path to the \"source_code\" folder (it looks like \"C:Users\\<your_name>\\Downloads\\source_code\"): ");
        fgets(CodePath, sizeof(CodePath), stdin);
        viderBuffer();
        CodePath_cpy = strdup(CodePath);
        CodePath = realloc(CodePath, strlen(CodePath) + 1 + strlen("\\gfmt.exe") + 1);
        strcat(CodePath, "\\fmt.exe");
    }
    else
    {
        getcwd(CodePath, sizeof(char)*300);
        CodePath_cpy = strdup(CodePath);
        strcat(CodePath, "\\gfmt.exe");
    }
    
    move_in_VPATH("GestionnaireDeFichierMT", CodePath, "gfmt.exe");

    return 0;
}
