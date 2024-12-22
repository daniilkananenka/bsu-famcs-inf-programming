import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class SetUtil2 {
    public static List<Set<String>> uniqueInEach(String[] words1, String[] words2) {
        Set<String> set1 = new TreeSet<>();
        Set<String> set2 = new TreeSet<>();
        for (String word : words1) {
            set1.add(word);
        }
        for (String word : words2) {
            set2.add(word);
        }
        Set<String> uniqueToWords1 = new TreeSet<>(set1);
        uniqueToWords1.removeAll(set2);
        Set<String> uniqueToWords2 = new TreeSet<>(set2);
        uniqueToWords2.removeAll(set1);
        List<Set<String>> result = new ArrayList<>();
        result.add(uniqueToWords1);
        result.add(uniqueToWords2);
        return result;
    }
}