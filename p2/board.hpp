#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <fstream>
#include "cell.hpp"
class Board
{
	public:
		Board();
		Board(std::string gameInput);
		~Board();
		Board& operator=(const Board& rhs);
		void inRows();
		int getRows() {return this->rows;};
		int getCols() {return this->cols;};
		void inCols();
		void createBoard();
		void printAll();
		void mineBoard();
		bool Click(int row, int col);
		bool Flag(int row, int col);
		bool winCheck();
		void gameOver();
		bool IsMine(int row, int col) {return this->boardArray[row][col].IsMine();};
		void recursionClear(int row, int col);
		void surroundingCheck(int row, int col);
		friend std::ostream& operator<<(std::ostream& os, const Board& rhs);
	private:
		int numClicks;
		int totalMines;
		std::ifstream inFS;
		int rows;
		int cols;
		Cell** boardArray;
		std::string boardLayout;
};

#endif
