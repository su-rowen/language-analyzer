#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
#include "phrase.h"

class languageAnalyser
{

private:

	int _wordCount;
	std::string rawInput;
	std::string cleanInput;
	std::vector<phrase*> phraseList;
	std::vector<std::string> wordList;
	std::vector<std::pair<std::string*, int>*> wordFreqList;	//string*, int pair to store pointer to word and number of recurances
	std::vector<std::pair<std::string*, std::vector<phrase*>*>*> wordPhraseCrossReference; //string*, vector<phrase*>  pair holds pointers to words and pointers to phrases they are found in 
	

	//functions
	int wordCount(std::string str);
	std::string removeNonStandardCharacters(std::string input);	//removes all ascii characters except Letters and punct
	void populatePhraseList();		//splits string on puntutation characters places them into a vector of phrase classes
	void populateWordList();	//populates wordList and word Frequency
	void crossReferencePhrases();	//cross reference phrases with the words in the word List
	bool isAlpha(char c);
	bool isPunct(char c);
	bool isSpace(char c);
	void insertIntoWordList(std::string word);
	



	
	
public:
	languageAnalyser(std::string input);
	std::vector<std::string> phraseCongruency(std::vector<std::string> words); //returns phrases made up of only the words in the list
};
