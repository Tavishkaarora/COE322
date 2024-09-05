
// name: Tavishka Arora UTEID: ta24435 tacc user: tavishka
#include <iostream>

<<<<<<< HEAD
//function to read user input number
int read_number() {
  int x;
  std::cout << "Enter a number: ";
  //stores number in variable x
  std::cin >> x;
  return x;
}

int main() {
  //read the number from user input
  int xNum = read_number();

  //determine FizzBuzz, Fizz, or buzz, based on entered number
  //divisible by 3 & 5
  if (xNum % 3 == 0 && xNum % 5 == 0) {
    std::cout << "FizzBuzz\n";
  }
  //divisible by only 3
  else if (xNum % 3 == 0) {
    std::cout << "Fizz\n";
  }
  //divisible by only 5
  else if (xNum % 5 == 0) {
    std::cout << "Buzz\n";
  }
  //return 0 to end main
  return 0;
 }
