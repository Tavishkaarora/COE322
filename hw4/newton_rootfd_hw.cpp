//Tavishka Arora TA24435 tavishka
#include <iostream>
#include <functional>
#include <cmath>

//using constant doubles for the following so the value cannot later be changed as these r inherent aspects of the method
const double h = 1e-6;
//set error tolerance for root
const double tolerance = 1e-10;
//just in case there is an infinite loop
const int max_it = 1000;

//Newton method root finder
double newton_root(std::function<double(double)> f) {
    //lambda function for the derivativeusing finite difference
    auto derivF = [&](double x) {
        return (f(x + h) - f(x)) / h;
    };

    //sets starting guess for the root
    double x0 = 1.0;
    //loop for newton method usinf f-d
    for (int i = 0; i < max_it; ++i) {
        double fx = f(x0);
        double dfx = derivF(x0);

        //just in case there is division by zero if the derivative is too small
        if (std::abs(dfx) < tolerance) {
            break;
        }
        //applies Newton Method
        double x1 = x0 - fx / dfx;

        //checks if the answer is within the error tolerance
        if (std::abs(x1 - x0) < tolerance) {
            return x1;
        }
        //updates guess for next round
        x0 = x1;
    }
    //gives a console error if a conclusion was not able to be reached by the method.
    std::cerr << "Error: The maximum number of iterations was reached without convergence. This is the best possible guess: " << std::endl;
    //returns the best guess after the maximum number of iterations
    return x0; 
}

int main() {
  double inNumber;
    
    //user input
    std::cout << "Enter a number: ";
    std::cin >> inNumber;

    //define the lambda function being used for root
    auto f = [inNumber](double x) {
        return x * x - inNumber;
    };

    //finds the root as per assignment instructions
    double rootAnswer = newton_root(f);

    //prints the answer
    std::cout << "The root of " << inNumber << " is " << rootAnswer << std::endl;

    //ends the main
    return 0;
}
