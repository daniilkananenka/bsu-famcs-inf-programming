package strategy;

import model.Student;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class StreamStrategy implements Strategy {
    @Override
    public List<Student> filter(List<Student> students, String group) {
        return students.stream()
                .filter(student -> student.getGroup().equals(group))
                .sorted(Comparator.comparing(Student::getId))
                .collect(Collectors.toList());
    }
}