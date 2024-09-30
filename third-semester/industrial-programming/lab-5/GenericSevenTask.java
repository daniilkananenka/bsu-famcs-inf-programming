import java.util.function.Predicate;

public class GenericSevenTask {
  public static void main(String[] args) {
    Integer[] arr = { 1, 2, 3, 4, 5, 10, 11, 12, 10, 13, 14, 15 };

    // Less than 10
    Predicate<Integer> pred = i -> i < 10;
    System.out.println("Count: " + count(arr, pred));
  }

  public static <T> Integer count(T[] arr, Predicate<T> pred) {
    int counter = 0;
    for (T el : arr) {
      if (pred.test(el))
        counter++;
    }
    return counter;
  }
}
