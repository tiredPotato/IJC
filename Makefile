#
# Makefile pre DU1 z IJC
# Adriana Jurkechová, FIT VUT Brno
# Dátum: 16.3.2020
#

CFLAGS = -std=c11 -Wall -pedantic -Wextra -g -lm -O0

all: primes primes-i steg-decode



primes: primes.o eratosthenes.o error.o
	gcc $(CFLAGS) primes.o eratosthenes.o error.o -o primes -lm

primes.o: primes.c bitset.h
	gcc $(CFLAGS) -c primes.c -o primes.o -lm

eratosthenes.o: eratosthenes.c bitset.h
	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o -lm

error.o: error.c error.h
	gcc $(CFLAGS) -c error.c -o error.o




bitset-i.o: bitset.h bitset.c
	gcc $(CFLAGS) -c -DUSE_INLINE bitset.c -o bitset-i.o


primes-i: primes-i.o eratosthenes-i.o error.o bitset-i.o
	gcc $(CFLAGS) -DUSE_INLINE primes-i.o eratosthenes-i.o error.o bitset-i.o -o primes-i -lm

primes-i.o: primes.c bitset.h bitset.c
	gcc $(CFLAGS) -c -DUSE_INLINE primes.c -o primes-i.o

eratosthenes-i.o: eratosthenes.c bitset.h bitset.c
	gcc $(CFLAGS) -c -DUSE_INLINE eratosthenes.c -o eratosthenes-i.o




steg-decode: steg-decode.o eratosthenes.o error.o ppm.o
	gcc $(CFLAGS) steg-decode.o eratosthenes.o error.o ppm.o -o steg-decode

steg-decode.o: steg-decode.c bitset.h error.h ppm.h
	gcc $(CFLAGS) -c steg-decode.c -o steg-decode.o

ppm.o: ppm.c error.h ppm.h
	gcc $(CFLAGS) -c ppm.c -o ppm.o



.PHONY: all primes clean


clean:
	rm primes primes-i steg-decode *.o

run:
	ulimit -s 65000 && ./primes
	ulimit -s 65000 && ./primes-i
