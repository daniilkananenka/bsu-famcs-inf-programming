
import java.util.Arrays;
import java.util.Scanner;

public class GenericFiveTask {
  public static void main(String[] args) {
    Integer[] arr = { 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15 };
    try (Scanner scanner = new Scanner(System.in)) {
      Integer userIn = scanner.nextInt();
      System.out.println(has(arr, userIn) ? "Contains" : "Not contains");
    }
  }

  public static <T> Boolean has(T[] arr, T value) {
    return Arrays.asList(arr).contains(value);
  }
}
