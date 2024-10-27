import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Integer[] arr = { 1, 2, 3, 4, 5, 10, 11, 12, 10, 13, 14, 15 };
        System.out.println("Average: " + sum(arr));
    }

    public static <T extends Number> double sum(T[] arr) {
        return Arrays.stream(arr).mapToDouble(Number::doubleValue).sum() / arr.length;
    }
}