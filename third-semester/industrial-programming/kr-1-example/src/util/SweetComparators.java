package util;

import model.Sweet;
import java.util.Comparator;

public class SweetComparators {
    public static Comparator<Sweet> byWeight() {
        return Comparator.comparingDouble(Sweet::getWeight);
    }

    public static Comparator<Sweet> bySugarContent() {
        return Comparator.comparingDouble(Sweet::getSugarContent);
    }
}
