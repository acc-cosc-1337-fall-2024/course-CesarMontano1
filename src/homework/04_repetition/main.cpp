//write include statements
#include <iostream>
#include "repetition.h"
//write using statements

int main() 
{
	int choice;

    do {
        // Display menu
        std::cout << "Menu:\n";
        std::cout << "1-Factorial\n";
        std::cout << "2-Greatest Common Divisor\n";
        std::cout << "3-Exit\n";

        // Get user choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Factorial
                int num;
                std::cout << "Enter a number to calculate its factorial: ";
                std::cin >> num;
                std::cout << "Factorial of " << num << " is: " << factorial(num) << std::endl;
                break;
            }
            case 2: {
                // Greatest Common Divisor
                int num1, num2;
                std::cout << "Enter two numbers to find their Greatest Common Divisor: ";
                std::cin >> num1 >> num2;
                std::cout << "Greatest Common Divisor of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << std::endl;
                break;
            }
            case 3: {
                // Exit
                char confirm;
                std::cout << "Are you sure you want to exit? (y/n): ";
                std::cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    std::cout << "Exiting the program. Goodbye!\n";
                    return 0;
                } else {
                    // Continue the loop if the user chooses not to exit
                    break;
                }
            }
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);
	
	return 0;
}
