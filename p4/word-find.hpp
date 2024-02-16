#ifndef WORD_FIND_HPP
#define WORD_FIND_HPP
#include <string>
#include <set>
#include "dictionary.hpp"
#include "gameboard.hpp"

class WordFind
{
    public:
        std::set<std::string> GetAllWords(GameBoard g);
    private:
        void AppendDFSWords(GameBoard g, std::string stringPrefix, std::set<std::string>& foundWords, bool alreadyChosen[16], int currentCell);
        Dictionary dictionary;
};
#endif
