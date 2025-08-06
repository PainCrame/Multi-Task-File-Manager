#include <stdio.h>
#include <stdlib.h>
#include "folder_uninstaller_process.h"
#include "file_uninstaller_process.h"
#include "extension_uninstaller_process.h"

#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */

int main(void)
{
    int instruction;

    printf("\nWelcome to the uninstaller program!\n");
    printf("\nDo you want to : "BLUE "DELETE SPECIFICS FILES (0)"RESET" or "BLUE"CLEAR THE FOLDER (1) : "RESET);
    scanf("%d", &instruction);
    
    if(instruction == 1)
    {
        printf(RED"WARNING"RESET": Are you sure ? The entire folder will be delete. " BLUE "CONTINUE (0)" RESET " or" BLUE " RETURN (1)"RESET " : ");
        scanf("%d", &instruction);

        if(instruction==0)
            clear_folder();
        else{
            main();
            return 1;
        }
        return 1;
    }
    else if(instruction == 0){
        instruction = 3;

        printf("\nDo you want uninstall files by :"BLUE" NAMES (0)"RESET" or"BLUE" EXTENSION (1)"RESET" : ");
        scanf("%d", &instruction);

        if(instruction == 0)
        {
            
            process_uninstall_file();
        }
        else if(instruction == 1)
        {
            uninstall_extension();
        }
        else
        {
            printf( "\nInvalid option. Please try again.\n");
            system("PAUSE");
            return 1;
        }
    }
    else{
        printf( "\nInvalid option. Please try again.\n");
        system("PAUSE");
        return 1;
    }

    return 0;
}