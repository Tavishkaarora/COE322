#include <iostream>
#include <functional>
using std::cout;
using std::function;

//Newton's method function for finding roots
double newton_root(function<double(double)> f) {
    //intialize xi to starting guess
    double xi = 10.0;
    //"y" value of xi
    double fxi = f(xi);

    // Iterate to find the root
    for (int count = 0;; ++count) {
        //newton method applied
        //derivative of x^2 is 2x
        xi -= f(xi) / (2 * xi);
        fxi = f(xi);

        //breaks the loop when root is found/within set tolerance
        if (std::abs(fxi) < 1.e-5) {
            break;
        }
    }
    return xi;
}

int main() {
    //test case
    for (int n = 2; n < 8; ++n) {
        //define lambda function of n
        cout << "Sqrt(" << n << ") = "
            //lambda function    
             << newton_root([n](double x) { return x * x - n; })
             << '\n';
    }

    return 0;
}
