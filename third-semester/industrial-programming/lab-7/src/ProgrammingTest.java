import misc.ComparatorByName;
import misc.Notifier;
import misc.Writer;
import models.*;

import java.io.File;
import java.util.*;
import java.util.function.Predicate;

public class ProgrammingTest {
    public static void main(String[] args) {
        Set<Student> students = new TreeSet<>(new ComparatorByName());

        Course course = new Course(students, "----Programming----");

        // Undergraduate
        course.addStudent(new Undergraduate("Boris", "gg4", "boris@gmail.com", new Academic("Paul Deitel")));
        course.addStudent(new Undergraduate("Polina", "pr3", "polina@gmail.com", new Academic("Cay Horstmann")));

        // Postgraduate
        course.addStudent(new Postgraduate("Daniil", "te2", "daniilkan@gmail.com", new Academic("Paul Deitel")));
        course.addStudent(new Postgraduate("Andrew", "yj34", "andrey@rambler.ru", new Academic("Cay Horstmann")));
        course.addStudent(new Postgraduate("Vlad", "jj8", "vlad@outlook.com", new Academic("Cay Horstmann")));

        System.out.println(course.toString());

        File file = new File("output.txt");
        Writer out = new Writer();
        out.write(course, file);

        System.out.println("----Postgraduates (supervisor - Cay Horstmann)----");
        Set<Student> set;
        set = course.iterateCourse(new Predicate<Student>() {
            @Override
            public boolean test(Student t) {
                return t.getClass() == Postgraduate.class && Objects.equals(((Postgraduate) t).getSupervisor().getName(), "Cay Horstmann");
            }
        });
        for (Student i : set)
            System.out.println(i.toString());
        System.out.println();


        // Notify students
        Notifier notifier = new Notifier(students);
        notifier.doNotifyAll("Hello, students!");
    }
}