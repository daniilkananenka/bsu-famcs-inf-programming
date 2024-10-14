public class Exponential extends Series {
    public Exponential(double base, double q) {
        super(base, q);
    }

    @Override
    public double calculateElement(int j) {
        return this.getBase() * Math.pow(this.getQ(), j);
    }
}
