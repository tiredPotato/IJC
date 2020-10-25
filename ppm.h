//ppm.h
//Riešenie IJC-DU1, príklad b), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Hlavičkový súbor pre ppm.c, obsahuje štruktúru ppm a deklaráciu funkcie na čítanie štruktúry zo súboru
//a uvoľnenie alokovanej štruktúry


struct ppm {
        unsigned xsize;
        unsigned ysize;
        char data[];    // RGB bajty, celkem 3*xsize*ysize
     };

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);