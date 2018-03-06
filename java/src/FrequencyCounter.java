import java.util.*;

/**
 * will count the frequency of words based on a text file that will be provided through command line
 * i will assume that words after and before interword-punctuation counts as words
 */
public class FrequencyCounter {

    private static HashMap<String, Integer> dictionary = new HashMap<String, Integer>();

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.println("Input URL:  ");
        String url = scan.nextLine();
        String line = LinkParse.parse(url);
        System.out.println("parsing link");

        /*while (scan.hasNextLine()) {
            String line = scan.nextLine();
            String s = checkValidityAndUpdate(line.trim());
        }*/

        String s = checkValidityAndUpdate(line.trim());
        //now that everything has been read and put into the dictionary, sort it
        //using link:  https://stackoverflow.com/questions/21054415/how-to-sort-a-hashmap-by-the-integer-value
        Object[] frequencyWords = dictionary.entrySet().toArray();
        Arrays.sort(frequencyWords, new Comparator() {
            public int compare(Object o1, Object o2) {
                return ((Map.Entry<String, Integer>) o2).getValue()
                        .compareTo(((Map.Entry<String, Integer>) o1).getValue());
            }
        });

        //output the first 10
        int counter = 0;
        System.out.println("Top 10 frequency words:");
        Iterator iterator = dictionary.entrySet().iterator();
        for (Object topFrequency : frequencyWords) {
            if (counter < 10) {
                System.out.println("Word:  " + ((Map.Entry<String, Integer>) topFrequency).getKey() + "  Frequency: "
                        + ((Map.Entry<String, Integer>) topFrequency).getValue());
                counter++;
            } else {
                break;
            }
        }
    }

    public static String checkValidityAndUpdate(String line) {
        //check that the line isnt just null or a bunch of whiteshpace
        if (line == null || line.length() == 0 || line.matches("[\\s]+")) {
            throw new IllegalArgumentException("INVALID INPUT");
        }

        //split over non-word characters
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
        return "Dictionary updated successfully";
    }
}
