#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <iomanip>
#include "languageAnalyser.h"

using namespace std;




//static class Lexicography
//{
//private:
//
//	
//
//	
//public:
//
//	static void phraseCongruency(vector<string> phrases)
//	{
//		string text = "";
//		vector<pair<string, vector<string>>> crossList;
//		vector<pair<string, int>> wordFreqList;
//
//		for(int phraseIter = 0; phraseIter < phrases.size(); phraseIter++)
//		{
//			text += (" " + phrases[phraseIter]);
//		}
//
//		wordFreqList = wordFrequency(text);
//		vector<string> wordList;
//
//		for(int wordIter = 0; wordIter < wordFreqList.size(); wordIter++)
//		{
//			wordList.push_back(wordFreqList[wordIter].first);
//		}
//
//		crossList = phraseCrossReference(phrases, wordList);
//		vector<pair<string , vector<string>>> phraseList; 
//
//		//vector<pair<vector<string>, vector<string>>> phraseCon;
//		
//
//		for(int phraseIter = 0; phraseIter < phrases.size; phraseIter++)
//		{
//			
//		}
//
//			int match =0;;
//			for(int wgIter1 = 0; wgIter1 < phraseCon.size(); wgIter1++)
//			{
//				for(int wgIter2 = 0; wgIter2 < phraseCon.size(); wgIter2++)
//				{
//					//cout << phraseCon[wgIter1] << " " << phraseCon[wgIter2] << endl;
//					
//					/*if(match == phraseCon[wgIter1].first.size() && wgIter1 != wgIter2)
//					{
//						for(int phraseIter = 0; phraseIter < phraseCon[wgIter2].second.size(); phraseIter++)
//						{
//							phraseCon[wgIter1].second.push_back(phraseCon[wgIter2].second[phraseIter]);
//						}
//						phraseCon.erase(phraseCon.begin() + wgIter2);
//						if(wgIter2 < wgIter1)
//						{
//							wgIter1--;
//						}
//						wgIter2 = 0;
//						ofstream file("test.txt");
//
//						for(int wgIter = 0; wgIter < phraseCon.size(); wgIter++)
//						{
//							for(int wordIter = 0; wordIter < phraseCon[wgIter].first.size(); wordIter++)
//							{
//								file << phraseCon[wgIter].first[wordIter] << " ";
//							}
//							file << endl;
//							for(int phraseIter = 0; phraseIter < phraseCon[wgIter].second.size(); phraseIter++)
//							{
//								file << "	" << phraseCon[wgIter].second[phraseIter] << endl;
//							}
//							file << endl;
//						}
//
//						file.close();
//					}*/
//				}
//			}
//
//
//
//			
//	}
//	
//	static vector<pair<string, int>> wordFrequency(string text)
//	{
//		unordered_map <string,int> wordFreq;
//		string word = "";
//
//		for(int i = 0; i < text.length(); i++)
//		{
//			if((text[i] == ' ' || text[i] == '!' || text[i] == '?' || text[i] == '.') && word.length() <= 0)
//			{
//
//			}else if((text[i] == ' ' || text[i] == '!' || text[i] == '?' || text[i] == '.') && word.length() > 0)
//			{
//				const int length = word.length();
//					for(int lowerIter = 0; lowerIter < length; ++lowerIter)
//					{
//						word[lowerIter] = std::tolower(word[lowerIter]);
//					}
//				wordFreq[word]++;
//				word = "";
//			}else
//			{
//				word += text[i];
//			}
//		}
//
//		int size = wordFreq.size();
//		vector <pair<string, int>> sortedWordFreq;
//
//		int max = -1;
//		unordered_map<string, int>::iterator maxIndex;
//		int orderedArrayIndex = 0;
//		while(orderedArrayIndex < size){
//			max = -1;
//			for(unordered_map<string, int>::iterator iter = wordFreq.begin(); iter != wordFreq.end(); ++iter)
//			{
//				if(max < iter->second)
//				{
//					maxIndex = iter;
//					max = iter->second;
//				}
//			
//			}
//			sortedWordFreq.push_back(*maxIndex);
//			maxIndex->second = 0;
//			orderedArrayIndex++;
//		}
//
//		return sortedWordFreq;
//	}
//
//	static vector<pair<string, vector<string>>> phraseCrossReference(vector<string> phrases, vector<string> wordList)
//	{
//		vector <pair <string, vector<string>>> ref;
//		for(int wordIter = 0; wordIter < wordList.size(); wordIter++)
//		{
//			vector<string> tmp;
//			ref.push_back(pair<string, vector<string>>(wordList[wordIter], tmp));
//
//			for(int phraseIter = 0; phraseIter < phrases.size(); phraseIter++)
//			{
//				if(Lexicography::findWordInPhrase(ref[wordIter].first, phrases[phraseIter]) != string::npos)
//				{
//					ref[wordIter].second.push_back(phrases[phraseIter]);
//				}
//			}
//		}
//		return ref;
//	}
//
//};

