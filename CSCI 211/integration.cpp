#include <iostream>
using namespace std;

// Define a function pointer type FUNC that represents functions
// taking a double as input and returning a double
typedef double (*FUNC)(double);

// Function that represents f(x) = x
double line(double x) {
    return x;
}

// Function that represents f(x) = x^2
double square(double x) {
    return x * x;
}

// Function that represents f(x) = x^3
double cube(double x) {
    return x * x * x;
}

// Numerical integration function using the rectangular method
double integrate(FUNC f, double a, double b) {
    double sum = 0, x = a;         
    double dx = 0.000001;     
    while (x < b) { 
        sum += f(x) * dx;  
        x += dx; 
    }
    return sum; // Return the final integral value
}

int main() {
    cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
    cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;
}
