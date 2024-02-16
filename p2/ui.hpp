#ifndef UI_HPP
#define UI_HPP
#include "board.hpp"
#include <string>
#include <sstream>
#include <fstream>
class UI
{
	public:
		UI();
		~UI();
		bool IsGameOver() {return this->gameOver;};
		bool SetFileName(std::string fileName);
		std::string GetPrompt();
		static std::string INPUTFILE;
		static std::string PLAY;
		static std::string INVALID;
		static std::string WIN;
		void setGameOver() {this->gameOver = true;};
		bool Move(char move, int row, int col);
	private:
		bool gameOver;
		Board *b;
		std::ifstream inFS;
		std::ostringstream os;
		std::string gameField;
		std::string prompt;





};


#endif
