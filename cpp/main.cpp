//
// Created by Asha Agrawal on 3/3/2018.
//

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

hashMap sort(hashMap map) {
    List list = new LinkedList(map.entrySet());
    // Defined Custom Comparator here
    Collections.sort(list, new Comparator()
    {
        int compare(Object o1, Object o2) {
            return ((Comparable)((Map.Entry)(o2)).getValue())
                    .compareTo(((Map.Entry)(o1)).getValue());
        }
    });

    // Here I am copying the sorted list in HashMap
    // using LinkedHashMap to preserve the insertion order
    HashMap sortedHashMap = new LinkedHashMap();
    for (Iterator it = list.iterator(); it.hasNext();) {
        Map.Entry
        entry = (Map.Entry)
        it.next();
        sortedHashMap.put(entry.getKey(), entry.getValue());
    }
    return sortedHashMap;
}

int main() {
    Scanner scan = new Scanner(System.in);

    while (scan.hasNextLine()) {
        String line = scan.nextLine();
        String s = checkValidityAndUpdate(line.trim());
    }
    //now that everything has been read and put into the dictionary, sort it
    sortByValues(dictionary);

    //output the first 10
    StringBuilder stringBuilder = new StringBuilder();
    stringBuilder.append("Top 10 frequency words:");
    Iterator iterator = dictionary.entrySet().iterator();
    for (int i = 0; i < 10; i++) {
        Map.Entry highestFrequency = (Map.Entry) iterator.next();
        stringBuilder.append("\nWord:  " + highestFrequency.getKey() + "  # of Times:  " + highestFrequency.getValue());
    }
    stringBuilder.toString();
}

static String checkValidityAndUpdate(String line) {
    //check that the line isnt just null or a bunch of whiteshpace
    if (line == null || line.length() == 0 || line.matches("[\\s]+")) {
        throw new IllegalArgumentException("INVALID INPUT");
    }

    //split over non-word characters
    //this means that if there is an apostraphe, then the stuff after the ' will be considered a word
    vector <String> splittedString = line.split("[\\s\\W]+");

    for (String s : splittedString) {
        String toCheck = s.toLowerCase();
        //if the specific word already exists in the dictionary, then update, or else add the word to the dictionary

        if (dictionary.containsKey(toCheck)) {
            dictionary.put(toCheck, dictionary.get(toCheck) + 1);
        } else {
            dictionary.put(toCheck, 1);
        }
    }
    return "Dictionary updated successfully";
}
