#ifndef __fraction
#define __fraction
#include <vector>
#include "fact.h"
using std::vector;

class fraction{
private:
    // Internal representation of a fraction (as a vector of factors)
    factrep frac;
public:
    // Class constructors
    fraction(int n);                // Construct a fraction for n
    fraction(int n, int m);         // Construct a fraction for n/m
    
    // Methods update the fraction
    void add(const fraction & f);   // Add a fraction
    void mult(const fraction & f);  // Multiply by a fraction
    void div(const fraction & f);   // Divide by a fraction
    
    // Methods to extract values from the fraction
    double getval() const;          // Get the fraction as double
    fraction getenum() const;       // Get the enumerator (as fraction)
    fraction getdenom() const;      // Get denominator (as fraction)
};

#endif
