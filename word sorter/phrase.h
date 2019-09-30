#pragma once

#include <vector>
#include <string>

class phrase
{
private:
	std::string phraseStr;
	std::vector <std::string> wordsInPhrase;
	int _wordCount;

public:

	//overload the [] operator to return word at that position.
	std::string& operator[] (const int Index);

	//phrase class constructor

	int wordCount()
	{
		return _wordCount;
	}
	phrase(std::string phraseInput);
		
	std::string ToString();

	

	int findWord(std::string str);
};