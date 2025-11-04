#ifndef INCLUDE_H
#define INCLUDE_H

#include ".\different_process\different_process.h"
#include ".\color\color.h"
#include ".\string_function\string_function.h"
#include ".\other_function\other_function.h"
#include ".\trieur_function\trieur.h"
#include ".\argument\argument.h"
#include ".\extract\extract.h"
#include ".\privilege\privilege.h"
#include ".\log_function\log.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <sys/stat.h>
#include <time.h>

#define é 130
#define è 138
#define ê 136
#define ë 137
#define ç 135
#define à 133
#define ä 132
#define â 131
#define û 150
#define ù 151
#define î 206

#define __UPER_CASE__ -32
#define __LOWER_CASE__ -32
#define __FILE__OPENNING__ERROR__ 1
#define __INVALID__OPTIONN__ 2
#define __FOLDER__OPENNING__ERROR__ 3
#define __ARGUMENT__ERROR__ 4
#define __ALLOCATION__ERROR__ 5
#define __PATH__LENGTH__ERROR__ 6
#define __FILE__MOVE__ERROR__ 7
#define __MAKE_FOLDER__ERROR__ 8
#define __FILE__DELETE__ERROR__ 9
#define __FOLDER__DELETE__ERROR__ 10
#define __GET__DIR__ERROR__ 11
#define __PRIVILEGE__ERROR__ 12

#endif