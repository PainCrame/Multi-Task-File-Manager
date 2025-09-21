#include ".\..\header\installer.h"

int main(int argc, char *argv[])
{
    printf("Did you move any of the files you just downloaded? (y/n) ");

    char *answer = malloc(sizeof(char) + 1);
    char *CodePath = malloc(sizeof(char)*300);

    if((answer == NULL) || (CodePath) == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    char *CodePath_cpy;
    fgets(answer, sizeof(answer), stdin);
    viderBuffer();

    if(strcmp(answer, "o") == 0)
    {
        free(answer);
        printf("\nEnter the full access path to the \"mtfm.exe\" file (it looks like \"C:Users\\<your_name>\\Downloads\\\"): ");
        fgets(CodePath, sizeof(CodePath), stdin);
        viderBuffer();
        CodePath_cpy = strdup(CodePath);
        CodePath = realloc(CodePath, strlen(CodePath) + 1 + strlen("\\gfmt.exe") + 1);
        
        if(CodePath_cpy == NULL)
            tell_error(__ALLOCATION__ERROR__, NULL);
        
        strcat(CodePath, "\\mtfm.exe");
    }
    else
    {
        getcwd(CodePath, sizeof(char)*300);
        CodePath_cpy = strdup(CodePath);

        if(CodePath_cpy == NULL)
            tell_error(__ALLOCATION__ERROR__, NULL);

        strcat(CodePath, "\\mtfm.exe");
    }
    
    move_in_VPATH("MultiTaskFM", CodePath, "mtfm.exe");

    return 0;
}
