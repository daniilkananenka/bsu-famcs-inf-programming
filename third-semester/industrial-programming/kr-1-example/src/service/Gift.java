package service;

import model.Sweet;
import java.util.*;
import java.util.stream.Collectors;

public class Gift {
    private final List<Sweet> sweets;

    public Gift() {
        sweets = new ArrayList<>();
    }

    public void addSweet(Sweet sweet) {
        sweets.add(sweet);
    }

    public double getTotalWeight() {
        return sweets.stream().mapToDouble(Sweet::getWeight).sum();
    }

    public void sortSweets(Comparator<Sweet> comparator) {
        sweets.sort(comparator);
    }

    public List<Sweet> findSweetsBySugarRange(double min, double max) {
        return sweets.stream()
                .filter(s -> s.getSugarContent() >= min && s.getSugarContent() <= max)
                .collect(Collectors.toList());
    }

    public Map<Double, List<Sweet>> groupByWeight() {
        return sweets.stream().collect(Collectors.groupingBy(Sweet::getWeight));
    }

    public void displaySweets() {
        sweets.forEach(System.out::println);
    }

    public List<Sweet> getSweets() { return sweets; }
}
