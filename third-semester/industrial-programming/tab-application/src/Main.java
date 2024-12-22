import javax.swing.*;

public class Main extends JFrame {
    public Main() {
        setTitle("Tab application");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JTabbedPane tabbedPane = new JTabbedPane();

        MouseEventsApp mouseEventsApp = new MouseEventsApp();
        RadioButtonsApp radioButtonsApp = new RadioButtonsApp();
        SelectionApp selectionApp = new SelectionApp();

        tabbedPane.addTab("Mouse Events", mouseEventsApp.getContentPane());
        tabbedPane.addTab("Radio Buttons", radioButtonsApp.getContentPane());
        tabbedPane.addTab("Selection", selectionApp.getContentPane());

        add(tabbedPane);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Main frame = new Main();
            frame.setVisible(true);
        });
    }
}
