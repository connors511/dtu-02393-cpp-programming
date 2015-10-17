#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
 
#include "fact.h"
 
vector<int> primes;
int main() {
 
        primes = eratosthenes(71);      
        // cout << "The prime numbers are:\n";
        // for(unsigned i = 0; i != myprimes.size(); i++) 
            // cout << primes[i] << '\n';
             
        int num;
        cin>>num;
        //[] = {1, 17, 54, 10, 36, 63, 20, 25};
        factrep f;
         
        f = primfact(num);
         
         
        cout << '\n' << num << " is factorized as:\nPrime     Exponent\n";
            bool agree = true;
            for(unsigned j = f.size(); j < f.size(); j++) {
                if(f[j] != 0) {
                    agree = false;
                    }
            }
            for(unsigned j = 0; j != min(f.size(), f.size()); j++) {
                if(f[j] != 0) {
                    cout << primes[j] << "     " << f[j] << '\n';
                }
            }
            if(!agree) {
                for(unsigned j = f.size(); j != f.size(); j++) {
                if(f[j] != 0) {
                    cout << primes[j] << "     " << f[j] << '\n';
                } 
                }
            }
 
         
            cout << "getval of " << num << " is " << getval(f) << "\n";
            factrep xx=primfact(7);     
            factrep res = mult(f, xx);
            cout << num << " multiplied by 7" << " is " << getval(res) << "\n";
             res = div(f, xx);
            cout << num << " divided by 7" << " is " << getval(res) << "\n";
 
 
}