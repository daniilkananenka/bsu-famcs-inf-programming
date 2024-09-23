import java.util.Scanner;

public class Program {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Input n: ");
    int n = scanner.nextInt();

    double[][] a = new double[n][n];
    double[] b = new double[n];
    double[] x = new double[n];

    System.out.println("Input matrix A:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = scanner.nextDouble();
      }
    }

    System.out.println("Input vector B:");
    for (int i = 0; i < n; i++) {
      b[i] = scanner.nextDouble();
    }

    for (int i = n - 1; i >= 0; i--) {
      x[i] = b[i];
      for (int j = i + 1; j < n; j++) {
        x[i] -= a[i][j] * x[j];
      }
      x[i] /= a[i][i];
    }

    System.out.println("Solving:");
    for (int i = 0; i < n; i++) {
      System.out.printf("x%d = %.2f\n", i + 1, x[i]);
    }
  }
}