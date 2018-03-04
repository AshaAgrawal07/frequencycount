import java.util.*;

public class FrequencyCounter {

    /**
     *used this link:  https://stackoverflow.com/questions/109383/sort-a-mapkey-value-by-values?rq=1
     *
     * @param toSort the map which we want to sort based on the values (frequency of each key [word])
     * @return the sorted map such that the words in the beginning have the lower frequency
     */
    public <String, Integer extends Comparable<? super Integer>>Map<String, Integer> sort(Map<String, Integer> toSort) {
        List<Map.Entry<String, Integer>> list = new LinkedList<Map.Entry<String, Integer>>(toSort.entrySet());
        Collections.sort( list, new Comparator<Map.Entry<String, Integer>>() {
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return (o1.getValue()).compareTo( o2.getValue() );
            }
        });

        Map<String, Integer> result = new LinkedHashMap<>();
        for (Map.Entry<String, Integer> entry : list) {
            result.put(entry.getKey(), entry.getValue());
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        while(scan.hasNextLine()) {
            String line = scan.nextLine();
            //split over a space
            String[] splittedString = line.split(" ");
            for (String s : splittedString) {
                if (s.matches("[\\W]")) {
                    String[] splittedWord = s.split("[\\W]");
                    for (String w: splittedWord) {

                    }
                }
            }
        }
    }
}
