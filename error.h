//error.h
//Riešenie IJC-DU1, príklad b), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Deklarácia funkcií z modulu error.c


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);