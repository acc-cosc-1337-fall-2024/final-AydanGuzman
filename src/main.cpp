#include <iostream>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() 
{
	srand(time(0));
	Die die1, die2;
	Shooter shooter;
	Roll* roll = shooter.throw_dice(die1, die2);
	int rolled_value =roll->roll_value();
	int point = rolled_value;

	ComeOutPhase come_out_phase;
  
     std::cout << "Rolled " << rolled_value << " Start of point phase" << std::endl;
     std::cout << "Roll until "<< rolled_value << " or 7 is rolled" << std::endl;

    RollOutcome outc = come_out_phase.get_outcome(roll);	

	int origvalue=rolled_value;	

	while(outc == RollOutcome::natural && outc == RollOutcome::craps) 
	{
			
		std::cout << "Rolled " << rolled_value << " Roll again" << std::endl;
		if (outc != RollOutcome::natural && outc != RollOutcome::craps )  //  if rolled value in (7-11-2-3-12) exit loop
		{
		   	std::cout << "Exit on " << rolled_value << std::endl;
		}	
	
        roll = shooter.throw_dice(die1, die2);
		rolled_value=roll->roll_value();	
		RollOutcome outc = come_out_phase.get_outcome(roll);
        std::cout << "Rolled " << rolled_value << " Roll again" << std::endl;

		if (rolled_value == 7 || origvalue == rolled_value)
		{
			break;
		}

		
	}
    
		std::cout << "Rolled " << rolled_value << " Roll again please" << std::endl;

	 std::cout << "Start of point phase. Roll until " << rolled_value << " or 7 is rolled." << std::endl;
	 
	 point = rolled_value;
     roll = shooter.throw_dice(die1, die2);

      PointPhase point_phase(point);

	while (true) 
	{
        RollOutcome outcome = point_phase.get_outcome(roll);
        std::cout << "Rolled " << rolled_value << " roll again" << std::endl;

        // Exit the loop if not seven out or no point
        if (outcome != RollOutcome::seven_out && outcome != RollOutcome::nopoint) 
		{
            break;  
        }

        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
    }

	std::cout << "End of point phase." << std::endl;
	shooter.display_rolled_values();
    
	return 0;
}