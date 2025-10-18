#include "..\header\uninstaller.h"

int main(void)
{

FILE *f;

    f = fopen("C:\\Program Files\\GestionnaireDeFichierMT\\bin\\gfmt.exe", "r+");

    if(f==NULL)
        tell_error(__FILE__OPENNING__ERROR__, "gfmt.exe");

    fclose(f);

    errno = 0;

    desinstall("C:\\Program Files\\GestionnaireDeFichierMT\\bin\\gfmt.exe");

    if(errno != 0)
        tell_error(__FILE__DELETE__ERROR__, "gfmt.exe");

    rmdir("C:\\Program Files\\GestionnaireDeFichierMT\\bin");

    if(errno != 0)
        tell_error(__FOLDER__DELETE__ERROR__, "C:\\Program Files\\GestionnaireDeFichierMT\\bin");

    rmdir("C:\\Program Files\\GestionnaireDeFichierMT");
    
    if(errno != 0)
        tell_error(__FOLDER__DELETE__ERROR__, "C:\\Program Files\\GestionnaireDeFichierMT");

    printf("\nLe logiciel %c correctement %ct%c supprim%c. Merci de l'avoir utili%c !", à, é, é, é, é);
    return 0;
}