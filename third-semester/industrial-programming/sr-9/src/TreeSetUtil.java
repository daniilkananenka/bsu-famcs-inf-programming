import java.util.TreeSet;

public class TreeSetUtil {

    public static boolean check(String[] names, String name) {
        Person p1 = new Person(name);
        TreeSet<Person> people = new TreeSet<Person>();
        for (String person : names)
            people.add(new Person(person));
        return processSet(people, p1);
    }

    public static boolean processSet(TreeSet<Person> people, Person person) {
        return people.contains(person);
    }

    static class Person implements Comparable<Person> {
        private String name;

        public Person(String name) {
            this.name = name;
        }

        public String toString() {
            return name;
        }

        public int hashCode() {
            return name.hashCode();
        }

        public boolean equals(Object object) {
            if (this == object) return true;
            if (object == null || getClass() != object.getClass()) return false;
            Person p = (Person) object;
            return name.equals(p.name);
        }

        public int compareTo(Person other) {
            return this.name.compareTo(other.name);
        }
    }
}