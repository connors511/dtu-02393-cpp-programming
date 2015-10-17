#include "fraction.h"

fraction::fraction(int n) {
    frac = primfact(n);
}

fraction::fraction(int n, int m) {
    // Should m be represented as negative entries in a
    // combined vector for n and m, and n be the positive entries?
    // this will only be possible in a reduced fraction form
    // so that n and m share no common primes
    frac = primfact(n);
}

// Add a fraction
void fraction::add(const fraction & f) {
    // – First compute the enumerators e1, e2, and denominators d1, d2 of
    // both involved fractions.
    fraction e1 = this->getenum();
    fraction d1 = this->getdenom();
    fraction e2 = f.getenum();
    fraction d2 = f.getdenom();
    // – Compute e1 ∗ d2 and e2 ∗ d1.
    e1.mult(d2);
    e2.mult(d1);
    // – Next, add these two. To that end, before the addition you need to
    // use getval and after the addition you need to make them a fraction
    // again.
    frac = primfact(e1.getval() + e2.getval());
    // – Finally divide the result by d1 and by d2.
    this->div(d1);
    this->div(d2);
}

// Multiply by a fraction
void fraction::mult(const fraction & f) {
    const factrep &f2 = frac;
    frac = frmult(f2, f.frac);
}

// Divide by a fraction
void fraction::div(const fraction & f) {
    const factrep &f2 = frac;
    frac = frdiv(f2, f.frac);
}

// Get the fraction as double
double fraction::getval() const {
    return frgetval(frac);
}

// Get the enumerator (as fraction)
fraction fraction::getenum() const {
    return fraction(1);
}

// Get denominator (as fraction)
fraction fraction::getdenom() const {
    return fraction(1);
}