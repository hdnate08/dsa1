#include "catch/catch.hpp"
#include "../word-find.hpp"
#include "../gameboard.hpp"
#include <iostream>

TEST_CASE("Checking word list finder")
{
	WordFind wordFinder; // need instance to house an instance of a lookup dictionary

	GameBoard g("GGGGGGGGGGGGGGGG"); // No words
	CHECK(wordFinder.GetAllWords(g).size() == 0);

	GameBoard g2("AAAAAAAAAAAAAAAH"); // AHA should be only word
	CHECK(wordFinder.GetAllWords(g2).size() == 1);

	GameBoard g3("ABHGDGEINSGEHTAC");
	CHECK(wordFinder.GetAllWords(g3).size() == 28);
}
