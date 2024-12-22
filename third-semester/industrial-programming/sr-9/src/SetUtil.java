import java.util.Set;
import java.util.HashSet;

public class SetUtil {

    public static String check(String str) {
        Set<Character> vowels = new HashSet<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        vowels.add('A');
        vowels.add('E');
        vowels.add('I');
        vowels.add('O');
        vowels.add('U');

        return processSet(vowels, str);
    }

    public static String processSet(Set<Character> set, String str) {
        StringBuffer sb = new StringBuffer();

        for (int i = 0; i < str.length(); i++) {
            char currentChar = str.charAt(i);
            if (!set.contains(currentChar)) {
                sb.append(currentChar);
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        String input = "Hello World";
        String result = check(input);
        System.out.println("Input: " + input);
        System.out.println("Output: " + result);
    }
}