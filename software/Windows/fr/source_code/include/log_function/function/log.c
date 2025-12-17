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
    
    time_t now = time(NULL);

    char *current_time = ctime(&now);
    
    return strdup(current_time);
}

//write current line and file for debug
void current_execution_line(FILE *_File, char *_file_name_, int _line_)
{
    if(_File == NULL)
        tell_error(__FILE__OPENNING__ERROR__, NULL);

    fwrite("\nIn file ", 1, strlen("\nIn file "), _File);
    fwrite(_file_name_, 1, strlen(_file_name_), _File);

    fprintf(_File, " at line %d", _line_);
}


FILE *fwrite_log(FILE *_File, int code, char *file_name)
{
    if(code<13) //if the code is an error
        fprintf(_File, "\nERRNO : %d", errno);
    
    errno = 0;
    
    char *current_hour = get_current_time();

    switch (code)
    {
        case 0:
        {
            fwrite(__ERROR__OCCURED__STR__, strlen(__ERROR__OCCURED__STR__), 1, _File);
            stopRun(EXIT_FAILURE);
            break;
        } 
        
        case __OPENING__ERROR__LOG__:
        {
            fwrite(__OPENING__ERROR__STR__, strlen(__OPENING__ERROR__STR__), 1, _File);
            fwrite(file_name, strlen(file_name), 1, _File);
            fwrite(__CHECK__IF__OPEN__STR, strlen(__CHECK__IF__OPEN__STR), 1, _File);
            break;
        }

        case __INVALID__OPTIONN__:
        {
            fwrite(__INVALID__OPTION__STR__, strlen(__INVALID__OPTION__STR__), 1, _File);
            break;
        }

        case __ARGUMENT__ERROR__:
        {
            fwrite(__ARGUMENT__ERROR__STR__, strlen(__ARGUMENT__ERROR__STR__), 1, _File);
            break;
        }

        case __ALLOCATION__ERROR__:
        {
            fwrite(__MEMORY__ALLOCATION__ERROR__STR__, strlen(__MEMORY__ALLOCATION__ERROR__STR__), 1, _File);
            break;
        }

        case __PATH__LENGTH__ERROR__:
        {
            fwrite(__PATH__LENGTH__ERROR__STR__, strlen(__PATH__LENGTH__ERROR__STR__), 1, _File);
            break;
        }

        case __FILE__MOVE__ERROR__:
        {
            fwrite(__FILE__DELETE__ERROR__STR__, strlen(__FILE__DELETE__ERROR__STR__), 1, _File);
            fwrite(file_name, strlen(file_name), 1, _File);
            break;
        }

        case __MAKE_FOLDER__ERROR__:
        {
            fwrite(__MAKE__FOLDER__ERROR__STR__, strlen(__MAKE__FOLDER__ERROR__STR__), 1, _File);
            fwrite(file_name, strlen(file_name), 1, _File);
            break;
        }

        case __FILE__DELETE__ERROR__:
        {
            fwrite(__FILE__DELETE__ERROR__STR__ , strlen(__FILE__DELETE__ERROR__STR__), 1, _File);
            fwrite(file_name, strlen(file_name), 1, _File);
            break;
        }

        case __FOLDER__DELETE__ERROR__:
        {
            fwrite(__FOLDER__DELETE__ERROR__STR__, strlen(__FOLDER__DELETE__ERROR__STR__), 1, _File);
            fwrite(file_name, strlen(file_name), 1, _File);
            break;
        }

        case __GET__DIR__ERROR__:
        {
            fwrite(__GET__DIR__ERROR__STR__, strlen(__GET__DIR__ERROR__STR__), 1, _File);
            break;
        }

        case __PRIVILEGE__ERROR__:
        {
            fwrite(__PRIVILEGE__ERROR__STR__, strlen(__PRIVILEGE__ERROR__STR__), 1, _File);
            break;
        }

        case __HOUR__LOG__:
        {
            fwrite(__OPEN__LOG__STR__, strlen(__OPEN__LOG__STR__), 1, _File);
            fwrite(current_hour, strlen(current_hour), 1, _File);
            fwrite("\n", strlen("\n"), 1, _File);

            free(current_hour);
            current_hour = NULL;

            return _File;
            break;
        }

        case __PROGRAM__LAUNCHED__LOG__:
        {
            fwrite(__PROGRAM__LAUNCHED__STR__, strlen(__PROGRAM__LAUNCHED__STR__), 1, _File);

            free(current_hour);
            current_hour = NULL;

            return _File;
            break;
        }

        case __SUPPRESSED__FILE__LOG__:
        {
            fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
            fwrite(file_name, strlen(file_name), 1, _File);
            fwrite(__SUPPRESSED__STR__, strlen(__SUPPRESSED__STR__), 1, _File);
        }

        case __EXTENSION__SUPPRESSION__MODE__LOG__:
        {
            fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
            fwrite(__EXTENSION__SUPPRESSION__MODE__STR__, strlen(__EXTENSION__SUPPRESSION__MODE__STR__), 1, _File);
            break;
        }

        case __FILE__SUPPRESSION__MODE__LOG__:
        {
            fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
            fwrite(__FILE__SUPPRESSION__MODE__STR__, strlen(__FILE__SUPPRESSION__MODE__STR__), 1, _File);
            break;
        }

        case __FOLDER__CLEAR__MODE__LOG__:
        {
            fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
            fwrite(__FOLDER__CLEAR__MODE__STR__, strlen(__FOLDER__CLEAR__MODE__STR__), 1, _File);
            break;
        }

        case __FOLDER__SORT__MODE__LOG__:
        {
            fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
            fwrite(__FOLDER__SORT__MODE__STR__, strlen(__FOLDER__SORT__MODE__STR__), 1, _File);
            break;
        }

        case __FOLDER__EXTRACT__MODE__LOG__:
        {
            fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
            fwrite(__FOLDER__EXTRACT__MODE__STR__, strlen(__FOLDER__EXTRACT__MODE__STR__), 1, _File);
            break;
        }

        case __MOVED__FILE__LOG__:
        {
            fwrite(__ACTION__STR__, strlen(__ACTION__STR__), 1, _File);
            fwrite(file_name, strlen(file_name), 1, _File);
            fwrite(__MOVED__STR__, strlen(__MOVED__STR__), 1, _File);
        }

    }

    free(current_hour);
    current_hour = NULL;
    
    fclose(_File);
}

