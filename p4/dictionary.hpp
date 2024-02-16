#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#include <unordered_set>
#include <string>
#include <fstream>

class Dictionary
{
	public:
		Dictionary();
		bool IsWord(std::string word);
	private:
		std::unordered_set<std::string> dictionary;
};
#endif
