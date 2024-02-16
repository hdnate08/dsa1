#ifndef GAME_HPP
#define GAME_HPP
#include "die.hpp"
#include "gameboard.hpp"
#include "word-find.hpp"
#include <set>
class Game
{
    public:
        Game();
        Game(std::string diceRolls);
        std::string ShowBoard();
        bool Guess(std::string word);
        int GetScore();
        int GetIncorrectGuesses();
        int GetTotalPointsPossible();
        std::string GetAllWords();
    private:
        Die dice[16];
        GameBoard board;
        WordFind wordFind;
        std::set<std::string> correctGuesses;
        int numberOfWrongGuesses;
        std::set<std::string> fullSetOfCorrectWords;
        int totalScore;
        void initDice();
        std::string GetAllDiceValues();
        bool IsValidGuess(std::string word);
        bool NewWord(std::string word);
        int GetWordScore(std::string word);
        int GetPointsForSet(const std::set<std::string>& wordList);
};
#endif
