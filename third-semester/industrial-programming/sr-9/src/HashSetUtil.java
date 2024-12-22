import java.util.HashSet;

public class HashSetUtil {

    public static boolean check(String s1, String s2) {
        Person p1 = new Person(s1, s2);
        Person p2 = new Person(s1, s2);

        HashSet<Person> people = new HashSet<>();
        people.add(p1);

        return processSet(people, p2);
    }

    public static boolean processSet(HashSet<Person> people, Person person) {
        return people.contains(person);
    }

    static class Person {
        private String fn;
        private String ln;

        public Person(String fn, String ln) {
            this.fn = fn;
            this.ln = ln;
        }

        @Override
        public String toString() {
            return ln + ", " + fn;
        }

        @Override
        public int hashCode() {
            int result = fn != null ? fn.hashCode() : 0;
            result = 31 * result + (ln != null ? ln.hashCode() : 0);
            return result;
        }

        @Override
        public boolean equals(Object object) {
            if (this == object) {
                return true;
            }

            if (object == null || getClass() != object.getClass()) {
                return false;
            }

            Person person = (Person) object;

            if (fn != null ? !fn.equals(person.fn) : person.fn != null) {
                return false;
            }
            return ln != null ? ln.equals(person.ln) : person.ln == null;
        }
    }

    public static void main(String[] args) {
        String firstName = "John";
        String lastName = "Doe";

        boolean result = check(firstName, lastName);

        System.out.println("Result of search: " + result);
    }
}