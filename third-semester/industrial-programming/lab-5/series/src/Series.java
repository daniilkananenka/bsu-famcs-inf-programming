import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public abstract class Series {
    private double base;
    private double q;

    public Series(double base, double q) {
        this.base = base;
        this.q = q;
    }

    public abstract double calculateElement(int j);

    public String toString(int j) {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < j; ++i) {
            stringBuilder.append(calculateElement(i));
            stringBuilder.append(" ");
        }

        return stringBuilder.toString();
    }

    public double getSum(int j) {
        double result = 0;
        for (int i = 0; i < j; ++i) {
            result += calculateElement(j);
        }

        return result;
    }

    public double getBase() {
        return base;
    }

    public double getQ() {
        return q;
    }

    public void writeToFile(int j, String filePath) {
        String seriesString = this.toString(j);
        try (FileWriter writer = new FileWriter(filePath)) {
            writer.write(seriesString);
        } catch (IOException e) {
            System.out.println("Error writing Series to file");
        }
    }
}
