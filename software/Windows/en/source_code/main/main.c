#include "..\include\include.h"

int main(int argc, char *argv[])
{
    DIR *d;
    if(!(argc == 2 && (d = opendir(argv[1]))))
    {
        printf("%d", argc);
        printf("\nUse command like : mtfm <path_of_the_folder_you_want_to_clean>.\nFor example : \"mtfm C:\\User\\Dekstop\\Downloads\"");
        getchar();
        exit(EXIT_FAILURE);
    }
    closedir(d);

    int c = chdir(argv[1]);
    if(! c==0)
    {
        perror("Error in opening the folder, please try again\nError ");
        getchar();
        exit(EXIT_FAILURE);
    }

    
    while(1)
    {
        int instruction;
        char buffer[PATH_MAX];

        printf("\nWelcome to the uninstaller program!\n");
        printf("\nYou're in the folder : %s\n(CTRL+C if you want to exit)\n", getcwd(buffer, PATH_MAX));
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
                clear_folder();

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