package model;

public abstract class Sweet {
    private final String name;
    private final double weight; // Gram
    private final double sugarContent;

    public Sweet(String name, double weight, double sugarContent) {
        this.name = name;
        this.weight = weight;
        this.sugarContent = sugarContent;
    }

    public String getName() { return name; }
    public double getWeight() { return weight; }
    public double getSugarContent() { return sugarContent; }

    @Override
    public String toString() {
        return String.format("%s (Weight: %f, Sugar: %f)", name, weight, sugarContent);
    }
}
