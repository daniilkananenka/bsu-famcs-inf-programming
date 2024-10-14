public class Linear extends Series {
    public Linear(double base, double q) {
        super(base, q);
    }

    @Override
    public double calculateElement(int j) {
        return this.getBase() + this.getQ() * j;
    }
}
