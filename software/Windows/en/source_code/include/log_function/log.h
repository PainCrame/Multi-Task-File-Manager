#ifndef __LOG__H__
#define __LOG__H__

#define __ERROR__ 1
#define __HOUR__ 2
#define __RESET__ 3
#define __SUPPRESSED__FILE__ 4
#define __EXTENSION__SUPPRESSION__MODE__ 5
#define __FILE__SUPPRESSION__MODE__ 6
#define __FOLDER__CLEAR__MODE__ 7
#define __FOLDER__SORT__MODE__ 8
#define __PROGRAM__LAUNCHED__ 9
#define __OPEN__LOG__STR__ "\nFile oppened at : "
#define __RESET__LOG__STR__ "\nFile's content reset"
#define __SUPPRESSED__STR__ " suppressed."
#define __ACTION__STR__ "\nAction : "
#define __EXTENSION__STR__ "Remove by extension"
#define __FILE__STR__ "Remove by file name"
#define __CLEAR__STR__ "Clear folder"
#define __SORT__STR__ "Sort folder"

void log_info(char *file_name, char *mode, int info_code);

#endif