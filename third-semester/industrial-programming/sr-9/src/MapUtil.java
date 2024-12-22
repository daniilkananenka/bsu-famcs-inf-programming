import java.util.Map;
import java.util.TreeMap;

public class MapUtil {
    public Map<String, Integer> makeMap(String[] words) {
        Map<String, Integer> wordMap = new TreeMap<>();
        for (String word : words) {
            wordMap.put(word, word.length());
        }
        return wordMap;
    }
}