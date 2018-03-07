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
map<string, int> dictionary;

vector<pair<string, int>> sortMap(map<string, int> map);

void inputWords(vector<string> vector);

void checkValidity(string basic_string);

int main() {

    //dictionary will contain the word as the key and its frequency as the value

    locale loc;
    regex reg("\\s+");

    //read the words in the file
    string file;
    vector<string> lines;
    while (cin) {
        getline(cin, file);
        checkValidity(file);
        lines.push_back(file);
    }
    for (int i = 0; i < lines.size(); i++) {
        //split each line over non-alphabetical (-, ', " " etc) and store into a vector
        sregex_token_iterator iter(lines[i].begin(), lines[i].end(), reg, -1);
        sregex_token_iterator end;
        vector<string> words(iter, end);

        inputWords(words);
    }

    //after getting all of the words and their frequencies, I want to sort from highest frequency to lowest
    vector<pair<string, int>> pairs;
    pairs = sortMap(dictionary);

    //now I want to output the top 10 words
    int n = 10;
    if (pairs.size() < 10) {
        n = pairs.size();
    }
    for (int i = 0; i < n; i++) {
        cout << "Word:  " << pairs[i].first << "  Frequency:  " << pairs[i].second << endl;

    }
}

void checkValidity(string file) {
    if (file == NULL|| file.) {

    }
}

/**
 * this function will go through each word of the vector and then add it accordingly to the dictionary
 * @param words the vector of strings which contains words
 */
void inputWords(vector<string> words) {
    //go through each word of the file and put it into the dictionary
    locale loc;
    for (int j = 0; j < words.size(); j++) {
        //for each splittedword, we want to do the following:
        //consider everything as case insensitive, so all words will be converted to lower case
        string wordToLower = "";
        wordToLower += tolower(words[j], loc);

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

/**
 * i used this link:  https://stackoverflow.com/questions/5056645/sorting-stdmap-using-value
 * @param dictionary which contains all of the words and their frequencies
 * @return the vector of sorted pairs such that the word-frequency pair with the highest frequency is first
 */
vector<pair<string, int>> sortMap(map<string, int> dictionary) {
    vector<pair<string, int>> pairs;
    for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
        pairs.push_back(*itr);

    sort(pairs.begin(), pairs.end(), [=](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });
    return pairs;
}



