#include "fact.h"
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;

void build_prime_numbers(int n){
    vector<bool> isPrime(n+1);
    
    // Apply the sieve of Eratosthenes
    // http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    // computes all prime numbers up to n
    
    for(int i=2; i<=n; i++)
        isPrime[i]=true;
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=2*i; j<=n; j+=i)
                isPrime[j]=false;
        }
    }
    
}

factrep primfact(int n){
    factrep a;
    
    // create the prime numbers vector if not yet done
    if (primes.size()==0) {
        // We first build a sufficiently large set of prime numbers
        build_prime_numbers(sqrt(INT_MAX));
    }
    
    int m; // still to factorize number
    
    m=n;
    
    // continue until nothing to factorize
    for(int i=0; m!=1 && i<primes.size(); i++){
        a.push_back(0);
        // while the factor divides m, go on
        while(m % primes[i] == 0){
            m=m/primes[i];
            a[i]++;
        }
    }

    return a;
}

factrep frmult(const factrep & f1, const factrep & f2){
    factrep a(fmax(f1.size(),f2.size()));
    
    for(int i=0; i<a.size(); i++){
        a[i]=(i<f1.size()?f1[i]:0)+(i<f2.size()?f2[i]:0);
    }
    
    return a;
}

factrep frdiv(const factrep & f1, const factrep & f2){
    factrep a(fmax(f1.size(),f2.size()));
    
    for(int i=0; i<a.size(); i++){
        a[i]=(i<f1.size()?f1[i]:0)-(i<f2.size()?f2[i]:0);
    }
    
    return a;
}

double frgetval(const factrep & f){
    double r;
        
    r=1.0;
    for (int i=0; i<f.size() && i<primes.size(); i++){
        r *= pow(primes[i],f[i]);
    }
    
    return r;
}



