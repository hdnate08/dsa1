#include <sstream>
#include "catch/catch.hpp"
#include "board-configurations.hpp"
#include "../cell.hpp"
#include "../board.hpp"
#include "../ui.hpp"

TEST_CASE("UI class")
{
	// test get file name
	UI ui;
	std::string prompt;
	bool isValidInput;
	bool isValidMove = false;

	CHECK(!ui.IsGameOver());

	prompt = ui.GetPrompt();
	CHECK("Please enter a file name with the minefield information: " == prompt);
	// class would use cin, we'll hard-code an expected input

	isValidInput = ui.SetFileName("foo.bar.baz"); // file does not exist on our system
	CHECK(!isValidInput);

	prompt = ui.GetPrompt();
	CHECK("Please enter a file name with the minefield information: " == prompt);
	
	isValidInput = ui.SetFileName("four-by-four.in");
	CHECK(isValidInput);

	// should now be in game play mode
	prompt = ui.GetPrompt();
	CHECK(NOTHING_CLICKED+"Choose your next move(c or f) and cell, e.g. c 0 3 to click row zero column 3: " == prompt);

	isValidMove = ui.Move('z', 0, 0); // not a click or a flag
	CHECK(!isValidMove);
	prompt = ui.GetPrompt();
	CHECK("Invalid move. Please enter your next move: " == prompt);

	isValidMove = ui.Move('C', -1, 0); // above the board
	CHECK(!isValidMove);

	isValidMove = ui.Move('c', 0, -1); // left of the board
	CHECK(!isValidMove);

	isValidMove = ui.Move('F', 4, 0); // below the board
	CHECK(!isValidMove);

	isValidMove = ui.Move('f', 0, 4); // right of the board
	CHECK(!isValidMove);

	ui.Move('c', 0, 0);
	prompt = ui.GetPrompt();
	CHECK(TOP_LEFT_CLICKED+"Choose your next move(c or f) and cell, e.g. c 0 3 to click row zero column 3: " == prompt);

	ui.Move('C', 0, 3);
	ui.Move('c', 3, 2);
	ui.Move('f', 1, 3);
	prompt = ui.GetPrompt();
	CHECK(FLAG_ADDED+"Choose your next move(c or f) and cell, e.g. c 0 3 to click row zero column 3: " == prompt);

	// click the rest of the cells without mines
	ui.Move('c', 3, 0);
	ui.Move('c', 3, 2);
	ui.Move('c', 2, 1);

	CHECK(!ui.IsGameOver());
	ui.Move('c', 2, 2); // final cell - Winner

	prompt = ui.GetPrompt();
	CHECK(CLEARED_MINEFIELD+"Game Over!" == prompt);

	CHECK(ui.IsGameOver());
}

TEST_CASE("Boom")
{
	UI ui;
	ui.SetFileName("four-by-four.in");

	ui.Move('c', 3, 3); // mine
	std::string prompt = ui.GetPrompt();
	CHECK(MINES_UNEARTHED+"Game Over!" == prompt);

	CHECK(ui.IsGameOver());
}
