//bitset.h
//Riešenie IJC-DU1, príklad a), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Hlavičkový súbor bitset.h definujúci makrá a inline funkcie
//Pozn.: Kontrolu medzí polí sa mi nepodarilo sfunkčniť 


#include <limits.h>
#include <assert.h>
#include <string.h>
#include <assert.h>
#include <error.h>

#define LONG_BITS (sizeof(unsigned long) * CHAR_BIT)


typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;



#define bitset_create(jmeno_pole, velikost)\
unsigned long jmeno_pole[velikost/LONG_BITS +2] = {velikost, 0}; \
static_assert(velikost>0, "Chyba velikosti pole")


#define bitset_alloc(jmeno_pole, velikost) \
jmeno_pole = calloc(((velikost + LONG_BITS -1) / LONG_BITS) + 1, sizeof(unsigned long)); jmeno_pole[0] = velikost;\
if (jmeno_pole == NULL) {fprintf(stderr, "bitset_alloc: Chyba alokace paměti"); assert(jmeno_pole == NULL);} 


#define bitset_free(jmeno_pole) \
free(jmeno_pole)


#ifndef USE_INLINE


#define bitset_size(jmeno_pole) \
(jmeno_pole[0])


#define bitset_setbit(jmeno_pole, index, vyraz) \
if(vyraz != 0) ((jmeno_pole[(index / LONG_BITS)+1]) |= (1UL << (index%LONG_BITS)));  \
else  (jmeno_pole[(index / LONG_BITS)+1]) &= ~(1UL << (index%LONG_BITS));   


#define bitset_getbit(jmeno_pole, index) \
((jmeno_pole[(index / LONG_BITS)+1] >> (index%LONG_BITS)) & 1UL)



#else


inline unsigned long bitset_size(bitset_t jmeno_pole)
{
    return jmeno_pole[0];
}


inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz) 
{
    if(vyraz != 0)
        (jmeno_pole[(index / LONG_BITS)+1]) |= (1UL << (index%LONG_BITS));
    else  
        (jmeno_pole[(index / LONG_BITS)+1]) &= ~(1UL << (index%LONG_BITS));  
}

inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
{
    return ((jmeno_pole[(index / LONG_BITS)+1] >> (index%LONG_BITS)) & 1UL);
}

#endif