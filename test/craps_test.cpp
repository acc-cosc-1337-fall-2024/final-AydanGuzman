#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <die.h>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Die rolls returns a value 1-6") {
	Die die;
	int result = die.roll();

	REQUIRE((result <= 6 && result >= 1));


}
TEST_CASE("Verify Die rolls return values 1-6 10 times") {
	Die die;

	for (int i = 0; i < 10; ++i)
	{
		int result = die.roll();
		REQUIRE((result >= 1 && result <= 6));
		//REQUIRE(result <= 6);
	}
	
}

