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

        const char *__PATH__ENV__ = getenv( "PATH" );

    printf("PATH / %s ", __PATH__ENV__);

    char *__PATH__ENV__COPY__ = strdup(__PATH__ENV__);

    int nb_of_program_in_env = 0;

    const char *separator = ";";
    const char *program_path = "C:\\Program Files\\GestionnaireDeFichierMT\\bin";

    printf("\nEnv copie !");

    char *token = strtok(__PATH__ENV__COPY__, separator);

    printf("\nComptage du nombre d'apparitions");

    if(strcmp(token, program_path) == 0)
            nb_of_program_in_env++;

    printf("\nDebut de boucle");

    while(token != NULL) //comptage nombre apparition pour malloc
    {
        printf("\nToken : %s", token);
        
        if(strcmp(token, program_path) == 0)
        nb_of_program_in_env++;

        token = strtok(NULL, separator);
    }

    free(__PATH__ENV__COPY__);
    __PATH__ENV__COPY__ = NULL;
    __PATH__ENV__COPY__ = strdup(__PATH__ENV__);

    size_t new_path_size = strlen(__PATH__ENV__) - strlen("C:\\Program Files\\GestionnaireDeFichierMT\\bin;") * nb_of_program_in_env - strlen(";") + 1; //calcul nouvelle taille
    printf("\nNombre : %d", nb_of_program_in_env);

    char *new_path_env = malloc(new_path_size);

    printf("\nDebut de la copie du premier terme");

    token = strtok(__PATH__ENV__COPY__, separator); //decoupage

    printf("\nPremier decoupage reussi");

    while(strcmp(token, program_path) == 0) //si gfmt est au debut
    {
        token = strtok(NULL, separator);

        if(token == NULL)
            break;
    }

    printf("\nPremiere copy");

    strcpy(new_path_env, token); //cpy prcq cat fonctionne pas sur une chaine vide
    strcat(new_path_env, ";");
    
    token = strtok(NULL, separator);


    printf("\nDebut de la copie des termes");

    while(token != NULL)
    {
        if(strcmp(token, program_path) != 0)
        {
            strcat(new_path_env, token);
            strcat(new_path_env, ";");
        }

        token = strtok(NULL, separator);
    }

    new_path_env[strlen(new_path_env) - 1] = '\0'; //retirer le dernier ";"

    printf("\ncopy : %s", __PATH__ENV__COPY__);;


    printf("\nTaille voulue : %lld, taille obtenue : %lld", new_path_size - 1, strlen(new_path_env));
    printf("\n%s", new_path_env);

    char *command = malloc(strlen("setx PATH \"") + strlen(new_path_env) + strlen("\"") + 1);

    if(command == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    strcpy(command, "setx PATH \"");
    strcat(command, new_path_env);
    strcat(command, "\"");

    if(system(command) == -1)
        tell_error(0, NULL);

    printf("\nLe logiciel %c correctement %ct%c supprim%c. Merci de l'avoir utili%c !", à, é, é, é, é);

    stopRun(EXIT_SUCCESS);
    
    return 0;
}