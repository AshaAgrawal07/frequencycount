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

using namespace std;

int main() {

    //dictionary will contain the word as the key and its frequency as the value
    map<string, int> dictionary;

    //read the words in the file
    string word, file;
    getline(cin, file);
    stringstream stream(file);

    //go through each word of the file and put it into the dictionary
    while (!stream.eof()) {
        stream >> word;

        //first check if word exists in the dictionary
        // if it does, the increment value; else add key and value of 1 to dicitonary
        map<string, int>::iterator it;
        it = dictionary.find(word);
        dictionary[word]++;
        if (it == dictionary.end()) {
            //if the word doesnt already exist in the dictionary, then a new K,V is made, with V=0, so I need to increment it again
            dictionary[word]++;
        }
    }
}
string checkValidityAndUpdate(string line) {
    //check that the line isnt just null or a bunch of whiteshpace
    if (regex_match(line, "[\\s]+")) {
        throw invalid_argument("INVALID INPUT");
    } else {
        if (line == NULL || line.length() == 0) {
            throw invalid_argument("INVALID INPUT");
        }
    }

    //split over non-word characters
    //this means that if there is an apostraphe, then the stuff after the ' will be considered a word
    vector<string> splittedString = line.split("[\\s\\W]+");

    for (string s : splittedString) {
        string toCheck = s;
        //if the specific word already exists in the dictionary, then update, or else add the word to the dictionary

        if (dictionary.containsKey(toCheck)) {
            dictionary.put(toCheck, dictionary.get(toCheck) + 1);
        } else {
            dictionary.put(toCheck, 1);
        }
    }
    return "Dictionary updated successfully";
}
