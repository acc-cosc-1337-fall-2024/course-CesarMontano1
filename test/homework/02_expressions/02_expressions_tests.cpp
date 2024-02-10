#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}

TEST_CASE("Test Get Sales Tax", "hwexpressions") 
{
    // Assertion for get_sales_tax_amount with parameter 10
    REQUIRE(get_sales_tax_amount(10) == Approx(0.675));  // Approx is used for comparing floating-point numbers
    
    // Assertion for get_sales_tax_amount with parameter 20
    REQUIRE(get_sales_tax_amount(20) == Approx(1.35));
}

TEST_CASE("Test Get Tip Amount", "hwexpressions") 
{
    // Assertion for get_tip_amount with parameters 20 and 15%
    REQUIRE(get_tip_amount(20, 0.15) == Approx(3.0));
    
    // Assertion for get_tip_amount with parameters 20 and 20%
    REQUIRE(get_tip_amount(20, 0.20) == Approx(4.0));
}
