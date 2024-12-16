import javax.swing.*;
import java.awt.*;

public class KeyDisplay extends JPanel implements KeyObserver {
    private final JLabel label;

    public KeyDisplay() {
        label = new JLabel("", SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.BOLD, 100));
        setLayout(new BorderLayout());
        add(label, BorderLayout.CENTER);
    }

    @Override
    public void update(char keyChar) {
        label.setText(String.valueOf(keyChar));
    }
}

