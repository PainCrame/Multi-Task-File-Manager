#ifndef __EXTRACT__H__
#define __EXTRACT__H__

char *get_file_name(char *file_name);
int file_already_exist(char *file_name);
char *add_letter_to_name(char *file_name);
char *get_file_name_in_back(char *file_name, char *file_name_with_letter);
char *change_name(char *file_name);
void print_current_dir(void);
void move_file_back(char *file_name);
int remove_folder(char *folder);
void scan_folder(char *folder);
void extract_files(char *folder);
void extract_main_folder();

#endif