#include "fact.h"
  
factrep new_factrep() {
    int i;
    factrep arr = new int[len];
    for (i = 0; i < len; i++) {
        arr[i] = 0;
    }
    return arr;
}
  
factrep primfact(int n) {
    int i;
    factrep arr_primes = new_factrep();
    for (i = 2; i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            arr_primes[i]++;
        }
    }
  
    return arr_primes;
}
  
factrep mult(factrep f1, factrep f2) {
    int i;
    factrep arr_mult = new_factrep();
    for (i = 0; i < len; i++) {
        arr_mult[i] = f1[i] + f2[i];
    }
  
    return arr_mult;
}
  
int getint(factrep f) {
    int sum = 1, i, j;
    for (i = 0; i < len; i++) {
        if (f[i] > 0) {
            for (j = 0; j < f[i]; j++) {
                sum *= i;
            }
        }
    }
  
    return sum;
}