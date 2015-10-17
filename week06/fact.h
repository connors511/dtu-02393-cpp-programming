#ifndef __factorization
#define __factorization
#include <vector>
using std::vector;

typedef vector<int> factrep;

// vector of prime numbers asglobal variable
// to be "created" by invoking "build_prime_numbers"
static vector<int> primes;
void build_prime_numbers(int n);

// Warnings
// (1) these functions require that you first build the primes vector
// (2) these functions will work as expected for numbers who can be
//     factorized using at most the first n primes, where n is the
//     desired prime vector size

factrep primfact(int n);
factrep frmult(const factrep & f1, const factrep & f2);
factrep frdiv(const factrep & f1, const factrep & f2);
double frgetval(const factrep & f);

#endif
