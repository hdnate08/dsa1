#include "gameboard.hpp"

GameBoard::GameBoard()
{
    this->letters[4][4] = {'a'};
}

GameBoard::GameBoard(std::string letters)
{
	int count = 0;

	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			this->letters[i][j] = letters.at(count++);
		}
	}
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            this->letters[i][j] = rhs.letters[i][j];
        }
    }
    return *this;
}

char GameBoard::GetLetterByRowCol(int row, int col)
{
	return this->letters[row][col];
}

std::string GameBoard::ShowBoard()
{
	std::ostringstream oss;
	std::string temp;

	oss << letters[0][0] << " " << letters[0][1] << " " << letters[0][2] << " " << letters[0][3] << '\n'
	    << letters[1][0] << " " << letters[1][1] << " " << letters[1][2] << " " << letters[1][3] << '\n'
	    << letters[2][0] << " " << letters[2][1] << " " << letters[2][2] << " " << letters[2][3] << '\n'
	    << letters[3][0] << " " << letters[3][1] << " " << letters[3][2] << " " << letters[3][3] << '\n';

	temp = oss.str();
	return temp;
}
