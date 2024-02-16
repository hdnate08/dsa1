#include <sstream>
#include "catch/catch.hpp"
#include "../cell.hpp"

TEST_CASE("Cell with mine")
{
	std::ostringstream os;
	bool mine = true;
	Cell c(mine);

	CHECK(c.IsMine());

	os << c;
	CHECK(" " == os.str()); // cell has not been uncovered yet

	os.str(""); // reset stream to empty string
	c.ToggleFlag();
	os << c;
	CHECK(Cell::FLAG == os.str());

	bool clickSuccessful = c.Click();
	CHECK(!clickSuccessful); // cannot click a cell that has a flag on it

	os.str(""); // reset stream to empty string
	c.ToggleFlag();
	os << c;
	CHECK(" " == os.str()); // flag should be gone

	os.str(""); // reset stream to empty string
	c.Click();
	os << c;
	CHECK(Cell::MINE == os.str());
}

TEST_CASE("Cell without mine")
{
	bool mine = false;
	Cell c(mine);
	CHECK(!c.IsMine());

	std::ostringstream os;
	os << c;
	CHECK(" " == os.str());

	os.str(""); // reset stream to empty string
	c.Click();
	os << c;
	CHECK(Cell::NO_ADJACENT_MINES == os.str());

	os.str(""); // reset stream to empty string
	c.SetAdjacentMineCount(6); // set arbitrary number of adjacent mines
	os << c;
	CHECK("6" == os.str());

	bool clickedAgain = c.Click(); // can't uncover a cell again
	CHECK(!clickedAgain);
}

