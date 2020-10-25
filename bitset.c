//bitset.h
//Riešenie IJC-DU1, príklad a), 12.3.2020
//Autor: Adriana Jurkechová, FIT
//Preložené: gcc (Debian 8.3.0-6) 8.3.0
//Modul pre externé definície inline funkcií


#include "bitset.h"

#ifdef USE_INLINE

extern inline unsigned long bitset_size(bitset_t jmeno_pole);

extern inline void bitset_setbit (bitset_t jmeno_pole, bitset_index_t index, int vyraz);

extern inline unsigned long bitset_getbit (bitset_t jmeno_pole, bitset_index_t index);

#endif