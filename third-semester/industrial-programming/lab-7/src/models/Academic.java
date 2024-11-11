package models;

public class Academic extends Person {
    public Academic(String name) {
        super(name);
    }

    @Override
    public String toString() {
        return "ACADEMIC=<" + getName() + ">";
    }
}
