#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include <string>
#include <sstream>

class GameBoard
{
	public:
        GameBoard();
		GameBoard(std::string letters);
		char GetLetterByRowCol(int row, int col);
		std::string ShowBoard();
        GameBoard& operator=(const GameBoard& rhs);
	private:
		char letters[4][4];
};
#endif
