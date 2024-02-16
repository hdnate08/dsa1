#include "dictionary.hpp"

Dictionary::Dictionary()
{
	std::ifstream inFS;
	inFS.open("words.txt");
	std::string temp;
	
	while(!inFS.eof())
	{
		getline(inFS, temp);
		this->dictionary.insert(temp);
	}
}

bool Dictionary::IsWord(std::string word)
{
	if(dictionary.find(word) == dictionary.end()) 
	{
		return false;	
	}
	return true;
}
