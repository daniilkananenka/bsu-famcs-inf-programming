package models;

import misc.ComparatorByName;

import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;
import java.util.function.Predicate;

public class Course implements Iterable<Student> {
    private final Set<Student> students;
    private final String course;

    public Course(Set<Student> students, String course) {
        this.students = students;
        this.course = course;
    }

    @Override
    public Iterator<Student> iterator() {
        return students.iterator();
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(course).append(":\n");

        for (Student i : students)
            stringBuilder.append(i.toString()).append("\n");

        return stringBuilder.toString();
    }

    public void addStudent(Student student) {
        students.add(student);
    }

    public Set<Student> iterateCourse(Predicate<Student> predicate) {
        Set<Student> result = new TreeSet<>(new ComparatorByName());

        for (Student i : students)
            if (predicate.test(i))
                result.add(i);
        return result;
    }
}
