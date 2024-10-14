import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;

class App extends JFrame {
    private JComboBox<String> progressionType;
    private JTextField fileNameField;
    private JTextField baseField;
    private JTextField qField;
    private JTextArea outputArea;
    private JTextField nField;

    public App() {
        setTitle("Series Generator");
        setSize(1920, 1080);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(8, 2));

        panel.add(new JLabel("Progression Type:"));
        progressionType = new JComboBox<>(new String[]{"Linear", "Exponential"});
        panel.add(progressionType);

        panel.add(new JLabel("File Name:"));
        fileNameField = new JTextField();
        panel.add(fileNameField);

        panel.add(new JLabel("Base:"));
        baseField = new JTextField();
        panel.add(baseField);

        panel.add(new JLabel("Q:"));
        qField = new JTextField();
        panel.add(qField);

        panel.add(new JLabel("Number of Elements:"));
        nField = new JTextField();
        panel.add(nField);

        JButton printButton = new JButton("Print");
        printButton.addActionListener(new PrintAction());
        panel.add(printButton);

        JButton saveButton = new JButton("Save to file");
        saveButton.addActionListener(new SaveAction());
        panel.add(saveButton);

        outputArea = new JTextArea();
        outputArea.setEditable(false);
        add(new JScrollPane(outputArea), BorderLayout.CENTER);
        add(panel, BorderLayout.NORTH);
    }

    private class PrintAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            int n = Integer.parseInt(nField.getText());
            String type = (String) progressionType.getSelectedItem();
            double base = Double.parseDouble(baseField.getText());
            double q = Double.parseDouble(qField.getText());

            Series series;
            if ("Linear".equals(type)) {
                series = new Linear(base, q);
            } else {
                series = new Exponential(base, q);
            }
            outputArea.setText(series.toString(n));
        }
    }

    private class SaveAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try (FileWriter writer = new FileWriter("output.txt")) {
                writer.write(outputArea.getText());
                JOptionPane.showMessageDialog(App.this, "Successfully saved to file.");
            } catch (IOException ex) {
                System.out.println("Error! Saving file failed");
            }
        }
    }
}