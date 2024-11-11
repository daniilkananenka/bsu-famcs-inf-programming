package misc;

import models.Student;

import java.util.HashSet;
import java.util.Set;

public class Notifier {
    private final Set<Student> notifiables;

    public Notifier(Set<Student> students) {
        notifiables = new HashSet<>(students);
        notifiables.addAll(students);
    }

    public void doNotifyAll(String message) {
        for (Student i : notifiables)
            i.notify(message);
    }
}