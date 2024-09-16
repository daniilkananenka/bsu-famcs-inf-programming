import java.util.StringTokenizer;

public class Program {
  public static void main(String[] args) {
    if (args.length < 2) {
      System.out.println("Usage: java ArithmeticExpressionEvaluator <expression> <X>");
      return;
    }

    String expression = args[0];
    int x;
    try {
      x = Integer.parseInt(args[1]);
    } catch (NumberFormatException e) {
      System.out.println("Invalid value for X: " + args[1]);
      return;
    }

    try {
      int result = evaluateExpression(expression, x);
      System.out.println("Result: " + result);
    } catch (InvalidExpressionException e) {
      System.out.println("Error: " + e.getMessage());
    }
  }

  public static int evaluateExpression(String expression, int x) throws InvalidExpressionException {
    StringTokenizer tokenizer = new StringTokenizer(expression, "+-", true);
    int result = 0;
    boolean add = true;

    while (tokenizer.hasMoreTokens()) {
      String token = tokenizer.nextToken().trim();
      switch (token) {
        case "+" -> add = true;
        case "-" -> add = false;
        default -> {
          int value;
          if (token.equals("X")) {
            value = x;
          } else {
            try {
              value = Integer.parseInt(token);
            } catch (NumberFormatException e) {
              throw new InvalidExpressionException("Invalid token: " + token);
            }
          }
          if (add) {
            result += value;
          } else {
            result -= value;
          }
        }
      }
    }

    return result;
  }
}

class InvalidExpressionException extends Exception {
  public InvalidExpressionException(String message) {
    super(message);
  }
}