#ifndef __factorization
#define __factorization
#include <vector>
using std::vector;

typedef vector<int> factrep;

factrep primfact(int n);
factrep mult(factrep f1, factrep f2);
factrep div(factrep f1, factrep f2);
double getval(factrep f);
vector<int> eratosthenes(int n);

extern vector<int> primes;

#endif