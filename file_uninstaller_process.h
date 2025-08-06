#ifndef DESINSTALLEUR
#define DESINSTALLEUR

// procède à la désinstallation des fichiers
void process_uninstall_file(void);

// désinstalle le fichier passé en argument 
void desinstall(char *file_name);

// indique l'erreur à l'utilisateur
int error(char *file_name);

#endif