int main()
{
	string line = "";

	vector <string> englishPhrases;
	vector <string> creolePhrases;

	string englishText = "";
	string creoleText = "";

	ifstream txtfile;
	
	txtfile.open("phrases.txt");

	if(txtfile.is_open())
	{
		while(getline(txtfile, line))
		{
			int punctPos;

			if(line.find_first_of(".") != string::npos)
			{
				punctPos = line.find_first_of(".");
			}

			if(line.find_first_of("!") != string::npos)
			{
				punctPos = line.find_first_of("!");
			}

			if(line.find_first_of("?") != string::npos)
			{
				punctPos = line.find_first_of("?");
			}

			string english, creole;

			english = line.substr(0, punctPos + 1);
			creole = line.substr(punctPos + 1, line.size() - punctPos);

			englishPhrases.insert(englishPhrases.begin(), english);
			creolePhrases.insert(creolePhrases.begin(), creole);

			englishText += english;
			creoleText += creole;
		}
		txtfile.close();
	}

	languageAnalyser* lanAna = new languageAnalyser(creoleText);

	txtfile.open("LessonWords.txt");

	line = "";

	vector<string> words;
	while(getline(txtfile, line))
	{
		for(int wordIter = 0; wordIter < line.size(); ++wordIter)
			{
				line[wordIter] = tolower(line[wordIter]);
			}
		words.push_back(line);
	}

	txtfile.close();
	
	vector<string> phraseCon = lanAna->phraseCongruency(words);
	
	ofstream lessonPhrases("LessonPhrases.txt");
	
	for(vector<string>::iterator i = phraseCon.begin(); i != phraseCon.end(); ++i)
	{
		cout << *i << endl;
		lessonPhrases << *i << endl;
	}

	lessonPhrases.close();
	//Lexicography::phraseCongruency(creolePhrases);

	//vector <pair<string, int>> wordFreqList = Lexicography::wordFrequency(creoleText);

	////for( int count = 0; count < wordFreqList.size(); count++)
	////{
	////	cout << wordFreqList[count].first << " " << wordFreqList[count].second << endl;
	////}

	//vector <string> wordList;
	//for(int i = 0; i < wordFreqList.size(); i++)
	//{
	//	wordList.push_back(wordFreqList[i].first);
	//}

	//vector <pair<string, vector<string>>> cross = Lexicography::phraseCrossReference(creolePhrases, wordList);

	////for(int wordIter = 0; wordIter < cross.size(); wordIter++)
	////{
	////	cout << cross[wordIter].first << endl;
	////	for(int phraseIter = 0; phraseIter < cross[wordIter].second.size(); phraseIter++)
	////	{
	////		cout << cross[wordIter].second[phraseIter] << endl;
	////	}
	////}


	////ofstream englishPhraseFile("englishPhrases.txt");
	//ofstream creolePhraseFile("creolePhrases.txt");
	////ofstream phraseDictionary("dictionary.txt");
	////
	////ofstream creoleWordFile("creoleWords.txt");
	//ofstream creoleFreqFile("creoleFreq.txt");
	////ofstream creoleCrossFile("creoleCross.txt");
	////

	////for(int wordIter = 0; wordIter < cross.size(); wordIter++)
	////{
	////	creoleCrossFile << cross[wordIter].first << endl;
	////	for(int phraseIter = 0; phraseIter < cross[wordIter].second.size(); phraseIter++)
	////	{
	////		creoleCrossFile << cross[wordIter].second[phraseIter] << endl;
	////	}
	////}

	//creoleFreqFile.setf(ios::left);
	//creoleFreqFile.width(12);
	//for(int i = 0; i < wordFreqList.size(); i++)
	//{
	//	string s = "";
	//	if(!cross[i].second.empty())
	//	{
	//		s = cross[i].second[0];
	//	}
	//	
	//	creoleFreqFile << wordFreqList[i].first << "		_____________________________	"   << s << endl << endl;
	//}

	//creolePhraseFile.setf(ios::left);
	//for(int i = 0; i < creolePhrases.size(); i++)
	//{
	//	creolePhraseFile << creolePhrases[i] << endl << endl << "_____________________________________________________________________" << endl << endl;
	//}
	//

	//// englishPhraseFile.close();
	// creolePhraseFile.close();
	//// creoleWordFile.close();
	// creoleFreqFile.close();
	//// creoleCrossFile.close();
	//// phraseDictionary.close();
	cout << "Done";
	return 0;
}

//if a word in the phrase is not in the word list discard the phrase.
//else keep the phrase.



