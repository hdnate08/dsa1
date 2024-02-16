#include "word-find.hpp"
#include <iostream>

std::set<std::string> WordFind::GetAllWords(GameBoard g)
{
    //This method should return all found words in the set.
    std::string stringPrefix = "";
    std::set<std::string> foundWords;
    bool alreadyChosen[16] = {false};

    //This method starts the recursion
    //Calls all cells and each cell checkitself as chosen - this acts as a base case
    for(int i = 0; i < 16; ++i)
    {
    	AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, i);
    }
	return foundWords;
}

void WordFind::AppendDFSWords(GameBoard g, std::string stringPrefix, std::set<std::string>& foundWords, bool alreadyChosen[16], int currentCell)
{
    //recursive backtracking algorithm used to find all words in the 2d boggle array
    //check this cell visited
    alreadyChosen[currentCell] = true;
    //add letter of current cell to stringPrefix and check against dictionary
    stringPrefix = stringPrefix + g.GetLetterByRowCol(currentCell/4, currentCell%4);
    //if word -> add to foundWords
    if(this->dictionary.IsWord(stringPrefix))
    {
	foundWords.insert(stringPrefix);
    }
    //check all blocks surrounding currentCell
    for(int i = (currentCell/4); i <= (currentCell/4) + 1; ++i)//row
    {
	for(int j = (currentCell%4) - 1; j <= (currentCell%4) + 1; ++j) //col
	{
		if(i >= 0 && j >= 0 && i < 4 && j < 4 && !alreadyChosen[(i*4)+j]) //check for out of bounds or flagged
		{
			AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, (i*4)+j);
		}
	}
    }
    stringPrefix.pop_back();
    alreadyChosen[currentCell] = false;
    return;
    //if no open then subtract last letter from stringPrefix and return
}
