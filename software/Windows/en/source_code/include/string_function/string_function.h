#ifndef STRING_FUNCTION_H
#define STRING_FUNCTION_H

int chararrlen(char **array);
void strarr(char **array_list, char *init_string, char *delim); //transforme un *char en une liste de *char en fonction d'un délimiteur
char *get_extension(char *file_name);
int get_nb_element_in_string(char *variable);
char *get_exe_name(char *path);
char* toUperCase(char* text);
char *toLowerCase(char *text);

int haveExtension(char *file_name, char **all_extension);
int isFolder(char *name);
int isException(char *file_name, char **all_exception);



#endif