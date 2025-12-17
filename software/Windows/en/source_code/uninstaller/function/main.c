#include "..\header\uninstaller.h"

void remove_program_file(void)
{
    FILE *f;

    f = fopen("C:\\Program Files\\MultiTaskFM\\bin\\mftm.exe", "r+");

    if(f==NULL)
        tell_error(__FILE__OPENNING__ERROR__, "mftm.exe");

    fclose(f);

    errno = 0;

    desinstall("C:\\Program Files\\MultiTaskFM\\bin\\mftm.exe");

    if(errno != 0)
        tell_error(__FILE__DELETE__ERROR__, "mftm.exe");
    
    printf("\nFile mftm.exe suppressed !");

    rmdir("C:\\Program Files\\MultiTaskFM\\bin");

    if(errno != 0)
        tell_error(__FOLDER__DELETE__ERROR__, "C:\\Program Files\\MultiTaskFM\\bin");

    printf("\nFolder C:\\Program Files\\MultiTaskFM\\bin suppressed !");

    rmdir("C:\\Program Files\\MultiTaskFM");
    
    if(errno != 0)
        tell_error(__FOLDER__DELETE__ERROR__, "C:\\Program Files\\MultiTaskFM");

    printf("\nFolder C:\\Program Files\\MultiTaskFM folder !");
}

int get_number_in_env(const char *__PATH__ENV__)
{
    int nb_of_program_in_env = 0;

    const char *separator = ";";
    const char *program_path = "C:\\Program Files\\MultiTaskFM\\bin";

    char *__PATH__ENV__COPY__ = strdup(__PATH__ENV__);

    char *token = strtok(__PATH__ENV__COPY__, separator);

    if(strcmp(token, program_path) == 0)
            nb_of_program_in_env++;


    while(token != NULL) //comptage nombre apparition pour malloc
    {        
        if(strcmp(token, program_path) == 0)
        nb_of_program_in_env++;

        token = strtok(NULL, separator);
    }

    free(__PATH__ENV__COPY__);

    return nb_of_program_in_env;
}

char *get_new_path_env(const char *__PATH__ENV__)
{
    char *__PATH__ENV__COPY__ = strdup(__PATH__ENV__);
    const char *separator = ";";
    const char *program_path = "C:\\Program Files\\MultiTaskFM\\bin";
    char *token;
    char *new_path_env;
    int nb_of_program_in_env;

    nb_of_program_in_env = get_number_in_env(__PATH__ENV__);

    size_t new_path_size = strlen(__PATH__ENV__) - strlen("C:\\Program Files\\MultiTaskFM\\bin;") * nb_of_program_in_env - strlen(";") + 1; //calcul nouvelle taille
    new_path_env = malloc(new_path_size);

    token = strtok(__PATH__ENV__COPY__, separator); //decoupage

    while(strcmp(token, program_path) == 0) //si gfmt est au debut
    {
        token = strtok(NULL, separator);

        if(token == NULL)
            break;
    }

    strcpy(new_path_env, token); //cpy prcq cat fonctionne pas sur une chaine vide
    strcat(new_path_env, ";");
    
    token = strtok(NULL, separator);

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

    free(__PATH__ENV__COPY__);

    return new_path_env;
}

char *get_command_for_env(char *new_path_env)
{
    char *command = malloc(strlen("setx PATH \"") + strlen(new_path_env) + strlen("\"") + 1);

    if(command == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    strcpy(command, "setx PATH \"");
    strcat(command, new_path_env);
    strcat(command, "\"");

    return command;
}

void remove_program_of_path(char *new_path_env)
{
    char *command = get_command_for_env(new_path_env);

    if(system(command) == -1)
        tell_error(0, NULL);

    printf("Successful deltion of the program path !");

    free(command);
}

int main(void)
{
    const char *__PATH__ENV__ = getenv( "PATH" );
    int nb_of_program_in_env;
    const char *separator = ";";
    const char *program_path = "C:\\Program Files\\MultiTaskFM\\bin";
    char *new_path_env;
    char *token;

    remove_program_file();

    new_path_env = get_new_path_env(__PATH__ENV__);

    remove_program_of_path(new_path_env);

    printf("\nThe software has been correctly deleted. Thanks for usage !");

    stopRun(EXIT_SUCCESS);
    
    return 0;
}