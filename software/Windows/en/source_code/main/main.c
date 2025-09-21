#include "..\include\include.h"

int main(int argc, char *argv[])
{

    check_option(argc, argv);

    DIR *d;

        if((d = opendir(argv[1])) == NULL)
    {
        perror("\nFolder does not exist or is inaccessible\nERROR : ");
        getchar();
        exit(EXIT_FAILURE);
    }

    if(chdir(argv[1]) != 0)
    {
        tell_error(__FOLDER__OPENNING__ERROR__, NULL);
    }

    printf("\nWelcome to the uninstaller program!\n");
    
    while(1)
    {
        int instruction;
        char buffer[PATH_MAX];

        printf("\nYou're in the folder : %s\n(CTRL+C if you want to exit)\n", getcwd(buffer, PATH_MAX));    
        printf("\nWould you like to : "BLUE "DELETE SPECIFICS FILES (0)"RESET" or "BLUE"CLEAR THE FOLDER (1) "RESET" or "BLUE"SORT THE FOLDER (2) : "RESET);
        scanf("%d", &instruction);
        viderBuffer();
        
        if(instruction == 1)
        {
            printf(RED"WARNING"RESET": Are you sure ? The entire folder will be delete (excepting folders). " BLUE "CONTINUE (0)" RESET " or" BLUE " RETURN (1)"RESET " : ");
            scanf("%d", &instruction);
            viderBuffer();

            if(instruction==0)
            {  
                clear_folder();

            }else if( instruction == 1){

                continue;
                
            }else{
                tell_error(__INVALID__OPTIONN__, NULL);
            }
            return 1;
        }

        else if(instruction == 0)
        {
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
                tell_error(__INVALID__OPTIONN__, NULL);
            }
        }

        else if(instruction == 2)
        {
            instruction = 3;

            trier();

            printf("\nThe file has been sorted correctly.");
        }

        else
        {
            tell_error(__INVALID__OPTIONN__, NULL);
        }
    }

    return 0;
}