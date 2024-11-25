import javax.swing.*;
import java.awt.*;
import java.io.File;

import javax.imageio.ImageIO;

public class MainFrame extends JFrame {
    private DrawingPanel drawingPanel;

    public MainFrame(String title) {
        super(title);

        // Drawing panel
        drawingPanel = new DrawingPanel();
        drawingPanel.setPreferredSize(new Dimension(1600, 1200));

        // Scroll pane
        JScrollPane scrollPane = new JScrollPane(drawingPanel);
        scrollPane.setPreferredSize(new Dimension(800, 600));

        JPanel bottomPanel = new JPanel();

        // Color setting buttons
        JButton redButton = new JButton("Red");
        JButton greenButton = new JButton("Green");
        JButton blueButton = new JButton("Blue");

        // Misc buttons
        JButton saveButton = new JButton("Save");
        JButton openButton = new JButton("Open");

        redButton.addActionListener(e -> drawingPanel.setCurrentColor(Color.RED));
        greenButton.addActionListener(e -> drawingPanel.setCurrentColor(Color.GREEN));
        blueButton.addActionListener(e -> drawingPanel.setCurrentColor(Color.BLUE));

        saveButton.addActionListener(e -> saveImage());
        openButton.addActionListener(e -> openImage());

        bottomPanel.add(redButton);
        bottomPanel.add(greenButton);
        bottomPanel.add(blueButton);
        bottomPanel.add(saveButton);
        bottomPanel.add(openButton);

        add(scrollPane, BorderLayout.CENTER);
        add(bottomPanel, BorderLayout.SOUTH);
    }

    private void saveImage() {
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setCurrentDirectory(new File(""));
        if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
            File file = fileChooser.getSelectedFile();
            try {
                drawingPanel.saveImageToFile(file);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "Error: " + ex.getMessage());
            }
        }
    }

    private void openImage() {
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setCurrentDirectory(new File(""));
        if (fileChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
            File file = fileChooser.getSelectedFile();
            try {
                drawingPanel.loadImageFromFile(file);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "Error: " + ex.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        MainFrame app = new MainFrame("Paint 2.0");
        app.setSize(800, 600);
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        app.setVisible(true);
    }
}
