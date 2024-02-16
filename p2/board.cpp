#include "board.hpp"
#include <cstring>
Board::Board()
{
	this->totalMines = 0;
	this->numClicks = 0;
	this-> rows = 1;
	this-> cols = 1;
	this->boardArray = new Cell*[rows];
	for(int i = 0; i < rows; ++i)
	{
		this->boardArray[i] = new Cell[cols];
	}
}

Board::Board(std::string gameInput)
{ 
	inFS.open(gameInput);
	this-> totalMines = 0;
	this->numClicks = 0;
	this-> rows = 0;
	this-> cols = 0;
	inRows();
	inCols();
	createBoard();
}

Board& Board::operator=(const Board& rhs)
{
	this->totalMines = rhs.totalMines;
	this->numClicks = rhs.numClicks;
	this->rows = rhs.rows;
	this->cols = rhs.cols;
	this->boardLayout = rhs.boardLayout;
	if(this !=&rhs)
	{
		for(int i = 0; i < rows; ++i)
		{
			delete [] boardArray[i];
		}
		delete [] boardArray;

		this->boardArray = new Cell*[rows];
		for(int i = 0; i < this->cols; ++i)
		{
			this->boardArray[i] = new Cell[cols];
		}
		for(int i = 0; i < this->rows; ++i)
		{
			for(int j = 0 ; j < this->cols; ++j)
			{
				this->boardArray[i][j] = rhs.boardArray[i][j];
			}
		}
	}
	return *this;
}

Board::~Board()
{
	for(int i = 0; i < rows; ++i)
	{
		delete [] boardArray[i];
	}
	delete [] boardArray;
	inFS.close();
}

void Board::inRows()
{
	std::string temp;
	while(std::getline(inFS, temp))
	{
		rows++;	
	}
	inFS.clear();
	inFS.seekg(0);
}

void Board::inCols()
{
	std::string temp;
	std::getline(inFS, temp);
	this-> cols = temp.length();
	inFS.clear();
	inFS.seekg(0);
}

void Board::createBoard()
{
	boardArray = new Cell*[rows];
	for(int i = 0; i < rows; i++)
	{
		boardArray[i] = new Cell[cols];
	}
	//modify Cells to either contain a mine or not
	mineBoard();
}

void Board::mineBoard()
{
	bool mine = true;
	std::string temp;
	std::getline(inFS, temp);
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			if(temp[j] == '*')
			{
				this-> boardArray[i][j] = Cell(mine);
				this->totalMines++;
			}
		}
		std::getline(inFS, temp);
	}
	inFS.clear();
	inFS.seekg(0);
}

bool Board::Click(int row, int col)
{
	if(row < 0 || row > this->rows - 1 || col < 0 || col > this->cols - 1)
	{
		return false;
	}
	else if(this->boardArray[row][col].Click())
	{
		recursionClear(row, col);
		return true;
	}
	return false;	
}

bool Board::Flag(int row, int col)
{
	if(row < 0 || row > this->rows - 1 || col < 0 || col > this->cols - 1)
	{
		return false;
	}
	else
	{	
		return this->boardArray[row][col].ToggleFlag();
	}
}

void Board::recursionClear(int row, int col)
{
	//Clears the clicked cell and checks all surrounding cells to see if they are also clearable
	//then counts mines surrounding the surrounding cells and displays that count
	surroundingCheck(row,col);
	if(this->boardArray[row][col].getMineCount() != 0)
	{
		this->boardArray[row][col].setSpot(std::to_string(this->boardArray[row][col].getMineCount()));
	}
	else//0 adjacent mine
	{
		this->boardArray[row][col].setSpot(Cell::NO_ADJACENT_MINES);
		this->boardArray[row][col].Click();
		for(int i = row-1; i <= row+1; ++i)//check adjacent cells for any that are 0
		{	
			if(i < 0 || i > this->rows-1)
			{	
			continue;
			}
			for(int j = col-1; j <= col+1; ++j)
			{
				if(j < 0 || j > this->cols-1)
				{
					continue;
				}
				surroundingCheck(i, j);
				if(this->boardArray[i][j].getMineCount() == 0 && !this->boardArray[i][j].IsRChecked()){//if 0 and hasn't already been passed then pass
					this->boardArray[i][j].Rcheck();
					recursionClear(i,j);
				}
				else if(this->boardArray[i][j].getMineCount() != 0 && !this->boardArray[i][j].IsRChecked() && this->boardArray[i][j].getSpot() != Cell::FLAG)//if not zero then display
				{
					this->boardArray[i][j].Click();
				//	this->boardArray[i][j].setSpot(std::to_string(this->boardArray[i][j].getMineCount()));
				}
			}
		}
	}
}

void Board::surroundingCheck(int row, int col)//checks cells around passed cell for mines
{
	if(this->boardArray[row][col].IsChecked())
	{
		return;
	}
	else
	{
		this->boardArray[row][col].check();
		for(int i = row-1; i <= row+1; ++i)
		{
			if(i < 0 || i > this->rows-1)
			{	
				continue;
			}
			for(int j = col-1; j <= col+1; ++j)
			{
				if(j < 0 || j > this->cols-1)
				{
					continue;
				}
				else if(this->boardArray[i][j].IsMine())
				{
					this->boardArray[row][col].addMine();
				}
			}
		}
	}
}

bool Board::winCheck()
{
	this->numClicks = 0;
	int total = (this->rows * this-> cols);
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(boardArray[i][j].IsClicked())
			{
				this->numClicks++;
			}
		}
	}
	if(this->numClicks == total - (this->totalMines))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Board::gameOver()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(this->boardArray[i][j].IsMine())
				{
					this->boardArray[i][j].setSpot(Cell::MINE);
				}
		}
	}
}

void Board::printAll()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			std::cout << boardArray[i][j].IsClicked();
		}
		std::cout << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Board& rhs)
{
	os <<
	       	"      0   1   2   3 \n"
		"    +---+---+---+---+\n"
		"  0 | "<<rhs.boardArray[0][0]<<" | "<<rhs.boardArray[0][1]<<" | "<<rhs.boardArray[0][2]<<" | "<<rhs.boardArray[0][3]<<" |\n"
		"    +---+---+---+---+\n"
		"  1 | "<<rhs.boardArray[1][0]<<" | "<<rhs.boardArray[1][1]<<" | "<<rhs.boardArray[1][2]<<" | "<<rhs.boardArray[1][3]<<" |\n"
		"    +---+---+---+---+\n"
		"  2 | "<<rhs.boardArray[2][0]<<" | "<<rhs.boardArray[2][1]<<" | "<<rhs.boardArray[2][2]<<" | "<<rhs.boardArray[2][3]<<" |\n"
		"    +---+---+---+---+\n"
		"  3 | "<<rhs.boardArray[3][0]<<" | "<<rhs.boardArray[3][1]<<" | "<<rhs.boardArray[3][2]<<" | "<<rhs.boardArray[3][3]<<" |\n"
		"    +---+---+---+---+\n";
	return os;
}
