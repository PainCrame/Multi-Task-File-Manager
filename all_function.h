#ifndef ALLFUNCTION
#define ALLFUNCTION

int chararrlen(char **array); //renvoie la longueur en nombre d'élément d'un tableau de *char en ignorant le caractère NULL de fin
void strarr(char **array_list, char *init_string, char *delim); //transforme un *char en une liste de *char en fonction d'un délimiteur
int haveExtension(char *file_name, char **all_extension); // vérifie si le fichier possède une des extensions spécifiés par l'utilisateur
int isException(char *file_name, char **all_exception); // vérifie si le fichier est une des exceptions spécifiés par l'utilisateur
char *get_extension(char *file_name); // renvoie l'extension du fichier passé en argument
int get_nb_element_in_string(char *variable); //récupère le nombre de *char dans une phrase
int isFolder(char *name); //vérifie si l'erreur de lecture est généré par le fait que le nom soit un nom de dossier
char *get_exe_name(char *path);


#endif