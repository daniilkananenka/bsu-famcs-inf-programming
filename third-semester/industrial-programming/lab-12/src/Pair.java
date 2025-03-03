class Pair<T> {
    T element;
    int priority;

    Pair(T element, int priority) {
        this.element = element;
        this.priority = priority;
    }

    void accept(Visitor<T> visitor) {
        visitor.visit(this);
    }
}