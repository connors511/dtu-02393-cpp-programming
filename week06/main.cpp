// This file is an example (and test) for the class
// of fractions to be developed

#include<iostream>
#include<cmath>
#include<climits>
#include "fraction.h"
using namespace std;

int main(){
    
    // We will ues some numbers
    int n1=1, m1=3;
    int n2=1,m2=4;
    
    // We  start with a simple test:
    // Building fractions for the above numbers
    fraction n(n1);
    fraction m(m1);
    fraction n11(n2);
    fraction m11(m2);
    
    // We can now see if constructors and getval
    // work as expected
    cout << n1 << " is " << n.getval() << endl;
    cout << m1 << " is " << m.getval() << endl;
    cout << n2 << " is " << n11.getval() << endl;
    cout << m2 << " is " << m11.getval() << endl;
    
    // We now construct some fractions using the second constructor
    // We shall use them later for testing multiplication of fractions
    fraction l(n1,m1);
    fraction l1(n2,m2);
    // And check that we get the expected result
    cout<<"the first fraction is "<<(l.getenum().getval())
    <<"/"<<(l.getdenom().getval())<<endl;
    cout<<"the second fraction is "<<(l1.getenum().getval()) <<"/"<<(l1.getdenom().getval())<<endl;
    l.mult(l1);
    cout<<n1<<"/"<<m1<<" * "<<(l1.getenum().getval()) <<"/"<<(l1.getdenom().getval())<<" = "<<(l.getenum().getval()) <<"/"<<(l.getdenom().getval())<<endl;
    
    // We now construct further fractions
    // We shall use them later for testing division of fractions
    fraction ld(n1,m1);
    fraction ld1(n2,m2);
    ld.div(ld1);
    // Again we check that fractions are built as expected
    cout <<n1 <<"/"<< m1 << " / " <<(ld1.getenum().getval()) <<"/"<<(ld1.getdenom().getval())<<" = " <<(ld.getenum().getval()) <<"/"<<( ld.getdenom().getval()) << endl;
    
    // We build a last set of fractions
    // We shall use them later for testing addition of fractions
    fraction ad1(n1,m1);
    fraction ad2(n2,m2);
    ad1.add(ad2);
    cout << n1 <<"/"<< m1 << " + " << (ad2.getenum()).getval() <<"/"<< (ad2.getdenom()).getval() << " = " <<(ad1.getenum().getval()) <<"/"<<( ad1.getdenom().getval()) << endl;
    
    /* Expected output:
     1 is 1
     3 is 3
     1 is 1
     4 is 4
     the first fraction is 1/3
     the second fraction is 1/4
     1/3 * 1/4 = 1/12
     1/3 / 1/4 = 4/3
     1/3 + 1/4 = 7/12
     */
    
}

