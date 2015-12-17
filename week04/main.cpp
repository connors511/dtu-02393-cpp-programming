#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

#include "fact.h"


/** eartosthenes constructs an up-to-n primes array of length len .
* @param n			call-by-value, top value for construction of primes.
* @param &len		call-by-reference, the finished size of the array of primes.
* @return int*		pointer to the first element of the array of primes.
* Description:
* The eartosthenes method of calculating primes are efficient for relative low primes (up to 10 million or so).
*/ 
int * eratosthenes(int n, int & len){
	// computes all prime numbers up to n 
	// returns the prime numbers as an array 
	// the len parameter will be set to the length of the array
	bool *isPrime=new bool [n+1]; // construct [n+1] booleans
	len=0;
	// initialize every value from 1..n to true.
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
	int *result=new int[len];
	// now we need to return the primes-filled array.
	for(int i=0, j=2; i<len; i++){
		// if it's not a prime, then we spin the value up.
		while(!isPrime[j]) j++;
		// when the while-loop no longer hold, we'll have the iterations desired prime
		// we then set it, and the for-loop will continue to the next.
		result[i]=j++;  
	}
	
	delete [] isPrime; 	// always delete what you have allocated with new.
						// we say these allocation are on the heap or free store (c-syntax)
	return result;
}

// these are our global variables
// so in our header we called extern
// which basically tells c++, that we'll define them in another file.
int *primes;
int len;

int main(){
	// construct our primes array with maximum integer value
	primes=eratosthenes(sqrt(INT_MAX),len);
	// len now contains the length of the primes.
	
	// TEST VALUES
	// these are our test values.
	int n=60;
	int m=25;
	int l=640;
	
	// first check for non-negative content
	if ( n < 0 || m < 0 || l < 0){
		cout << "values must be positive (n > 0)" << endl;
		return 1;
	}
	
	// construct 3 prime-factorized arrays by the values (60,25,640)
	factrep fn=primfact(n);
	factrep fm=primfact(m);
	factrep fl=primfact(l);
    
	// Verify that these are indeed constructed with those values
	cout << getint(fn) << " " << getint(fm) << " " << getint(fl) << endl;
	
	// multiply: 	fn = fn*fm, fm = fl*fl, fl = fn*fm
	// 1500 = 60*25, 409600 = 640*640, 614400000 = 1500*409600
	fn=mult(fn,fm);
	fm=mult(fl,fl);
	fl=mult(fn,fm);
	
	// Verify that our functions work as expected by printing out their values now.
	cout << getint(fn) << " " << getint(fm) << " " << getint(fl) << endl;

	/* Expected output:
		60 25 640
		1500 409600 614400000
	*/
	
	// and again, if we construct something on the heap/free-store we better delete it again
	// otherwise we might have a memory-leak on our hands.
	delete [] primes;
	delete [] fn;
	delete [] fm;
	delete [] fl;
	return 0;
}
