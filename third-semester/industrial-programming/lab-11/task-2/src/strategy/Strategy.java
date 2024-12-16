package strategy;

import model.Student;

import java.util.List;

public interface Strategy {
    List<Student> filter(List<Student> students, String group);
}
