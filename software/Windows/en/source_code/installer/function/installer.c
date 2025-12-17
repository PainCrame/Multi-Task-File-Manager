#include ".\..\header\installer.h"

int main(int argc, char *argv[])
{
    if(!admin_mode())
        tell_error(__PRIVILEGE__ERROR__, NULL);

    printf("Did you move any of the files you just downloaded? (y/n) ");

    char *answer = malloc(sizeof(char) + 1);
    char *CodePath = malloc(sizeof(char)*300);

    if((answer == NULL) || (CodePath) == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    char *CodePath_cpy;
    fgets(answer, sizeof(answer), stdin);

    if(getcwd(CodePath, sizeof(char)*300) == NULL)
        tell_error(__GET__DIR__ERROR__, CodePath);

    CodePath_cpy = strdup(CodePath);

    if(CodePath_cpy == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    strcat(CodePath, "\\mtfm.exe");

    
    move_in_VPATH("MultiTaskFM", CodePath, "mtfm.exe");

    return 0;
}