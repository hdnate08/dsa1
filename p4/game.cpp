#include "game.hpp"
#include <algorithm>
#include <iostream>

Game::Game()
{
    initDice();
    this->board = GameBoard(GetAllDiceValues());
    this->fullSetOfCorrectWords = this->wordFind.GetAllWords(board);
    this->totalScore = 0;
    this->numberOfWrongGuesses = 0;
}

Game::Game(std::string diceRolls)
{
    this->board = GameBoard(diceRolls);
    this->fullSetOfCorrectWords = this->wordFind.GetAllWords(board);
    this->totalScore = 0;
    this->numberOfWrongGuesses = 0;
}

void Game::initDice()
{
    //initialize each die
   this->dice[0] = Die("RIFOBX");
   this->dice[1] = Die("IFEHEY");
   this->dice[2] = Die("DENOWS");
   this->dice[3] = Die("HMSRAO");
   this->dice[4] = Die("LUPETS");
   this->dice[5] = Die("ACITOA");
   this->dice[6] = Die("YLGKUE");
   this->dice[7] = Die("QBMJOA");
   this->dice[8] = Die("EHISPN");
   this->dice[9] = Die("VETIGN");
   this->dice[10] = Die("BALIYT");
   this->dice[11] = Die("EZAVND");
   this->dice[12] = Die("RALESC");
   this->dice[13] = Die("UWILRG");
   this->dice[14] = Die("PACEMD");
   this->dice[15] = Die("UTOKND");
    //shuffle each die into array
    std::random_shuffle(dice, dice + 16);
}

std::string Game::GetAllDiceValues()
{
    std::string temp;

    for(int i = 0; i < 16; ++i)
    {
            temp = temp + this->dice[i].Roll();
    }
    return temp;
}

bool Game::IsValidGuess(std::string word)
{
    if(this->fullSetOfCorrectWords.find(word) != fullSetOfCorrectWords.end())
    {
        return true;
    }
    return false;
}

bool Game::NewWord(std::string word)
{
    if(this->correctGuesses.find(word) == correctGuesses.end())
    {
        return true;
    }
    return false;
}

std::string Game::ShowBoard()
{
    return this->board.ShowBoard();
}

bool Game::Guess(std::string word)
{
    if(IsValidGuess(word) && NewWord(word))
    {
        this->correctGuesses.insert(word);
        this->totalScore = totalScore + GetWordScore(word);
        return true;
    }
    else if(IsValidGuess(word) && !NewWord(word))
    {
        return false;
    }
    this->numberOfWrongGuesses++;
    return false;
}

int Game::GetWordScore(std::string word)//failing
{
    if(word.length() > 2 && word.length() < 5)
    {
        return 1;
    }
    else if(word.length() == 5)
    {
        return 2;
    }
    else if(word.length() == 6)
    {
        return 3;
    }
    else if(word.length() == 7)
    {
        return 4;
    }
    else if(word.length() >= 8)
    {
        return 11;
    }
    else
    {
        return 0;
    }
}

int Game::GetScore()
{
    return this->totalScore;
}

int Game::GetIncorrectGuesses()
{
    return this->numberOfWrongGuesses;
}

int Game::GetTotalPointsPossible()
{
    return GetPointsForSet(fullSetOfCorrectWords);
}

int Game::GetPointsForSet(const std::set<std::string>& wordList)
{
    int temp = 0;
    std::set<std::string>::iterator it = wordList.begin();
    while(it != wordList.end())
    {
        temp = temp + GetWordScore(*it);
        it++;
    }
    return temp;
}

std::string Game::GetAllWords()
{
    std::string temp;
    std::set<std::string>::iterator it = fullSetOfCorrectWords.begin();
    while(it != fullSetOfCorrectWords.end())
    {
        temp = temp + (*it) + '\n';
        it++;
    }
    return temp;
}

