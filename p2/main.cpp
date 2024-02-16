#include "board.hpp"
#include <sstream>
#include <iostream>
#include "ui.hpp"
int main()
{
	std::string filename = "";
	char move;
	int row;
	int col;
	UI ui;
	
	std::cout << UI::INPUTFILE;
	std::cin >> filename;
	while(!ui.SetFileName(filename))
	{
		std::cout << UI::INPUTFILE;
		std::cin >> filename;
	}

	while(!ui.IsGameOver())
	{
		std::cout << ui.GetPrompt();
		std::cin >> move >> row >> col;
		ui.Move(move, row, col);
		std::cin.clear();
	}

	std::cout << ui.GetPrompt();

	return 0;
}
