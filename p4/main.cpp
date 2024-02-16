#include "game.hpp"
#include <iostream>
int main()
{
    std::string temp, guess;
    Game g;
    std::cout << "Enter a 16-character long string to run manual tests, or leave empty to get a random board: ";
    std::getline(std::cin, temp);

    if(temp.length() == 16)
    {
        g = Game(temp);
        std::cout << g.ShowBoard();
    }
    else
    {
        std::cout << g.ShowBoard();
    }
        
    std::cout << "Enter a word (q to quit): ";

    while(g.GetTotalPointsPossible() != g.GetScore())
    {   
        std::cin >> guess;
        if(guess != "q")
        {
            if(!g.Guess(guess))
            {
                std::cout << '\t' << "Not worth any points" << std::endl;
            }
        }

        if(guess == "q" && g.GetScore() == 1 && g.GetIncorrectGuesses() == 1)
        {
            std::cout << "You got " << g.GetScore() << " point and had " << g.GetIncorrectGuesses() << " incorrect guess." << std::endl;
            std::cout << "There were " << g.GetTotalPointsPossible() << " points possible" << std::endl;  
            std::cout << "============================================================" << std::endl;
            std::cout << g.GetAllWords();
            return 0;
        }
        else if(guess == "q" && g.GetScore() != 1 && g.GetIncorrectGuesses() == 1)
        {
            std::cout << "You got " << g.GetScore() << " points and had " << g.GetIncorrectGuesses() << " incorrect guess." << std::endl;
            std::cout << "There were " << g.GetTotalPointsPossible() << " points possible" << std::endl;
            std::cout << "============================================================" << std::endl;
            std::cout << g.GetAllWords();
            return 0;
        }
        else if(guess == "q" && g.GetScore() != 1 && g.GetIncorrectGuesses() != 1)
        {
            std::cout << "You got " << g.GetScore() << " points and had " << g.GetIncorrectGuesses() << " incorrect guesses." << std::endl;
            std::cout << "There were " << g.GetTotalPointsPossible() << " points possible" << std::endl;
            std::cout << "============================================================" << std::endl;
            std::cout << g.GetAllWords();
            return 0;
        }
        

        if(g.GetTotalPointsPossible() == g.GetScore())
        {
            std::cout << "Congratulations! You achieved " << g.GetScore() << " out of " << g.GetTotalPointsPossible() << " possible points!" << std::endl;
            std::cout << "You got " << g.GetScore() << " point and had " << g.GetIncorrectGuesses() << " incorrect guess." << std::endl;
            std::cout << "There were " << g.GetTotalPointsPossible() << " points possible" << std::endl;
            return 0;
        }
    
        std::cout << "Enter a word: ";    
    }

    return 0;
}
