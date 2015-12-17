#ifndef __factorization
#define __factorization

//every time we use factrep it'll actually be int*
typedef int * factrep;

factrep new_factrep();
factrep primfact(int n);
factrep mult(factrep f1, factrep f2);
int getint(factrep f);

// we declare that we'll define these in another file.
extern int *primes;
extern int len;

#endif