#include "fact.h"
#include<iostream>
#include<math.h>
using namespace std;
 
factrep div(factrep f1, factrep f2) {
    int i, len = max(f1.size(), f2.size());
    factrep arr_div(len);
    for (i = 0; i < len; i++) {
        if (i >= f1.size()) {
            arr_div[i] = -f2[i];
        } else if (i > f2.size()) {
            arr_div[i] = f1[i];
        } else {
            arr_div[i] = f1[i] - f2[i];
        }
    }
 
    return arr_div;
 
}
 
factrep mult(factrep f1, factrep f2) {
    int i, len = max(f1.size(), f2.size());
    factrep arr_mult(len);
    for (i = 0; i < len; i++) {
        if (i >= f1.size()) {
            arr_mult[i] = f2[i];
        } else if (i > f2.size()) {
            arr_mult[i] = f1[i];
        } else {
            arr_mult[i] = f1[i] + f2[i];
        }
    }
 
    return arr_mult;
 
}
 
vector<int> eratosthenes(int n) {
    // computes all prime numbers up to n
    // returns the prime numbers as an array
    // the len parameter will be set to the length of the array
    vector<bool> isPrime(n+1); // construct [n+1] booleans
 
    int len=0;
    // initialize every value from 2..n to true.
    for(int i=2; i<=n; i++){
        isPrime[i]=true;
    }
    // now we'll start at 2, and for every number of multiplicity 2.
    // e.g. 2*{1,2,3,4...n} is then set to false, as they are dividable by 2.
    // then we increment to 3, during the same.
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            len++; // for each such iteration, we increase our desired length.
            for(int j=2*i; j<=n; j+=i){
                isPrime[j]=false; // set every(n) multiplicity of 2 to false.
            }
        }
    }
    // having used erathosthenes formula, we now construct our array.
    vector<int> result(len);
    // now we need to return the primes-filled array.
    for(int i=0, j=2; i<len; i++){
        // if it's not a prime, then we spin the value up.
        while(!isPrime[j]) j++;
        // when the while-loop no longer hold, we'll have the iterations desired prime
        // we then set it, and the for-loop will continue to the next.
        result[i]=j++;
    }
 
    return result;
}
 
bool isPrime(int n) {
    int i;
 
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
 
    return true;
}
 
factrep primfact(int n) {
    int i, count = -1;
    factrep arr_primes(n + 1);
    for (i = 2; i <= n; i++) {
        if (isPrime(i)) {
            count++;
            while (n % i == 0) {
                n /= i;
                arr_primes[count]++;
            }
        }
    }
 
    return arr_primes;
}
 
 
double getval(factrep f) {
    double sum = 1.0;
    int i, len = f.size();
    for (i = 0; i < len; i++) {
        if (f[i] != 0) {
            sum *= pow(primes[i], f[i]);
        }
    }
 
    return sum;
}