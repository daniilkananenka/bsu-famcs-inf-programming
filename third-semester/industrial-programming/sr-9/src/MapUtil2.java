import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;

public class MapUtil2 {
    public Map<Integer, TreeSet<String>> makeMap(String[] words) {
        Map<Integer, TreeSet<String>> lengthMap = new TreeMap<>();
        for (String word : words) {
            int length = word.length();
            lengthMap.putIfAbsent(length, new TreeSet<>());
            lengthMap.get(length).add(word);
        }
        return lengthMap;
    }
}