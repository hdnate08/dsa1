#include <sstream>
#include "catch/catch.hpp"
#include "board-configurations.hpp"
#include "../cell.hpp"
#include "../board.hpp"

TEST_CASE("Board Initialization and display")
{
	Board b("four-by-four.in");
	std::ostringstream os;
	os << b;

	CHECK(NOTHING_CLICKED == os.str());
}
