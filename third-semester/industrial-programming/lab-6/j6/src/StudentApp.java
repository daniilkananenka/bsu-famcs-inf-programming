import model.Student;
import strategy.Strategy;
import strategy.StreamStrategy;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class StudentApp {
    private final JFrame frame;
    private final JTextArea displayArea;
    private final JTextArea logArea;
    private final List<Student> students;
    private final JTextField groupField;
    private final Strategy filterStrategy;

    public StudentApp() {
        filterStrategy = new StreamStrategy();
        students = new ArrayList<>();
        frame = new JFrame("model.Student Management");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);
        frame.setLayout(new GridLayout(3, 1));

        displayArea = new JTextArea();
        displayArea.setEditable(false);
        frame.add(new JScrollPane(displayArea));

        logArea = new JTextArea();
        logArea.setEditable(false);
        frame.add(new JScrollPane(logArea));

        JPanel controlPanel = new JPanel();
        controlPanel.setLayout(new FlowLayout());

        groupField = new JTextField(10);
        JButton filterButton = new JButton("Filter by Group");

        controlPanel.add(new JLabel("Group:"));
        controlPanel.add(groupField);
        controlPanel.add(filterButton);

        frame.add(controlPanel);

        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem openItem = new JMenuItem("Open");
        JMenuItem addItem = new JMenuItem("Add");
        fileMenu.add(openItem);
        fileMenu.add(addItem);
        menuBar.add(fileMenu);
        frame.setJMenuBar(menuBar);

        openItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                openFile();
            }
        });

        addItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addStudent();
            }
        });

        filterButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                filterStudentsByGroup();
            }
        });

        frame.setVisible(true);
    }

    private void openFile() {
        JFileChooser fileChooser = new JFileChooser();
        int result = fileChooser.showOpenDialog(frame);
        if (result == JFileChooser.APPROVE_OPTION) {
            File file = fileChooser.getSelectedFile();
            loadStudentsFromFile(file);
        }
    }

    private void loadStudentsFromFile(File file) {
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            students.clear();
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split("\\s+");
                String id = parts[0];
                String surname = parts[1];
                int course = Integer.parseInt(parts[2]);
                String group = parts[3];
                students.add(new Student(id, surname, course, group));
            }
            displayStudents();
            logArea.append("Loaded students from file: " + file.getName() + "\n");
        } catch (IOException e) {
            logArea.append("Error loading file: " + e.getMessage() + "\n");
        }
    }

    private void displayStudents() {
        displayArea.setText("");
        for (Student student : students) {
            displayArea.append(student.toString() + "\n");
        }
    }

    private void addStudent() {
        JPanel panel = new JPanel(new GridLayout(4, 2));
        JTextField idField = new JTextField();
        JTextField surnameField = new JTextField();
        JTextField courseField = new JTextField();
        JTextField groupField = new JTextField();

        panel.add(new JLabel("ID:"));
        panel.add(idField);
        panel.add(new JLabel("Surname:"));
        panel.add(surnameField);
        panel.add(new JLabel("Course:"));
        panel.add(courseField);
        panel.add(new JLabel("Group:"));
        panel.add(groupField);

        int result = JOptionPane.showConfirmDialog(frame, panel, "Add model.Student", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            String id = idField.getText();
            String surname = surnameField.getText();
            int course = Integer.parseInt(courseField.getText());
            String group = groupField.getText();
            Student student = new Student(id, surname, course, group);
            students.add(student);
            logArea.append("Added student: " + student + "\n");
        }
        displayStudents();
    }

    private void filterStudentsByGroup() {
        String group = groupField.getText();
        List<Student> filteredStudents = filterStrategy.filter(students, group);

        displayArea.setText("");
        for (Student student : filteredStudents) {
            displayArea.append(student.toString() + "\n");
        }
        logArea.append("Filtered students by group: " + group + "\n");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new StudentApp());
    }
}
