#include "cell.hpp"
#include <iostream>

Cell::Cell()
{
	this->clicked = false;
	this->status = false;
	this->spot = CLEAR;
	this->checked = false;
	this->adjacentMines = 0;
	this->Rchecked = false;
}

Cell::Cell(bool status)
{
	this->clicked = false;
	this->status = status;
	this->spot = CLEAR;
	this->checked = false;
	this->adjacentMines = 0;
	this-> Rchecked = false;
}

Cell::Cell(const Cell& rhs)
{
	this->status = rhs.status;
	this->clicked = rhs.clicked;
	this->spot = rhs.spot;
	this->adjacentMines = rhs.adjacentMines;
	this->checked = rhs.checked;
	this->Rchecked = rhs.Rchecked;
}

Cell& Cell::operator=(const Cell& rhs)
{
	this->status = rhs.status;
	this->clicked = rhs.clicked;
	this->spot = rhs.spot;
	this->adjacentMines = rhs.adjacentMines;
	this->checked = rhs.checked;
	this->Rchecked = rhs.Rchecked;
	return *this;
}

bool Cell::IsMine() const
{
	return status;
}

bool Cell::ToggleFlag()
{
	if(this->spot == FLAG)
	{
		this->spot = CLEAR;
		return false;
	}
	else
	{
		this->spot = FLAG;
		return true;
	}
}

std::ostream& operator<<(std::ostream& os, const Cell& rhs)
{
	os << rhs.spot;
	return os;
}

bool Cell::Click()
{
	if(clicked == true)
	{
		return false;
	}
	else if(this->spot == FLAG)
	{
		return false;
	}
	else if(this->spot == CLEAR && status == true)
	{
		this->spot = MINE;
		this->clicked = true;
		return false;
	}
	else if(this->spot == CLEAR && status == false)
	{
		this->clicked = true;//click successful - mark as clicked
		if(this->adjacentMines != 0)
		{
		this->spot = std::to_string(adjacentMines);
		}
		return true;//clear spot
	}
	return false;
}

void Cell::SetAdjacentMineCount(int numMines)
{
	this->adjacentMines = numMines;
	this->spot = std::to_string(adjacentMines);
}
std::string Cell::FLAG = "f";
std::string Cell::MINE = "*";
std::string Cell::CLEAR = " ";
std::string Cell::NO_ADJACENT_MINES = " ";
