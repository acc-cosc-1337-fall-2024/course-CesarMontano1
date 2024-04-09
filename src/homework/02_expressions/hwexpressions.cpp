#include "hwexpressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

// Function to calculate sales tax amount
double get_sales_tax_amount(double meal_amount)
{
    // Assuming tax_rate is a constant or defined somewhere
    const double tax_rate = 0.0675; // Change this value based on your requirement

    // Calculate and return the sales tax amount
    return meal_amount * tax_rate;
}

// Function to calculate tip amount
double get_tip_amount(double meal_amount, double tip_rate)
{
    // Calculate and return the tip amount
    return meal_amount * tip_rate;
}




