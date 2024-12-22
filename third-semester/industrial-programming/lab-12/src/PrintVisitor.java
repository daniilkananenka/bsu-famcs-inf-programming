class PrintVisitor<T> implements Visitor<T> {
    @Override
    public void visit(Pair<T> pair) {
        System.out.println(pair.element + ", " + pair.priority);
    }

    @Override
    public void visit(PriorityQueueWithPairs<T> queue) {
        System.out.println("Visiting Priority Queue");
    }
}