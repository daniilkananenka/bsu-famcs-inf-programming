interface Visitor<T> {
    void visit(Pair<T> pair);
    void visit(PriorityQueueWithPairs<T> queue);
}