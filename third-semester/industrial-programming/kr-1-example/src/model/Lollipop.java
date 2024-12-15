package model;

public class Lollipop extends Sweet {
    public enum Color { RED, GREEN, YELLOW }
    private final Color color;

    public Lollipop(String name, double weight, double sugarContent, Color color) {
        super(name, weight, sugarContent);
        this.color = color;
    }

    public Color getColor() { return color; }

    @Override
    public String toString() {
        return String.format(super.toString() + " [Lollipop: %s]", color);
    }
}

