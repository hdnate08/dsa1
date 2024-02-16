#include <sstream>
#include "catch/catch.hpp"
#include "board-configurations.hpp"
#include "../cell.hpp"
#include "../board.hpp"

TEST_CASE("Board Game Play")
{
	std::ostringstream printoutOfBoard;
	bool wasValidClick;
	bool isFlagged;

	Board b("four-by-four.in");

	SECTION ("Board boundaries")
	{
		// testing clicks outside the board
		wasValidClick = b.Click(-1, 0);
		CHECK(!wasValidClick);
		wasValidClick = b.Click(4, 0);
		CHECK(!wasValidClick);
		wasValidClick = b.Click(0, -1);
		CHECK(!wasValidClick);
		wasValidClick = b.Click(0, 4);
		CHECK(!wasValidClick);
	}

	SECTION ("Trying to click on flagged cell")
	{
		isFlagged = b.Flag(0, 0); // place flag at cell 0,0
		CHECK(isFlagged);

		wasValidClick = b.Click(0, 0); // has flag from above
		CHECK(!wasValidClick);

		b.Flag(0, 0); // removes the flag on cell 0,0
		wasValidClick = b.Click(0, 0);
		CHECK(wasValidClick);

		printoutOfBoard << b;

		CHECK(TOP_LEFT_CLICKED == printoutOfBoard.str());
	}

	SECTION ("Bunch 'O clicks")
	{
		std::ostringstream bottomRightClickedStream;
		b.Click(0, 0);
		b.Click(3, 2);
		bottomRightClickedStream << b;
		CHECK(BOTTOM_RIGHT_NUMBER_CLICKED == bottomRightClickedStream.str());

		std::ostringstream topRowClickedStream;
		b.Click(0, 3);
		topRowClickedStream << b;
		CHECK(TOP_ROW_ALL_CLICKED == topRowClickedStream.str());
	}
}
