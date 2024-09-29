// Tavishka Arora TA24435 tavishka
#include <iostream>
#include <ranges>
#include <numeric>
#include <vector>

int main() {
  //lambda to compute the sum of divisors of a number
  auto sumDivisors = [](int n) {
      
    //use iota to generate numbers from 1 to n-1 as those are the numbers we check to see if they divide n
    //uses a filter of % to only gather divisors of n
    //returns the sum
    
    int sum =0;
    for (int i : std::views::iota(1, n) | std::views::filter([n](int i) { return n % i == 0; })) {
        sum += i;
        }
    return sum;
    };

    //lambda to check if a number is perfect
    auto perfect = [&sumDivisors](int n) {
        return sumDivisors(n) == n;
    };

    //loop generates numbers starting from 2 and finds the perfect numbers
    int count = 0;
    for (int n : std::views::iota(2)) {
        if (perfect(n)) {
            std::cout << n << std::endl;
            count++;
        }
        //breaks the loop after finding the first 4 perfect numbers
        if (count == 4) break;
    }

    return 0;
}
