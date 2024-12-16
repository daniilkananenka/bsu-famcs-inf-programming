import java.util.ArrayList;
import java.util.List;

public class KeySubject {
    private final List<KeyObserver> observers = new ArrayList<>();

    public void attach(KeyObserver observer) {
        observers.add(observer);
    }

    public void detach(KeyObserver observer) {
        observers.remove(observer);
    }

    public void notifyObservers(char keyChar) {
        for (KeyObserver observer : observers) {
            observer.update(keyChar);
        }
    }
}

