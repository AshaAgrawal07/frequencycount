//
// Created by Asha Agrawal on 3/5/2018.
//

#include "FrequencyCount.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <regex>
#include <stdexcept>
#include <locale>
using namespace std;

int main() {

    //dictionary will contain the word as the key and its frequency as the value
    map<string, int> dictionary;
    locale loc;
    string delimiter = "/[]':;<>?!-_=+*@3$%^()~` ";

    //read the words in the file
    string word;
    ifstream file;
    stringstream stream(word);

    //go through each word of the file and put it into the dictionary
    while (file >> word) {
        stream >> word;
        //split each word over interword punctuation (-, ', etc) and store into a vector
        //if there is nothing to split over, then the vector will only hold the word itself
        stringstream ss(word);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> splittedWords(begin, end);

        //for each splittedword, we want to do the following:
        for (auto &word  : splittedWords) {

            //consider everything as case insensitive, so all words will be converted to lower case
            string wordToLower = "";
            for (int i = 0; i < word.length(); i++) {
                wordToLower += tolower(word[i], loc);
            }
            //first check if word exists in the dictionary
            // if it does, the increment value; else add key and value of 1 to dicitonary
            map<string, int>::iterator it;
            it = dictionary.find(wordToLower);
            dictionary[wordToLower]++;
            if (it == dictionary.end()) {
                //if the word doesnt already exist in the dictionary, then a new K,V is made, with V=0, so I need to increment it again
                dictionary[wordToLower]++;
            }
        }
    }


    //after getting all of the words and their frequencies, I want to sort from highest frequency to lowest
    //i used this link:  https://stackoverflow.com/questions/5056645/sorting-stdmap-using-value
    vector<pair<string, int>> pairs;
    for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
        pairs.push_back(*itr);

    sort(pairs.begin(), pairs.end(), [=](pair<int, int>& a, pair<int, int>& b)
    {
        return a.second < b.second;
    });

    //now I want to output the top 10 words
    int n = 10;
    if (pairs.size() < 10) {
        n = pairs.size();
    }
    for(int i = 0; i < n; i++) {
        cout << "Word:  "<< pairs[i].first << "  Frequency:  " << pairs[i].second << endl;

    }
    file.close();
}

