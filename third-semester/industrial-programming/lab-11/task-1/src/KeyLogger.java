import javax.swing.*;
import java.awt.*;

public class KeyLogger extends JPanel implements KeyObserver {
    private final JTextArea textArea;

    public KeyLogger() {
        textArea = new JTextArea();
        textArea.setEditable(false);
        setLayout(new BorderLayout());
        add(new JScrollPane(textArea), BorderLayout.CENTER);
    }

    @Override
    public void update(char keyChar) {
        textArea.append(keyChar + "\n");
    }
}

