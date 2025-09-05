#ifndef INSTALLER_H
#define INSTALLER_H

#include ".\..\..\include\include.h"

void errorr(char *msg);
int SETXPATH_LENGHT_GOOD(char *NewPath);
int vpath_setx(char *ProgramName, char *NewPath);
int make_bin_dir(char *NewPath);
int make_program_dir(char *ProgramName, char *NewPath);
int move_in_VPATH(char *ProgramName, char *ProgramPath, char *file_name);
void viderBuffer(void);

#endif