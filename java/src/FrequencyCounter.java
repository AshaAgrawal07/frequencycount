import java.util.*;

/**
 * will count the frequency of words based on a text file that will be provided through command line
 * i will assume that words after and before interword-punctuation counts as words
 */
public class FrequencyCounter {

    /**
     *used this link:  https://beginnersbook.com/2013/12/how-to-sort-hashmap-in-java-by-keys-and-values/
     *
     * @param map the map which we want to sort based on the values (frequency of each key [word])
     * @return the sorted map such that the words in the beginning have the higher frequency
     */
    private static HashMap sortByValues(HashMap<String, Integer> map) {
        List list = new LinkedList(map.entrySet());
        // Defined Custom Comparator here
        Collections.sort(list, new Comparator() {
            public int compare(Object o1, Object o2) {
                return ((Comparable) ((Map.Entry) (o2)).getValue())
                        .compareTo(((Map.Entry) (o1)).getValue());
            }
        });

        // Here I am copying the sorted list in HashMap
        // using LinkedHashMap to preserve the insertion order
        HashMap sortedHashMap = new LinkedHashMap();
        for (Iterator it = list.iterator(); it.hasNext();) {
            Map.Entry entry = (Map.Entry) it.next();
            sortedHashMap.put(entry.getKey(), entry.getValue());
        }
        return sortedHashMap;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        HashMap<String, Integer> dictionary = new HashMap<String, Integer>();

        while(scan.hasNextLine()) {
            String line = scan.nextLine().trim();
            if(line == null) {
                System.out.println("invalid string input");
                break;
            }
            //split over a whitespace and non-word characters
            //this means that if there is an apostraphe, then the stuff after the ' will be considered a word
            String[] splittedString = line.split("[\\s\\W]+");

            for (String s : splittedString) {
                String toCheck = s.toLowerCase();
                //if the specific word already exists in the dictionary, then update, or else add the word to the dictionary

                if (dictionary.containsKey(toCheck)) {
                    dictionary.put(toCheck, dictionary.get(toCheck) + 1);
                } else {
                        dictionary.put(toCheck, 1);
                }
            }
        }
        //now that everything has been read and put into the dictionary, sort it
        sortByValues(dictionary);

        //output the first 10
        System.out.println("Top 10 frequency words:");
        Iterator iterator = dictionary.entrySet().iterator();
        for(int i = 0; i < 10; i++) {
            Map.Entry highestFrequency = (Map.Entry)iterator.next();
            System.out.println("Word:  " + highestFrequency.getKey() + "  # of Times:  " + highestFrequency.getValue());
        }
    }
}
