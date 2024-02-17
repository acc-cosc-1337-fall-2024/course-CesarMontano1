//write include statements
#include <iostream>
#include "decisions.h"

int main() 
{
	 int choice;
    int numericalGrade;

    // Display the main menu
    std::cout << "MAIN MENU" << std::endl;
    std::cout << "1-Letter grade using if" << std::endl;
    std::cout << "2-Letter grade using switch" << std::endl;
    std::cout << "3-Exit" << std::endl;

    // Prompt the user to choose an option
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    // Process the user's choice
    switch (choice) {
        case 1:
            // Option 1: Letter grade using if
            std::cout << "Enter a numerical grade: ";
            std::cin >> numericalGrade;

            if (numericalGrade >= 0 && numericalGrade <= 100) {
                std::cout << "Letter grade using if: " << get_letter_grade_using_if(numericalGrade) << std::endl;
            } else {
                std::cout << "Number out of range. Please enter a valid numerical grade (0-100)." << std::endl;
            }
            break;

        case 2:
            // Option 2: Letter grade using switch
            std::cout << "Enter a numerical grade: ";
            std::cin >> numericalGrade;

            if (numericalGrade >= 0 && numericalGrade <= 100) {
                std::cout << "Letter grade using switch: " << get_letter_grade_using_switch(numericalGrade) << std::endl;
            } else {
                std::cout << "Number out of range. Please enter a valid numerical grade (0-100)." << std::endl;
            }
            break;

        case 3:
            // Option 3: Exit
            std::cout << "Exiting the program." << std::endl;
            break;

        default:
            // Invalid option
            std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
            break;
    }
	
	return 0;
}