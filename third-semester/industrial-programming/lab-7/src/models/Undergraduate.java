package models;

public class Undergraduate extends Student {
    private Academic tutor;

    public Undergraduate(String name, String login, String email, Academic tutor) {
        super(name, login, email);
        this.tutor = tutor;
    }

    public Academic getTutor() {
        return tutor;
    }

    public void setTutor(Academic tutor) {
        this.tutor = tutor;
    }

    @Override
    public String toString() {
        return "UNDERGRADUATE=<" + super.toString() + tutor.toString() + ">";
    }
}