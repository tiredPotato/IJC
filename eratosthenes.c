//eratosthenes.c
//Riešenie IJC-DU1, príklad a), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Zdrojový súbor eratosthenes.c, definuje funkciu využívajúcu algoritmus Eratostenovo sito


#include "bitset.h"
#include <math.h>
#include <stdio.h>


void Eratosthenes(bitset_t pole)
{
    unsigned long velkost = bitset_size(pole);

    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);

    unsigned long odmocnina = sqrt(velkost);

    for(bitset_index_t i = 2; i <= odmocnina; i++) 
    {
        if(!bitset_getbit(pole, i))
            for(int j = i; j*i <= velkost; j++) {
                bitset_setbit(pole, j*i, 1);
            }    
    }

}
