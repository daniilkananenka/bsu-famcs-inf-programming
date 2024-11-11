package misc;

import models.Course;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Writer {
    public void write(Course course, File File) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(File))) {
            bw.write(course.toString());
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
}