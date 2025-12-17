#ifndef __LOG__H__
#define __LOG__H__


#define __OPEN__LOG__STR__ "\nLog oppened at : "
#define __RESET__LOG__STR__ "\nFile's content reset"
#define __SUPPRESSED__STR__ " suppressed."
#define __MOVED__STR__ " moved"
#define __ACTION__STR__ "\nAction : "
#define __EXTENSION__STR__ "Remove by extension"
#define __FILE__STR__ "Remove by file name"
#define __CLEAR__STR__ "Clear folder"
#define __SORT__STR__ "Sort folder"
#define __FILE__DELETE__ERROR__STR__ "Failed to suppressed"
#define __ERROR__OCCURED__STR__ "\nAn error has occured"
#define __OPENING__ERROR__STR__ "\nFailed to open : "
#define __CHECK__IF__OPEN__STR "\nPlease check if this file/folder is already open in an other program"
#define __INVALID__OPTION__STR__ "\nInvalid program option"
#define __ARGUMENT__ERROR__STR__ "\nInvalid program argument"
#define __MEMORY__ALLOCATION__ERROR__STR__ "\nMemory allocation failed"
#define __PATH__LENGTH__ERROR__STR__ "\nPATH fully filled"
#define __FILE__MOVE__ERROR__STR__ "\nFailed to move "
#define __MAKE__FOLDER__ERROR__STR__ "\nFailed to create "
#define __FOLDER__DELETE__ERROR__STR__ "\nFailed to remove "
#define __GET__DIR__ERROR__STR__ "\nError while reading current directory"
#define __PRIVILEGE__ERROR__STR__ "\nAdmin privilege required"
#define __PROGRAM__LAUNCHED__STR__ "\nProgram launched succesfully"
#define __FOLDER__CLEAR__MODE__STR__ "Folder clear mode"
#define __FILE__SUPPRESSION__MODE__STR__ "File suppression mode"
#define __EXTENSION__SUPPRESSION__MODE__STR__ "Extension suppression mode"
#define __FOLDER__SORT__MODE__STR__ "Folder sort mode"
#define __FOLDER__EXTRACT__MODE__STR__ "Folder extract mod"
#define __MOVED__FILE__STR__ "File moved"
#define __ALLOCATION__ERROR__STR__ "Memory allocation error"

#define __INFO__LOG__ "INFO.log"
#define __FATAL__ERROR__LOG__ "FATAL_ERROR.log"


void log_info(char *file_name, char *mode, int info_code, char *_file_, int _line_, char *Str_);

#endif