import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Integer[] arr = { 1, 2, 3, 4, 5, 10, 11, 12, 10, 13, 14, 15 };
        try (Scanner scanner = new Scanner(System.in)) {
            Integer userIn = scanner.nextInt();
            System.out.println("Count: " + count(arr, userIn));
        }
    }

    public static <T> Integer count(T[] arr, T value) {
        int counter = 0;
        for (T el : arr) {
            if (el == value)
                counter++;
        }
        return counter;
    }
}