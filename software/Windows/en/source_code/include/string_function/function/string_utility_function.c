#include ".\..\..\include.h"

#ifdef _WIN32 
    #define slash "\\"
#elif defined __linux__ || defined __APPLE__
    #define slash "/"
#endif

int chararrlen(char **array)
{
    int i = 0; 

    while(array[i]!=NULL)
    {
        i++;
    }
    return i;
}


void strarr(char **array_list, char *init_string, char *delim) //transforme un *char en une liste de *char en fonction d'un délimiteur
{

    char *string_copy = strdup(init_string);

    if(string_copy == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    int i = 0;
    char *token;
    char *last_token;
    
    token = strtok(string_copy, delim);
    array_list[i] = token;
    i++;

    while(token != NULL)
    {
        token = strtok(NULL, delim);
        if(token ==NULL)
            break;
        
        last_token = token;
        array_list[i] = last_token;
        i++;
    }

    array_list[i] = NULL;

}

char *get_extension(char *file_name)
{

  char *file_name_copy = malloc(strlen(file_name)+1);

  if(file_name_copy == NULL)
    tell_error(__ALLOCATION__ERROR__, NULL);

  strcpy(file_name_copy, file_name); 

  char const *separator = ".";
  char *actual_token = strtok(file_name_copy, separator);
  char *last_token = NULL;

  while (actual_token != NULL) {
    last_token = actual_token;
    actual_token = strtok(NULL, separator);
  }

  if (last_token == NULL) {
    free(file_name_copy);
    return "ERROR";
  }

  char *extension;

  if((extension = strdup(last_token)) != NULL)
  {
    free(file_name_copy);
    return extension;
  }
  else
    tell_error(__ALLOCATION__ERROR__, NULL);

  
}

int get_nb_element_in_string(char *variable)
{
    char *limit = " ;-.,/";
    char *token;
    int element_nb = 0;
    char *variable_copy = malloc(strlen(variable)+1);

    if(variable_copy == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    strcpy(variable_copy,variable);

    token = strtok(variable_copy, limit);

    while(token != NULL)
    {
        element_nb++;
        token = strtok(NULL, limit);
    }

    free(variable_copy);

    return element_nb;
}

char *get_exe_name(char *path)
{
    char *token;
    char *token_save;
    char *separator = slash;

    token = strtok(path, separator);

    while(token != NULL)
    {
        token_save = token;
        token = strtok(NULL, separator);
    }

    char *exe_name = strdup(token_save);
    return exe_name;
}

char* toUperCase(char* text)
{
    char *returned_text;

    if( (returned_text = malloc(strlen(text) + 1)) == NULL )
        tell_error(__ALLOCATION__ERROR__, NULL);

    for(int i = 0 ; i < strlen(text) ; i++)
    {
        int ch = text[i];
        
        if(strchr("1234567890", ch) == NULL)
        {
            returned_text[i] = (char)((int)text[i] - 32);
            continue;
        }
        else
        {
            returned_text[i] = text[i];
        }
    }

    printf("\n%s", returned_text);

    returned_text[strlen(text)] = '\0';

    return returned_text;
}

char* toLowerCase(char* text)
{
    char *returned_text;

    if((returned_text = malloc(strlen(text) + 1)) == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);


    for(int i = 0 ; i < strlen(text) ; i++)
    {
        int ch = text[i];

        if(strchr("1234567890", ch) == NULL)
        {
            returned_text[i] = (char)((int)text[i] + 32);
            continue;
        }
            returned_text[i] = (int)text[i];
    }

    returned_text[strlen(text)] = '\0';

    return returned_text;
}