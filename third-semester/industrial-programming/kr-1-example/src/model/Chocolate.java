package model;

public class Chocolate extends Sweet {
    public enum Type { DARK, MILK, WHITE }
    private final Type type;

    public Chocolate(String name, double weight, double sugarContent, Type type) {
        super(name, weight, sugarContent);
        this.type = type;
    }

    public Type getType() { return type; }

    @Override
    public String toString() {
        return String.format(super.toString() + " [Chocolate: %s]", type);
    }
}

