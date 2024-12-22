import java.util.Map;
import java.util.TreeMap;

public class LetterMap {
    public Map<String, Integer> makeLetterMap(String str) {
        Map<String, Integer> freqs = new TreeMap<>();
        for (char c : str.toCharArray()) {
            String letter = String.valueOf(c);
            Integer count = freqs.get(letter);
            if (count == null) {
                freqs.put(letter, 1);
            } else {
                freqs.put(letter, count + 1);
            }
        }
        return freqs;
    }
}