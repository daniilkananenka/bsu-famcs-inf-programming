import java.util.Set;
import java.util.TreeSet;

public class LetterSet {
    public Set<String> makeLetterSet(String str) {
        Set<String> letterSet = new TreeSet<>();
        for (char c : str.toCharArray()) {
            letterSet.add(String.valueOf(c));
        }
        return letterSet;
    }
}