import java.util.Scanner;

public class GenericForthTask {
  public static void main(String[] args) {
    Integer[] arr = { 1, 2, 3, 4, 5, 10, 11, 12, 10, 13, 14, 15 };
    try (Scanner scanner = new Scanner(System.in)) {
      Integer userIn = scanner.nextInt();
      System.out.println("Count: " + count(arr, userIn));
    }
  }

  public static <T extends Comparable<T>> Integer count(T[] arr, T value) {
    int counter = 0;
    for (T el : arr) {
      if (el.compareTo(value) > 0)
        counter++;
    }
    return counter;
  }
}
