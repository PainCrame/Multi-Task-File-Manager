#include <stdio.h>
#include <stdlib.h>
#include "folder_uninstaller_process.h"
#include "file_uninstaller_process.h"
#include "extension_uninstaller_process.h"
#include "all_function.h"
#include <string.h>

#define RED     "\033[31m"
#define RESET   "\033[0m"
#define BLUE    "\033[34m"

int main(int argc, char *argv[])
{
    while(1)
    {
        int instruction;

        printf("\nWelcome to the uninstaller program!\n");
        printf("\nDo you want to : "BLUE "DELETE SPECIFICS FILES (0)"RESET" or "BLUE"CLEAR THE FOLDER (1) : "RESET);
        scanf("%d", &instruction);
        viderBuffer();
        
        if(instruction == 1)
        {
            printf(RED"WARNING"RESET": Are you sure ? The entire folder will be delete (excepting folders). " BLUE "CONTINUE (0)" RESET " or" BLUE " RETURN (1)"RESET " : ");
            scanf("%d", &instruction);
            viderBuffer();

            if(instruction==0)
            {  
                clear_folder(argv[0]);

            }else if( instruction == 1){

                continue;
                
            }else{
                error(2, NULL);
            }
            return 1;
        }
        else if(instruction == 0){
            instruction = 3;

            printf("\nDo you want uninstall files by :"BLUE" NAMES (0)"RESET" or"BLUE" EXTENSION (1)"RESET" : ");
            scanf("%d", &instruction);
            viderBuffer();

            if(instruction == 0)
            {
                process_uninstall_file();
            }
            else if(instruction == 1)
            {
                uninstall_extension(argv[0]);
            }
            else
            {
                error(2, NULL);
            }
        }
        else{
            error(2, NULL);
        }
    }

    return 0;
}