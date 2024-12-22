import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        PriorityQueueWithPairs<String> queue = new PriorityQueueWithPairs<>();
        View view = new View();
        Controller controller = new Controller(queue, view);
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            view.displayMenu();
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    view.displayMessage("Enter element:");
                    String element = scanner.nextLine();
                    view.displayMessage("Enter priority:");
                    int priority = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    controller.addElement(element, priority);
                    break;
                case 2:
                    controller.extractMinimum();
                    break;
                case 3:
                    controller.displayElements();
                    break;
                case 4:
                    running = false;
                    view.displayMessage("Exiting...");
                    break;
                default:
                    view.displayMessage("Invalid choice. Please try again.");
            }
        }
        scanner.close();
    }
}
