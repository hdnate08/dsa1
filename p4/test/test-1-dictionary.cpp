#include "catch/catch.hpp"
#include "../dictionary.hpp"

TEST_CASE("Basic dictionary creation and lookup tests")
{
	Dictionary wordList;

	CHECK(wordList.IsWord("AARDVARK")); // verify that we didn't skip the first word
	CHECK(wordList.IsWord("ZYMURGY")); // verify that the entire file got written by checking last word
	CHECK(!wordList.IsWord("ZZZZ"));
	CHECK(!wordList.IsWord("MARCUS")); // proper noun not in the list given
}
