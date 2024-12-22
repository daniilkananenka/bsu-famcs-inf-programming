import java.util.ArrayList;
import java.util.List;

class PriorityQueueWithPairs<T> {
    private final ArrayList<Pair<T>> list;

    public PriorityQueueWithPairs() {
        list = new ArrayList<>();
    }

    public void insert(T element, int priority) {
        list.add(new Pair<>(element, priority));
    }

    public Pair<T> extractMinimum() {
        if (list.isEmpty()) return null;
        Pair<T> minPair = getMinimum();
        list.remove(minPair);
        return minPair;
    }

    public Pair<T> getMinimum() {
        if (list.isEmpty()) return null;
        Pair<T> minPair = list.get(0);
        for (Pair<T> pair : list) {
            if (pair.priority < minPair.priority) {
                minPair = pair;
            }
        }
        return minPair;
    }

    public void insertAll(ArrayList<Pair<T>> pairs) {
        list.addAll(pairs);
    }

    public CustomIterator<T> iterator() {
        return new CustomIterator<>(list);
    }

    public void accept(Visitor<T> visitor) {
        visitor.visit(this);
        for (Pair<T> pair : list) {
            pair.accept(visitor);
        }
    }

    public List<Pair<T>> toList() {
        List<Pair<T>> elements = new ArrayList<>();
        CustomIterator<T> it = this.iterator();
        while (it.hasNext()) {
            elements.add(it.next());
        }
        return elements;
    }

    static class CustomIterator<E> {
        private final ArrayList<Pair<E>> list;
        private int currentIndex = 0;

        CustomIterator(ArrayList<Pair<E>> list) {
            this.list = list;
        }

        public boolean hasNext() {
            return currentIndex < list.size();
        }

        public Pair<E> next() {
            if (!hasNext()) return null;
            return list.get(currentIndex++);
        }
    }
}