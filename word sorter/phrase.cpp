#include "phrase.h"
//phrase class constructor

phrase::phrase(std::string phraseInput)
{
	phraseStr = phraseInput;
	_wordCount = 0;

	std::string word = "";
	for(int i = 0; i < phraseStr.size(); i++)
	{
		if((phraseStr[i] == ' ' || phraseStr[i] == '!' || phraseStr[i] == '?' || phraseStr[i] == '.') && word != "")
		{
			for(int wordIter = 0; wordIter < word.size(); ++wordIter)
			{
				word[wordIter] = tolower(word[wordIter]);
			}

			wordsInPhrase.push_back(word);	//add word to wordList
			_wordCount++;
			word = "";
		}else if(!(phraseStr[i] == ' ' || phraseStr[i] == '!' || phraseStr[i] == '?' || phraseStr[i] == '.'))
		{
			word += phraseStr[i];
		}
	}
}
		
std::string phrase::ToString()
{
	return phraseStr;
}

//overload the [] operator to return word at that position.
std::string& phrase::operator[] (const int Index)
{
	return wordsInPhrase[Index];
}

int phrase::findWord(std::string str)
{
	for(int i = 0; i < wordsInPhrase.size(); i++)
	{
		if(wordsInPhrase[i] == str)
		{
			return i;
		}
	}
	return std::string::npos;
}