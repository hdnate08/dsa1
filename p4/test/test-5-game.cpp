#include "catch/catch.hpp"
#include "../game.hpp"
#include <regex>

TEST_CASE("Testing fixed game initialization")
{
	Game g("GNTRHIFHHISTDSRA");
	CHECK("G N T R\nH I F H\nH I S T\nD S R A\n" == g.ShowBoard());
//	G N T R
//	H I F H
//	H I S T
//	D S R A

	CHECK(g.Guess("STAR"));
	CHECK(1 == g.GetScore());

	CHECK(g.Guess("FIST")); // checking diagonals work

	CHECK(!g.Guess("STAR")); // already used - invalid. Don't ++ 'incorrect' count.
	CHECK(!g.Guess("THIS")); // no wrap-around
	CHECK(!g.Guess("HINT")); // no going up

	// Re-guessing a word isn't "incorrect", it just doesn't add to the score
	CHECK(2 == g.GetIncorrectGuesses());

	CHECK(g.Guess("STARS"));
	CHECK(4 == g.GetScore());

	CHECK(27 == g.GetTotalPointsPossible());
}

TEST_CASE("Print out all answers")
{
	Game g("AAAAAAAAAAADAHAH");
	// HAD is not valid since it would require going 'up'
	CHECK("AHA\nHAHA\n" == g.GetAllWords());
}

TEST_CASE("Testing random game initialization")
{
	Game g;
	std::string board = g.ShowBoard ();
	/*
	Since we're using randomization, all we can asset is that the
	board layout matches the basic pattern:
		A B C D
		E F G H
		I J K L
		M N O P
	*/
	std::regex boardFormat("([A-Z] [A-Z] [A-Z] [A-Z]\n){4}");
	CHECK(std::regex_match(board, boardFormat));
	// The below would only happen 1 in every 6^16 runs, so pretty safe to assert it isn't a match
	CHECK("G N L T\nH I F H\nH I S T\nD J A R\n" != g.ShowBoard());
}
