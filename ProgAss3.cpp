#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<algorithm>
#include "MyHash.h"
#include "timer.h"
using namespace std;

vector<string> readDictionary() {
    ifstream infile;
	vector<string> words;
	string word;
	infile.open("dict.txt");
    long int count = 0;
	if (infile.is_open()) {
		infile >> word;
		while (!infile.eof()) {
			words.push_back(word);
            count++;
			infile >> word;
		}
	}
	infile.close();
    return words;
}

void cleanWord(string &word) {
    int length = word.size();
    char temp;
    for(int i=0; i<length; i++){
        temp = word[i];
        if(isalpha(temp)){
            if(isupper(temp)){
                word[i] = tolower(temp);
            }
        }
        else if((isdigit(temp)) ||(temp == '\'') ){ }
        else{
            word = word.erase(i, 1);
            length = word.size();
            i--;
        }

    }

}

int main() {
    int skip = 0;
    long  int correctSpell = 0;
	long  int wrongSpell = 0;
	double foundAvg = 0;
	double notFoundAvg = 0;
    string word, bookWords;
	vector<string> dictWords = readDictionary();
	myHash<string> dictionary;
    Timer timer;
    ifstream infile;
    ofstream outfile;
	infile.open("book.txt");
	outfile.open("misspelled.txt");

    for(int i=0; i < dictWords.size(); i++){
        cleanWord(dictWords[i]);
        dictionary.insert(dictWords[i]);
    }
	cout << "Dictionary Size: " << dictionary.getSize() << "\n";

	if (infile.is_open()) {
		timer.Start();
		infile >> bookWords;
		while (!infile.eof()){
			cleanWord(bookWords);
			if(bookWords.compare("") == 0){ }
			else  if (!isalpha(bookWords[0])){
				skip++;
			}
		    else if (dictionary.find(bookWords)){
				correctSpell++;
			}
			else{
				outfile << bookWords << "\n";
				wrongSpell++;
			}
			infile >> bookWords;
		}
		timer.Stop();
	}
    infile.close();
	outfile.close();

    foundAvg = (dictionary.foundCompare/correctSpell);
	notFoundAvg = (dictionary.notFoundCompare/wrongSpell);

	cout<< "Done Checking and these are the results\n";
	cout<< "Finished in time: " << timer.Time() << "\n";
	cout<<"Finished in Milliseconds Time: " << timer.TimeMS() << "\n";
	cout << "There are " << correctSpell << " words found in the dictionary\n\t";
	cout<< dictionary.foundCompare << " compares. Average: " << foundAvg << "\n";
	cout << "There are " << wrongSpell << " words NOT found in the dictionary\n\t";
	cout << dictionary.notFoundCompare << " compares. Average: " << notFoundAvg << "\n";
	cout << "There are " << skip << " words not checked." << "\n";

    return 0;
}