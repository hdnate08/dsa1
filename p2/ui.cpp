#include "ui.hpp"

UI::UI()
{
	this->gameOver = false;
	this->prompt = INPUTFILE;
	this->gameField = " ";
}

UI::~UI()
{
	delete this->b;
}

std::string UI::GetPrompt()
{
	return this->prompt;
}

bool UI::SetFileName(std::string fileName)
{
	inFS.open(fileName);
	if(!inFS.is_open())
	{
		inFS.close();
		return false;
	}
	else
	{
		inFS.close();
		b = new Board(fileName);
		os << *b;
		this->prompt = os.str() + PLAY;
		return true;
	}
}

bool UI::Move(char move, int row, int col)
{
	if(row < 0 || col < 0|| row > this->b->getRows() -1 || col > this->b->getCols() -1)
	{
		this->prompt = INVALID;
		return false;
	}
	else
	{
		if(move == 'C' || move == 'c')
		{
			this->b->Click(row,col);
			if(this->b->winCheck())
			{
				os.str("");
				os << *b;
				this->gameOver = true;
				this->prompt = os.str() + WIN;
				return true;
			}
			else if(this->b->IsMine(row, col))
			{
				os.str("");
				this->b->gameOver();
				os << *b;
				this->gameOver = true;
				this->prompt = os.str() + WIN;
				return true;
			}
			else
			{
				os.str("");
				os << *b;
				this->prompt = os.str() + PLAY;
				return true;
			}
		}
		else if(move == 'F' || move == 'f')
		{
			this->b->Flag(row,col);
			os.str("");
			os << *b;	
			this->prompt = os.str() + PLAY;
			return true;
		}
		else
		{
			this->prompt = INVALID;
			return false;
		}
	}
}

std::string UI::WIN = "Game Over!";
std::string UI::INPUTFILE = "Please enter a file name with the minefield information: ";
std::string UI::PLAY = "Choose your next move(c or f) and cell, e.g. c 0 3 to click row zero column 3: ";
std::string UI::INVALID = "Invalid move. Please enter your next move: ";
