#ifndef CELL_HPP
#define CELL_HPP
#include <ostream>
#include <string>
class Cell
{
	public:
		Cell();
		Cell(bool mine);
		Cell(const Cell& rhs);
		Cell& operator=(const Cell& rhs);
		bool IsMine() const;
		bool ToggleFlag();
		void setSpot(std::string spot) {this->spot = spot;};
		static std::string FLAG;
		static std::string HIDDEN;
		static std::string MINE;
		static std::string CLEAR;
		static std::string SHOW;
		static std::string NO_ADJACENT_MINES;
		bool IsChecked() {return this->checked;};
		void check() {this->checked = true;};
		bool IsRChecked() {return this-> Rchecked;};
		void Rcheck() {this->Rchecked = true;};
		int getMineCount() {return this->adjacentMines;};
	       	void addMine() {this->adjacentMines +=1;};	
		bool Click();
		bool IsClicked() {return this->clicked;};
		void SetAdjacentMineCount(int numMines);
		std::string getSpot() {return this-> spot;};
		friend std::ostream& operator<<(std::ostream& os, const Cell& rhs);
	private:
		bool status;
		bool clicked;
		std::string spot;
		int adjacentMines;
		bool checked;
		bool Rchecked;

};
#endif
