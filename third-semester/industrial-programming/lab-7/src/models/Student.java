package models;

import interfaces.Notifiable;

public class Student extends Person implements Notifiable {
    private String login;
    private String email;

    Student(String name, String login, String email) {
        super(name);
        this.login = login;
        this.email = email;
    }

    @Override
    public void notify(String message) {
        System.out.println(this.toString() + " NOTIFICATION:" + message);
    }
    
    public String getEmail() {
        return email;
    }

    public String getLogin() {
        return login;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    @Override
    public String toString() {
        return super.toString() + " STUDENT=<" + login + ", " + email + "> ";
    }
}
