package strategy;

import model.Student;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class SimpleStrategy implements Strategy {
    @Override
    public List<Student> filter(List<Student> students, String group) {
        List<Student> filteredStudents = new ArrayList<>();
        for (Student student : students) {
            if (student.getGroup().equals(group)) {
                filteredStudents.add(student);
            }
        }
        filteredStudents.sort(Comparator.comparing(Student::getId));
        return filteredStudents;
    }
}