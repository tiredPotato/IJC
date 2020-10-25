//steg-decode.c
//Riešenie IJC-DU1, príklad b), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Zdrojový súbor steg-decode.c využívaný pri dekódovaní správy z formátu PPM

#include <stdio.h>
#include <stdlib.h>
#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"
#include "ppm.h"


#define LIMIT 3*8000*8000

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        warning_msg("Argumentom má byť iba obrázok vo formáte PPM.\n");
        return 42;
    }

    struct ppm *obrazok = ppm_read(argv[1]);

    unsigned long velkost = LIMIT;
    bitset_t sprava;
    bitset_alloc(sprava, velkost);

    Eratosthenes(sprava);

    char znak[2] = {'\0'};
    unsigned int poradie_bitu = 0;

    for(bitset_index_t index = 23; index < bitset_size(sprava); index++)
    {
        if(bitset_getbit(sprava, index) == 0)
        {
            bitset_setbit(znak, poradie_bitu, (obrazok->data[index] & 1));
            poradie_bitu++;
        

            if((poradie_bitu%8) == 0 && znak[1] == '\0')
            {
                printf("\n");
                break;
            }
            else if((poradie_bitu%8) == 0)
            {
                printf("%c", znak[1]);
                poradie_bitu = 0;
            }
        }
    }
    ppm_free(obrazok);
    bitset_free(sprava);
    return 0;
}