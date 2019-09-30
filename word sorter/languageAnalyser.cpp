#include "languageAnalyser.h"


//private
int languageAnalyser::wordCount(std::string str)
{
	int wordCount;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == ' ' || str[i] == '!' || str[i] == '?' || str[i] == '.')
		{
			wordCount++;
		}
	}
	return wordCount;
}

bool languageAnalyser::isAlpha(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return true;
	}else
	{
		return false;
	}
}

bool languageAnalyser::isPunct(char c)
{
	if(c == '!' || c == '.' || c == '?')
	{
		return true;
	}else
	{
		return false;
	}
}

bool languageAnalyser::isSpace(char c)
{
	if(c == ' ')
	{
		return true;
	}else
	{
		return false;
	}
}

std::string languageAnalyser::removeNonStandardCharacters(std::string input)
{
	std::string cleanTmp = "";

	for(int i = 0; i < languageAnalyser::rawInput.size(); i++)
	{
		if(languageAnalyser::isAlpha(rawInput[i]) || languageAnalyser::isPunct(rawInput[i]) || languageAnalyser::isSpace(rawInput[i]))
		{
			cleanTmp += languageAnalyser::rawInput[i];
		}
	}
	return cleanTmp;
}

void languageAnalyser::populatePhraseList()
{
	std::string tmpPhraseInput = "";
	for(int i = 0; i < languageAnalyser::cleanInput.size(); i++)
	{
		if(languageAnalyser::isPunct(languageAnalyser::cleanInput[i]))
		{
			tmpPhraseInput += languageAnalyser::cleanInput[i];
			while(isSpace(tmpPhraseInput[0]))
			{
				tmpPhraseInput.erase(tmpPhraseInput.begin());
			}


			while(isSpace(tmpPhraseInput[tmpPhraseInput.size()]))
			{
				tmpPhraseInput.erase(tmpPhraseInput.end());
			}

			languageAnalyser::phraseList.push_back(new phrase(tmpPhraseInput));
			tmpPhraseInput = "";
		}else
		{
			tmpPhraseInput += languageAnalyser::cleanInput[i];
		}
	}
	
}

void languageAnalyser::populateWordList()
{
	
		std::unordered_map <std::string,int> wordFreq;
		std::string word = "";

		for(int i = 0; i < cleanInput.length(); i++)
		{
			if((cleanInput[i] == ' ' || cleanInput[i] == '!' || cleanInput[i] == '?' || cleanInput[i] == '.') && word.length() <= 0)
			{

			}else if((cleanInput[i] == ' ' || cleanInput[i] == '!' || cleanInput[i] == '?' || cleanInput[i] == '.') && word.length() > 0)
			{
				const int length = word.length();
					for(int lowerIter = 0; lowerIter < length; ++lowerIter)
					{
						word[lowerIter] = std::tolower(word[lowerIter]);
					}
				wordFreq[word]++;
				word = "";
			}else
			{
				word += cleanInput[i];
			}
		}

		int size = wordFreq.size();
		std::vector <std::pair<std::string, int>> sortedWordFreq;

		int max = -1;
		std::unordered_map<std::string, int>::iterator maxIndex;
		int orderedArrayIndex = 0;
		while(orderedArrayIndex < size){
			max = -1;
			for(std::unordered_map<std::string, int>::iterator iter = wordFreq.begin(); iter != wordFreq.end(); ++iter)
			{
				if(max < iter->second)
				{
					maxIndex = iter;
					max = iter->second;
				}
			
			}
			sortedWordFreq.push_back(*maxIndex);
			maxIndex->second = 0;
			orderedArrayIndex++;
		}

		for(int i = 0; i < sortedWordFreq.size(); ++i)
		{
			wordList.push_back(sortedWordFreq[i].first);
			wordFreqList.push_back(new std::pair<std::string*, int> (& wordList[i], sortedWordFreq[i].second));

		}

		
}

void languageAnalyser::crossReferencePhrases()
{
	for(std::vector<std::string>::iterator wordListIter = wordList.begin(); wordListIter != wordList.end(); ++wordListIter)
	{
		wordPhraseCrossReference.push_back(new std::pair<std::string *, std::vector<phrase*>*> (&(*wordListIter), new std::vector<phrase*>));
		for(std::vector<phrase*>::iterator phraseListIter = phraseList.begin(); phraseListIter != phraseList.end(); ++phraseListIter)
		{
			if((*phraseListIter)->findWord(*wordListIter) != std::string::npos)
			{
				wordPhraseCrossReference[wordListIter - wordList.begin()]->second->push_back((*phraseListIter));
			}
		}
	}
}


//public
languageAnalyser::languageAnalyser(std::string input)
{
	rawInput = input;
	cleanInput = languageAnalyser::removeNonStandardCharacters(languageAnalyser::rawInput);
	
	languageAnalyser::populatePhraseList();

	languageAnalyser::populateWordList();

	languageAnalyser::crossReferencePhrases();
		
}




std::vector<std::string> languageAnalyser::phraseCongruency(std::vector<std::string> words)
{
	std::vector<std::string> phrases;
	bool found = false;

	for(int phraseIter = 0; phraseIter < phraseList.size(); ++phraseIter)//loop through phrases
	{
		for(int wordInPhraseIter = 0; wordInPhraseIter < phraseList[phraseIter]->wordCount(); ++wordInPhraseIter)
		{
			int i = 0;
			while(i < words.size())// loop through word list
			{
				if((*phraseList[phraseIter])[wordInPhraseIter] == words[i])
				{
					found = true;
					i = words.size(); // break out of loop word found 
				}else
				{
					++i;
					found = false;
				}
			}
			if(!found)
			{
				wordInPhraseIter = phraseList[phraseIter]->wordCount(); // if one word is not found break out of loop if word is not found it disqualifies the entire phrase
			}
		}
		if(found)
		{
			phrases.push_back(phraseList[phraseIter]->ToString());
		}
	}


	return phrases;
}