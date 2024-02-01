#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int.h"
#include "decimals.h"
#include "char.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify echo variable", "verification"){
	REQUIRE(echo_variable(10) == 11);
}


/*test case echo_variable */

/*test case add_to_double_1 with 0 as parameter*/
TEST_CASE("Verify add to double 1 w 0 as parameter", "show issues when comparing double(decimal) values"){
	//REQUIRE(add_to_double_1(0) == .9);
}


/*test case add_to_double_1 with 1 as parameter*/

/*test case add_to_double_2 with 0 as parameter*/
TEST_CASE("Verify add to double 2 w 0 as parameter", "show issues when comparing double(decimal) values"){
	REQUIRE(add_to_double_2(0) == 1.5);
}


/*test case add_to_double_2 with 1 as parameter*/

/*test case char test ASCII values */

/*test case string test ASCII values Joe characters are equal to 74, 111, and 101*/
TEST_CASE("Test char to int conversion")
{
	REQUIRE(get_char_ascii_value('J') == 74);
	REQUIRE(get_char_ascii_value('o') == 111);
	REQUIRE(get_char_ascii_value('e') == 101);
}

