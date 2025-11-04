#include ".\..\..\include.h"

// #define BUFFER 1024

FILE *fopen_log(char *file_name, char *mod);
FILE *fwrite_log(FILE *_File, int code, char *file_name);

// double log16(int x)
// {
//     return log(x) / log(16);
// }

// char* hex(char *number)
// {
//     // char chiffre[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//     // int *position = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
//     // if(strcmp(number, "0\n") == 0)
//     //     return strdup("0x0");

//     // int nb = atoi(number);
//     // int max_16power = (int)log16(nb);
//     // int bits = max_16power + 1;

//     // char *buffer = malloc(bits);
//     // char *binary = malloc(bits + 3); // '0', 'x', bits, '\0'

//     // for (int i = 0; i < bits; i++) {
//     //     buffer[i] = '0';
//     // }

//     // while (nb > 0) {
//     //     int power = (int)log16(nb);
//     //     buffer[power] = '1';
//     //     nb -= (1 << power);
//     // }

//     // binary[0] = '0';
//     // binary[1] = 'x';

//     // for (int i = max_16power; i >= 0; i--) {
//     //     binary[2 + max_16power - i] = buffer[i];
//     // }

//     // binary[bits + 2] = '\0';

//     // free(buffer);
//     // return binary;
// }

// char* bin(char *number)
// {
//     if(strcmp(number, "0\n") == 0)
//         return strdup("0b0");

//     int nb = atoi(number);
//     int max_2power = (int)log2(nb);
//     int bits = max_2power + 1;

//     char *buffer = malloc(bits);
//     char *binary = malloc(bits + 3); // '0', 'B', bits, '\0'

//     for (int i = 0; i < bits; i++) {
//         buffer[i] = '0';
//     }

//     while (nb > 0) {
//         int power = (int)log2(nb);
//         buffer[power] = '1';
//         nb -= (1 << power);
//     }

//     binary[0] = '0';
//     binary[1] = 'b';

//     for (int i = max_2power; i >= 0; i--) {
//         binary[2 + max_2power - i] = buffer[i];
//     }

//     binary[bits + 2] = '\0';

//     free(buffer);
//     return binary;
// }

// char *toBaseX(char *number, int base)
// {
//     if(base==16)
//         hex(number);

//     else if(base==2)
//         bin(number);
//     else
//     {
//         printf("\nInvalid Option");
//         exit(EXIT_FAILURE);
//     }
    
// }



char *get_current_time(void)
{
    char *current_time = malloc(24*sizeof(char));
    time_t now;
    
    time(&now);
    
    current_time = ctime(&now);
    
    return current_time;
}



FILE *fwrite_log(FILE *_File, int code, char *file_name)
{
    char *current_hour = get_current_time();

    switch (code)
    {
    case 0:
        /* code */
        break;

    case 1:
        break;

    case __HOUR__:
        fwrite(__OPEN__LOG__STR__, strlen(__OPEN__LOG__STR__), 1, _File);
        fwrite(current_hour, strlen(current_hour), 1, _File);
        fwrite("\n", strlen("\n"), 1, _File);
        break;

    case __RESET__:
        fclose(_File);
        _File = fopen(file_name, "w+");
        fwrite(__RESET__LOG__STR__, strlen(__RESET__LOG__STR__), 1, _File);
        fwrite(" at ", strlen(" at "), 1, _File);
        fwrite(current_hour, strlen(current_hour), 1, _File);
        fwrite("\n", strlen("\n"), 1, _File);
        return _File;
        break;

    case __SUPPRESSED__FILE__:
        fwrite(file_name, strlen(file_name), 1, _File);
        fwrite(__SUPPRESSED__STR__, strlen(__SUPPRESSED__STR__), 1, _File);
        fwrite("\n", strlen("\n"), 1, _File);
        break;
        
    case __EXTENSION__SUPPRESSION__MODE__:
        fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
        fwrite(__EXTENSION__STR__, strlen(__EXTENSION__STR__), 1, _File);
        fwrite("\n", strlen("\n"), 1, _File);
        break;

    case __FILE__SUPPRESSION__MODE__:
        fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
        fwrite(__FILE__STR__, strlen(__FILE__STR__), 1, _File);
        fwrite("\n", strlen("\n"), 1, _File);
        break;
    
        case __FOLDER__CLEAR__MODE__:
        fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
        fwrite(__CLEAR__STR__, strlen(__CLEAR__STR__), 1, _File);
        fwrite("\n", strlen("\n"), 1, _File);
        break;

    case __FOLDER__SORT__MODE__:
        fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
        fwrite(__SORT__STR__, strlen(__SORT__STR__), 1, _File);
        fwrite("\n", strlen("\n"), 1, _File);
        break;

    default:
        break;
    }

    fclose(_File);
}

