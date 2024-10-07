package control;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class App {
  static final String INPUT_FILE_PATH = "/home/daniilkan/projects/bsu-famcs-inf-programming/third-semester/industrial-programming/lab-6/control/input.txt";
  static final String OUTPUT_FILE_PATH = "/home/daniilkan/projects/bsu-famcs-inf-programming/third-semester/industrial-programming/lab-6/control/output.txt";

  public static void main(String[] args) throws FileNotFoundException {
    Scanner scanner = new Scanner(new File(INPUT_FILE_PATH));
    PrintWriter writer = new PrintWriter(new File(OUTPUT_FILE_PATH));
    scanner.useLocale(Locale.US);

    double result = 0;
    while (scanner.hasNextLine()) {

      String line = scanner.nextLine();
      String[] tokens = line.split("[\\s,;\\n]+");

      for (String token : tokens) {
        try {
          result += Double.parseDouble(token);
        } catch (NumberFormatException e) {
        }
      }
    }

    writer.println(result);

    writer.close();
    scanner.close();
  }
}
