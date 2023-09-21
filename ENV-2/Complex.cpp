#include "Complex.h"
#include <cmath>
#include <iostream>

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(double factor) const {
    return Complex(real * factor, imag * factor);
}

double Complex::abs() const {
    return sqrt(real * real + imag * imag);
}

double Complex::getRealPart() {
    return real;
}

double Complex::getImagPart() {
    return imag;
}