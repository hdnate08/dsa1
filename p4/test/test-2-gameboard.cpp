#include "catch/catch.hpp"
#include "../gameboard.hpp"

TEST_CASE("Test GameBoard initialization")
{
	GameBoard g("GNLTHIFHHISTDJAR");
	CHECK('G' == g.GetLetterByRowCol(0, 0));
	CHECK('T' == g.GetLetterByRowCol(0, 3));
	CHECK('R' == g.GetLetterByRowCol(3, 3));

	CHECK("G N L T\nH I F H\nH I S T\nD J A R\n" == g.ShowBoard());
}
