//
// Created by Asha Agrawal on 3/5/2018.
//

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

//dictionary will contain the word as the key and its frequency as the value
map<string, int> dictionary;

vector<pair<string, int>> SortMap(map<string, int> map);
void InputWords(vector<string> vector);
void CheckValidity(string basic_string);

int main() {


    locale loc;
    regex reg("\\s\\W+");

    //read the words in the file
    string file;
    vector<string> lines;
    while (cin) {
        getline(cin, file);
        CheckValidity(file);
        lines.push_back(file);
    }
    for (int i = 0; i < lines.size(); i++) {
        //split each line over non-alphabetical (-, ', " " etc) and store into a vector
        sregex_token_iterator iter(lines[i].begin(), lines[i].end(), reg, -1);
        sregex_token_iterator end;
        vector<string> words(iter, end);

        InputWords(words);
    }

    //after getting all of the words and their frequencies, I want to sort from highest frequency to lowest
    vector<pair<string, int>> pairs;
    pairs = SortMap(dictionary);

    //now I want to output the top 10 words
    int n = 10;
    if (pairs.size() < 10) {
        n = pairs.size();
    }
    for (int i = 0; i < n; i++) {
        cout << "Word:  " << pairs[i].first << "  Frequency:  " << pairs[i].second << endl;

    }
    return 0;
}

/**
 * checks that the file/line is not null or just a bunch of whitespace
 * @param file a line from the file
 */
void CheckValidity(string file) {

    regex reg("\\s+");
    sregex_token_iterator iter(file.begin(), file.end(), reg, -1);
    sregex_token_iterator end;
    vector<string> lines(iter, end);

    if (lines.size() == 0) {
        throw std::invalid_argument("INVALID INPUT");
    }
}

/**
 * this function will go through each word of the vector and then add it accordingly to the dictionary
 * @param words the vector of strings which contains words
 */
void InputWords(vector<string> words) {
    //go through each word of the file and put it into the dictionary
    locale loc;
    for (int j = 0; j < words.size(); j++) {
        //for each splittedword, we want to do the following:
        //consider everything as case insensitive, so all words will be converted to lower case
        string word_to_lower = "";
        word_to_lower += tolower(words[j], loc);

        //first check if word exists in the dictionary
        // if it does, the increment value; else add key and value of 1 to dicitonary
        map<string, int>::iterator it;
        it = dictionary.find(word_to_lower);
        dictionary[word_to_lower]++;
        if (it == dictionary.end()) {
            //if the word doesnt already exist in the dictionary, then a new K,V is made, with V=0, so I need to increment it again
            dictionary[word_to_lower]++;
        }
    }
}

/**
 * i used this link:  https://stackoverflow.com/questions/5056645/sorting-stdmap-using-value
 * @param dictionary which contains all of the words and their frequencies
 * @return the vector of sorted pairs such that the word-frequency pair with the highest frequency is first
 */
vector<pair<string, int>> SortMap(map<string, int> dictionary) {
    vector<pair<string, int>> pairs;
    for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
        pairs.push_back(*itr);

    sort(pairs.begin(), pairs.end(), [=](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });
    return pairs;
}


//------------------------
//------TEST CASES--------
//------------------------

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("testEmptyInput:  ends with throwing exception: ", "[fail]") {
    CheckValidity("");
    FAIL();
}

TEST_CASE("testMultipleSpacesInput:  ends with throwing exception: ", "[fail]") {
    CheckValidity("       ");
    FAIL();
}

TEST_CASE("testNewLineInput:  ends with throwing exception: ", "[fail]") {
    CheckValidity("\n");
    FAIL();
}

TEST_CASE("testTabInput:  ends with throwing exception: ", "[fail]") {
    CheckValidity("\t");
    FAIL();
}

TEST_CASE("sortMap size is correct",  "[require]")
{
    map<string, int> dictionary;
    dictionary.insert(std::pair<string, int>("a", 20));
    dictionary.insert(std::pair<string, int>("hi", 2));
    dictionary.insert(std::pair<string, int>("then", 5));

    vector<pair<string, int>> output = SortMap(dictionary);
    REQUIRE(output.size() == 3);
}
TEST_CASE("sortMap sorted properly",  "[require]")
{
    map<string, int> dictionary;
    dictionary.insert(std::pair<string, int>("a", 20));
    dictionary.insert(std::pair<string, int>("hi", 2));
    dictionary.insert(std::pair<string, int>("then", 5));

    vector<pair<string, int>> output;
    output.push_back(std::pair<string, int>("a", 20));
    output.push_back(std::pair<string, int>("then", 5));
    output.push_back(std::pair<string, int>("hi", 2));
    REQUIRE(output == SortMap(dictionary));
}