void open_log_dir(void) //go into APPDATA/LOCAL/GFMT
{
    if(opendir("GestionnaireDeFichierMT") == NULL)
        if(mkdir("GestionnaireDeFichierMT") != 0)
            tell_error(__MAKE_FOLDER__ERROR__, "GestionnaireDeFichierMT");
    
    if(chdir("GestionnaireDeFichierMT") != 0)
        tell_error(__FOLDER__OPENNING__ERROR__, "GestionnaireDeFichierMT");
}

void chdir_log(void) //go into APPDATA/LOCAL
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
        
    fwrite_log(f, __RESET__LOG__, file_name);

    fclose(f);
        
    f = NULL;
}


void fcopy(char *file_name, char *new_file_name)
{
    FILE *src;
    
    if((src = fopen(file_name, "rb")) == NULL) //check if src file existing
    {
        fprintf(stderr, "Erreur d'ouverture dans le fichier %s.", file_name);
        exit(EXIT_FAILURE);
    }

    FILE *dest;

    if( (dest = fopen(new_file_name, "wb")) == NULL) //check if dest file existing
    {
        fprintf(stderr, "Erreur d'ouverture dans le fichier pour sauvegarder le log");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];

    int ch;

    while( (ch = fread(buffer, 1, sizeof(buffer), src)) != 0) //copy
        fwrite(buffer, 1, ch, dest);

    fclose(src);
    fclose(dest);
    
    src = NULL;
    dest = NULL;

    free(new_file_name);
    new_file_name = NULL;

    freset_log(file_name); //reset src log
}

void check_log_size(char *file_name)
{
    struct stat info;

    if(stat(file_name, &info) != 0)
        tell_error(__FILE__OPENNING__ERROR__, file_name);

    if(info.st_size <= 1000000) //if log size > 1 Mo
        return;

    char *new_file_name = malloc(strlen(file_name) + strlen(".save") + 1); //make .save file
    
    if(new_file_name == NULL)
        tell_error(__ALLOCATION__ERROR__, NULL);
        
    strcpy(new_file_name, file_name);
    strcat(new_file_name, ".save");

    fcopy(file_name, new_file_name);
}

FILE *fopen_log(char *file_name, char *mod)
{
    chdir_log(); //go to APPDATA/LOCAL environnement

    open_log_dir(); //go to log program environnement

    FILE *f = fopen(file_name, mod); 

    if (f == NULL)
    {
        perror("Erreur Ouverture");
        exit(EXIT_FAILURE);
    }

    fwrite_log(f, __HOUR__LOG__, file_name);

    return f;
}

void log_info(char *file_name, char *mode, int info_code, char *__file__, int _line_, char *Str_)
{  
    char old_working_dir[MAX_PATH];     //save program environnement
    
    getcwd(old_working_dir, MAX_PATH);
    
    FILE *f = fopen_log(file_name, mode);

    if(f == NULL)
        tell_error(__FILE__OPENNING__ERROR__, file_name);

    current_execution_line(f, __file__, _line_);

    fwrite_log(f, info_code, Str_);

    check_log_size(file_name);

    if(chdir(old_working_dir) != 0)     //back to old environnement
        tell_error(__FOLDER__OPENNING__ERROR__, old_working_dir);

    if(f)
        fclose(f);
        
    return;
}