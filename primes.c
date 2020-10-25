//primes.c
//Riešenie IJC-DU1, príklad a), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Zdrojový súbor primes.c vypíše posledných 10 prvočísel od 2 do 500000000 vzostupne

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "eratosthenes.h"


#define VELKOST 500000000

int main()
{
    //clock_t = start;
    //start = clock();

    bitset_create(b, VELKOST);

    Eratosthenes(b);

    int index = 0;
    unsigned long primes[10] = {0};

    for(int i = VELKOST; index < 10; --i)
    {
        if((bitset_getbit(b, i)) == 0)
        {
            primes[index] = i;
            index++;
        }
    }

    for(int i = 9; i >= 0; --i)
        printf("%ld\n", primes[i]);

    //fprintf("Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}