//write include statements
#include <iostream>
#include "hwexpressions.h"

using std::cout;
using std::cin;
//write namespace using statement for cout

int main()
{
	// Step a) Create double variables
    double meal_amount, tip_rate, tip_amount, tax_amount, total;

    // Step b) Use cin to capture the meal amount
    cout << "Enter the meal amount: ";
    cin >> meal_amount;

    // Step c) Call get_sales_tax_amount and assign the return value to tax_amount
    tax_amount = get_sales_tax_amount(meal_amount);

    // Step d) Capture the tip rate from the keyboard and assign it to tip_rate
    cout << "Enter the tip rate (as a decimal): ";
    cin >> tip_rate;

    // Step e) Call get_tip_amount and set its return value to tip_amount
    tip_amount = get_tip_amount(meal_amount, tip_rate);

    // Step f) Calculate the total
    total = meal_amount + tax_amount + tip_amount;

    // Step g) Display the receipt
    cout << "Meal Amount:      " << meal_amount << std::endl;
    cout << "Sales Tax:         " << tax_amount << std::endl;
    cout << "Tip Amount:        " << tip_amount << std::endl;
    cout << "Total:             " << total << std::endl;

	return 0;
}
