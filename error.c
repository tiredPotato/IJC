//error.c
//Riešenie IJC-DU1, príklad b), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Definície fukcií podobných printf


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "error.h"

void warning_msg(const char *fmt, ...) 
{
    fprintf(stderr, "CHYBA: ");
    va_list argument;
    va_start(argument, fmt);
    vfprintf(stderr, fmt, argument);
    va_end(argument);
}

void error_exit(const char *fmt, ...)
{
    fprintf(stderr, "CHYBA: ");
    va_list argument;
    va_start(argument, fmt);
    vfprintf(stderr, fmt, argument);
    va_end(argument);

    exit(1);
}