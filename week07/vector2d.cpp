#include "vector2d.h"
#include <math.h>
  
v2d::v2d(double a, double b) {
    x = a;
    y = b;
}
  
// destructor
v2d::~v2d() {
  
}
  
// copy constructor
// builds a vector that is exactly as v
v2d::v2d(const v2d & v) {
    x = v.x;
    y = v.y;
}
  
// assignment
v2d & v2d::operator=(const v2d &v) {
    this->x = v.x;
    this->y = v.y;
    return *this;
}
  
// vector addition
v2d & v2d::operator+(const v2d &v) {
    this->x += v.x;
    this->y += v.y;
    return *this;
}
  
// direct product
double v2d::operator*(const v2d &v) {
    return (this->x * v.x) + (this->y * v.y);
}
  
// scalar multiplication
v2d & v2d::operator*(double k) {
    this->x *= k;
    this->y *= k;
  
    return *this;
  
}
  
// length
double v2d::length() {
    return sqrt(*this * *this);
}