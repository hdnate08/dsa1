#include "catch/catch.hpp"
#include "../die.hpp"

TEST_CASE("Testing die creation and roll")
{
	Die d("RIFOBX");
	char roll = d.Roll();
	CHECK((roll == 'R' || roll == 'I' || roll == 'F' || roll == 'O' || roll == 'B' || roll == 'X'));

	char secondRoll = roll;

	while (secondRoll == roll) // just making sure that the roll method will return different values
	{
		// Doing this in a loop since this should be random and might return the same char several times
		secondRoll = d.Roll();
	}

	CHECK(secondRoll != roll);
}
