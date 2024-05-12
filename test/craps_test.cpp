#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"



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

	
	

	for (int i = 0; i < 10; ++i)
	{
		roll.roll_dice();
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
		std::cout << "Roll value " << rollValue  << std::endl;
		REQUIRE(rollValue >=2);
		REQUIRE(rollValue <= 12);
		
	}
	
}

TEST_CASE("Test ComeOutPhase") {

	Die die1;
	Die die2;	

	Roll roll(die1, die2);
	
    
    ComeOutPhase comeOutPhase;

	for (int i = 0; i < 10; ++i)
	{
    roll.roll_dice();
	int value = roll.roll_value();

	RollOutcome outc = comeOutPhase.get_outcome(&roll);
  
	std::cout << "myrowval " << value << std::endl;

	if (outc == RollOutcome::natural)
	{
		REQUIRE(outc == RollOutcome::natural);
	}
	else if (outc == RollOutcome::craps)
	{
		REQUIRE(outc == RollOutcome::craps);
	}
	else
	{
		REQUIRE(outc == RollOutcome::point);
	}
	
	  switch (outc) 
	   {
        case RollOutcome::natural:
            std::cout << "Natural!" << std::endl;
            break;
        case RollOutcome::craps:
            std::cout << "Craps!" << std::endl;
            break;
        case RollOutcome::point:
            std::cout << "Point!" << std::endl;
            break;

       }
	}

}

TEST_CASE("Test PointPhase") {

	Die die1;
	Die die2;	

	Roll roll(die1, die2);
	
	int vpoint = 5;
    PointPhase point_phase(vpoint);

	for (int i = 0; i < 10; ++i)
	{
    roll.roll_dice();
	int value = roll.roll_value();

	RollOutcome outc = point_phase.get_outcome(&roll);
  
	std::cout << "myrowval " << value << std::endl;

	if (outc == RollOutcome::point)
	{
		REQUIRE(outc == RollOutcome::point);
	}
	else if (outc == RollOutcome::seven_out)
	{
		REQUIRE(outc == RollOutcome::seven_out);
	}
	else if (outc == RollOutcome::nopoint)
	{
		REQUIRE(outc == RollOutcome::nopoint);
	}
	
	  switch (outc) 
	   {
        case RollOutcome::point:
            std::cout << "Point!" << std::endl;
            break;
        case RollOutcome::seven_out:
            std::cout << "Seven Out!" << std::endl;
            break;
        case RollOutcome::nopoint:
            std::cout << "No Point!" << std::endl;
            break;     
       }
	}

}


