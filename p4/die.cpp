#include "die.hpp"
#include <ctime>
Die::Die()
{
    this->possibleLetters[6] = {'a'};
}

Die::Die(std::string possibleLetters)
{
	for(int i = 0; i < 6; ++i)
	{
		this->possibleLetters[i] = possibleLetters[i];
	}
}

Die& Die::operator=(const Die& rhs)
{
    for(int i = 0; i < 6; ++i)
    {
        this->possibleLetters[i] = rhs.possibleLetters[i];
    }
    return *this;
}

char Die::Roll()
{
	std::srand(time(0));
	return possibleLetters[rand() % 6];	
}
