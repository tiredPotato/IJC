//ppm.c
//Riešenie IJC-DU1, príklad b), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Zdrojový súbor ppm.c, v ktorom sú definované funkcie na čítanie štruktúry zo súboru
//a uvolnenie štruktúry

#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "ppm.h"


struct ppm * ppm_read(const char * filename)
{
    FILE *subor = fopen(filename, "r");
    if (subor == NULL)
    {
        warning_msg("Subor sa nepodarilo otvoriť.\n");
        return NULL;
    }


    unsigned long xSize;
    unsigned long ySize;
    int farba;

    if(fscanf(subor, "P6 %lu %lu %d%*c", &xSize, &ySize, &farba) != 3 || farba !=255)
    {
        warning_msg("Chybný formát súboru.\n");
        fclose(subor);
        return NULL;
    }

    struct ppm * obrazok = (struct ppm*)malloc(3*xSize*ySize + sizeof(struct ppm));
    if(obrazok == NULL)
    {
        warning_msg("Zlyhala alokácia pamäte.\n");
        fclose(subor);
        return NULL;
    }

    obrazok->xsize = xSize;
    obrazok->ysize = ySize;

    size_t nacitane = fread(obrazok->data, 1, 3*xSize*ySize, subor);
    if(nacitane < 3*xSize*ySize)
    {
        fclose(subor);
        ppm_free(obrazok);
        return NULL;
    }


    fclose(subor);

    return obrazok;       
}



void ppm_free(struct ppm *p)
{
    free(p);
}
