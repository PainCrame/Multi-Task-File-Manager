#include ".\..\..\include.h"

int haveExtension(char *file_name, char **all_extension)
{
    int i;
    char *file_name_cpy = strdup(file_name);

    if(file_name_cpy == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    char *extension;

    for(i = 0 ; i < chararrlen(all_extension) ; i++)
    {
        if((strcmp(extension = get_extension(file_name_cpy), all_extension[i])) == 0)
        {
            free(file_name_cpy);
            free(extension);
            return 1;
        }

        free(extension);
    }

    free(file_name_cpy);


    return 0;
}

int isFolder(char *name)
{
    DIR *d = opendir(name);

    if(d != NULL)
    {
        closedir(d);
        return 1;
    }
    
    return 0;

}

int isException(char *file_name, char **all_exception)
{
    int i;
    char *file_name_cpy = strdup(file_name);

    if(file_name_cpy == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);

    for(i = 0 ; i < chararrlen(all_exception) ; i++)
    {
    
        if(strcmp(all_exception[i], file_name_cpy) == 0)
        {
            free(file_name_cpy);
            return 1;
        }
    }
    
    return 0;
}