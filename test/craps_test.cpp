#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <die.h>
#include <roll.h>
#include "shooter.h"


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

TEST_CASE("Verify Dice rolls returns a value 2-12") {
	Die die1;
	Die die2;

	Roll roll(die1, die2);

	roll.roll_dice();
	int value = roll.roll_value();

	REQUIRE((value <= 12 && value >= 2));


}
TEST_CASE("Verify Dice rolls return values 1-6 10 times") {
	Die die1;
	Die die2;

	Roll roll(die1, die2);

	roll.roll_dice();
	

	for (int i = 0; i < 10; ++i)
	{
		int value = roll.roll_value();
		REQUIRE((value >= 2 && value <= 12));
		
	}
	
}

TEST_CASE("Verify that Shooter returns a Roll with valid roll result") {
	Die die1;
	Die die2;

	Shooter shooter;
	

	for (int i = 0; i < 10; ++i)
	{
		Roll* roll = shooter.throw_dice(die1, die2);
		int rollValue = roll->roll_value();
		std::cout << "Roll value " << rollValue;
		REQUIRE(rollValue >=2);
		REQUIRE(rollValue <= 12);
		
	}
	
}

