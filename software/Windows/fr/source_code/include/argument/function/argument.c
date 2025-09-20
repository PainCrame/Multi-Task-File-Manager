#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include ".\..\..\include.h"

// Fonction qui affiche le message d'aide
void display_help(void) {
    printf("Utilisation: gfmt [CHEMIN_VERS_LE_DOSSIER]...\n");
    printf("\nOptions:\n");
    printf("  -h, --help     Affiche de l'aide et quitte.\n");
    printf("  -v, --version  Affiche la version du programme et quitte.\n");
    exit(EXIT_SUCCESS); // Quitte le programme après l'affichage
}

void print_HelloWorld(void)
{
    printf("Hello, World !");
}

void print_version(void)
{
    printf("\nv2.0\n");
}

int check_option(int argc, char *argv[])
{

    if(argc<2)
    {
        tell_error(__ARGUMENT__ERROR__, NULL);
    }

    int opt;

    // Définition des options longues
    static struct option long_options[] = {
        {"help",    no_argument, 0,  'h' },
        {"version", no_argument, 0,  'v' },
        {"hello", no_argument, 0, 'i'},
        {0,         0,           0,  0 }
    };

    // La chaîne "hv" indique que -h et -v sont des options valides.
    // Les deux-points (:) après une lettre indiqueraient qu'elle attend un argument (ex: "f:").
    while ((opt = getopt_long(argc, argv, "hvi", long_options, NULL)) != -1) {
        switch (opt) {
            
            case 'h': // Cas pour -h ou --help
                display_help();
                exit(EXIT_SUCCESS);
                break;

            case 'v':
                print_version();
                exit(EXIT_SUCCESS);
                break;

            case 'i':
                print_HelloWorld();
                exit(EXIT_SUCCESS);
                break;
        }

    }
    
    return 0;
}