void open_log_dir(void)
{
    DIR *d;
    if(opendir("GestionnaireDeFichierMT") == NULL)
        if(mkdir("GestionnaireDeFichierMT") != 0)
            tell_error(__MAKE_FOLDER__ERROR__, "GestionnaireDeFichierMT");
    
    if(chdir("GestionnaireDeFichierMT") != 0)
        tell_error(__FOLDER__OPENNING__ERROR__, "GestipnnaireDeFichierMT");
}

void chdir_log(void)
{
    char *APPDATA;
    if((APPDATA = getenv("APPDATA")) == NULL)
        tell_error(__FOLDER__OPENNING__ERROR__, "APPDATA");

    if(chdir(APPDATA) != 0)
        tell_error(__FOLDER__OPENNING__ERROR__, "APPDATA");
    
    if(chdir(".\\..") != 0)
        tell_error(__FOLDER__OPENNING__ERROR__, "AppData\\Roaming\\..");

    if(chdir(".\\Local") != 0)
        tell_error(__FOLDER__OPENNING__ERROR__, "APPDATA\\Local");
}


int freset_log(char *file_name)
{
    FILE *f;

    if((f = fopen(file_name, "w+")) == NULL)
        tell_error(__FILE__OPENNING__ERROR__, file_name);
        
    fwrite_log(f, __RESET__, file_name);

    fclose(f);
        
    f = NULL;
}


void fcopy(char *file_name, char *new_file_name)
{
    FILE *src;
    
    if((src = fopen(file_name, "rb")) == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture dans le fichier %s.", file_name);
        exit(EXIT_FAILURE);
    }

    FILE *dest;

    if( (dest = fopen(new_file_name, "wb")) == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture dans le fichier pour sauvegarder le log");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];

    int ch;

    while( (ch = fread(buffer, 1, sizeof(buffer), src)) != 0)
    {
        int byte = fwrite(buffer, 1, ch, dest);
    }

    fclose(src);
    fclose(dest);
    
    src = NULL;
    dest = NULL;

    freset_log(file_name);
}

void check_log_size(char *file_name)
{
    struct stat *info;

    if(stat(file_name, info) != 0)
        tell_error(__FILE__OPENNING__ERROR__, file_name);

    if(info->st_size <= 500000)
        return;

    char *new_file_name = malloc(strlen(file_name) + strlen(".save") + 1);
    
    if(new_file_name == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);
        
    strcpy(new_file_name, file_name);
    strcat(new_file_name, ".save");


    fcopy(file_name, new_file_name);
}

FILE *fopen_log(char *file_name, char *mod)
{
    chdir_log();

    open_log_dir();

    FILE *f = fopen(file_name, mod);

    if (f == NULL)
    {
        perror("Erreur Ouverture");
        exit(EXIT_FAILURE);
    }

    fwrite_log(f, __HOUR__, file_name);

    return f;
}

void log_info(char *file_name, char *mode, int info_code)
{  
    FILE *f = fopen_log(file_name, mode);

    if(f == NULL)
        tell_error(__FILE__OPENNING__ERROR__, file_name);

    fwrite_log(f, info_code, file_name);

    check_log_size(file_name);
        
    return;
}