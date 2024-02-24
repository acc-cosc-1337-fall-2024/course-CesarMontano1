//add include statements
#include "repetition.h"
//add function(s) code here
// Function definition for factorial
int factorial(int num) {
    int result = 1;

    while (num > 0) {
        result *= num;
        num--;
    }

    return result;
}

// Function definition for gcd
int gcd(int num1, int num2) {
    while (num1 != num2) {
        if (num1 < num2) {
            // Swap values if num1 is smaller than num2
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }

        // Subtract num2 from num1
        num1 -= num2;
    }

    return num1;
}