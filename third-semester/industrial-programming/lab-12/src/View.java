import java.util.List;

public class View {

    public void displayMenu() {
        System.out.println("Menu:");
        System.out.println("1. Add element");
        System.out.println("2. Extract minimum element");
        System.out.println("3. Display all elements");
        System.out.println("4. Exit");
        System.out.print("Enter your choice: ");
    }

    public void displayMessage(String message) {
        System.out.println(message);
    }

    public void displayElements(List<Pair<String>> elements) {
        if (elements.isEmpty()) {
            System.out.println("The queue is empty.");
        } else {
            System.out.println("Elements in the queue:");
            for (Pair<String> pair : elements) {
                System.out.println("Element: " + pair.element + ", Priority: " + pair.priority);
            }
        }
    }
}
