//name: Tavishka Arora UTEID: ta24435 tacc user: tavishka
#include <iostream>
using namespace std;

//Collatz Function
int collatz(int nStart) {
    //counts the number of numbers in the sequence
    int length = 0;
    //stops iterations when reaching 1
    while (nStart != 1) {
        //checks if number is even
        if (nStart % 2 == 0) {
            //divide by 2
            nStart /= 2; 
        } else {
            //applies odd "formula" for odd numbers, multiply by 3 and add 1
            nStart = 3 * nStart + 1; 
        }
        //increment the number of step
        length++;
    }
    //return the total number of steps
    return length;
}

int main() {
    //store the maximum length
    int max_length = 0;
    //Store the starting number associated with the maximum length
    int num_of_max_length = 1;
    
    //iterates starting numbers 1-1000 to check to see which starting number provides the longest sequence
    for (int i = 1; i <= 1000; ++i) {
        int lCurrent = collatz(i);
        //checks to see if update is necessary
        if (lCurrent > max_length) {
            //update max length
            max_length = lCurrent;
            //update the starting number with max length
            num_of_max_length = i; 
        }
    }

    cout << "The starting number with the longest Collatz sequence between 1 and 1000 is: "
         << num_of_max_length << endl;
    cout << "The length of this sequence is: " << max_length << endl;

    return 0;
}

