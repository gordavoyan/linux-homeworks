#include <iostream>
#include <vector>
#include "Complex.h"
#include "Sort.h"

int main() {
    std::vector<Complex> complexNumbers;

    complexNumbers.push_back(Complex(3, 4));
    complexNumbers.push_back(Complex(1, 2));
    complexNumbers.push_back(Complex(5, 1));
    complexNumbers.push_back(Complex(2, 3));

    for (int i = 0; i < complexNumbers.size(); ++i) {
        Complex c = complexNumbers[i];
        std::cout << c.getRealPart() << " + " << c.getImagPart() << "i, ";
    }
    std::cout << "\n";

    bubbleSort(complexNumbers);

    for (int i = 0; i < complexNumbers.size(); ++i) {
        Complex c = complexNumbers[i];
        std::cout << c.getRealPart() << " + " << c.getImagPart() << "i, ";
    }
    std::cout << "\n";

    return 0;
}