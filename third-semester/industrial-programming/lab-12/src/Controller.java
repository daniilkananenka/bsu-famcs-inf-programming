import java.util.ArrayList;
import java.util.List;

public class Controller {
    private final PriorityQueueWithPairs<String> queue;
    private final View view;

    public Controller(PriorityQueueWithPairs<String> queue, View view) {
        this.queue = queue;
        this.view = view;
    }

    public void addElement(String element, int priority) {
        queue.insert(element, priority);
        view.displayMessage("Element added: " + element + " with priority " + priority);
    }

    public void extractMinimum() {
        Pair<String> minPair = queue.extractMinimum();
        if (minPair != null) {
            view.displayMessage("Extracted minimum element: " + minPair.element + " with priority " + minPair.priority);
        } else {
            view.displayMessage("Queue is empty.");
        }
    }

    public void displayElements() {
        view.displayElements(queue.toList());
    }
}
