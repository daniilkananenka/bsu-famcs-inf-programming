package model;

public class Student {
    private String id;
    private String surname;
    private int course;
    private String group;

    public Student(String id, String surname, int course, String group) {
        this.id = id;
        this.surname = surname;
        this.course = course;
        this.group = group;
    }

    public String getId() {
        return id;
    }

    public String getSurname() {
        return surname;
    }

    public int getCourse() {
        return course;
    }

    public String getGroup() {
        return group;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %s", id, surname, course, group);
    }
}
