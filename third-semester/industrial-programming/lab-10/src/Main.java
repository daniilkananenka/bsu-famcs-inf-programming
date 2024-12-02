public class Main {
    public static void main(String[] args) {
        PriorityQueueWithPairs<String> pq = new PriorityQueueWithPairs<>();
        pq.insert("a", 3);
        pq.insert("b", 1);
        pq.insert("c", 2);

        System.out.println("Min element: " + pq.getMinimum().element); // b
        pq.extractMinimum();
        System.out.println("Min after extraction: " + pq.getMinimum().element); // c

        PriorityQueueWithPairs.CustomIterator<String> iterator = pq.iterator();
        while (iterator.hasNext()) {
            Pair<String> pair = iterator.next();
            System.out.println(pair.element + ": " + pair.priority);
        }
    }
}
