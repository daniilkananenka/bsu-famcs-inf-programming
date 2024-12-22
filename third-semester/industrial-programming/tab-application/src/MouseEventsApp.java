import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MouseEventsApp extends JFrame {
    private static final int ROWS = 3;
    private static final int COLS = 3;

    public MouseEventsApp() {
        setTitle("Mouse Events Example");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(ROWS, COLS));

        ButtonMouseListener buttonMouseListener = new ButtonMouseListener();
        for (int i = 0; i < ROWS * COLS; i++) {
            JButton button = new JButton("Button " + (i + 1));
            button.addMouseListener(buttonMouseListener);
            add(button);
        }
    }

    private static class ButtonMouseListener extends MouseAdapter {
        private Color originalColor;
        private String originalText;

        @Override
        public void mouseEntered(MouseEvent e) {
            JButton button = (JButton) e.getSource();
            originalColor = button.getBackground();
            button.setBackground(Color.YELLOW);
        }

        @Override
        public void mouseExited(MouseEvent e) {
            JButton button = (JButton) e.getSource();
            button.setBackground(originalColor);
        }

        @Override
        public void mousePressed(MouseEvent e) {
            JButton button = (JButton) e.getSource();
            originalText = button.getText();
            button.setText("Clicked!");
        }

        @Override
        public void mouseReleased(MouseEvent e) {
            JButton button = (JButton) e.getSource();
            button.setText(originalText);
        }
    }
}
