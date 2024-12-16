import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MainFrame extends JFrame {
    private KeySubject keySubject;
    private KeyLogger keyLogger;
    private KeyDisplay keyDisplay;

    public MainFrame() {
        setTitle("Key Observer Example");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(2, 1));

        keySubject = new KeySubject();
        keyLogger = new KeyLogger();
        keyDisplay = new KeyDisplay();

        keySubject.attach(keyLogger);
        keySubject.attach(keyDisplay);

        add(keyDisplay);
        add(keyLogger);

        // Создаем панель и добавляем к ней слушателя клавиш
        JPanel panel = new JPanel();
        panel.setFocusable(true);
        panel.requestFocusInWindow();
        panel.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                keySubject.notifyObservers(e.getKeyChar());
            }
        });

        add(panel);

        // Устанавливаем фокус на панель при отображении окна
        addWindowFocusListener(new java.awt.event.WindowAdapter() {
            @Override
            public void windowGainedFocus(java.awt.event.WindowEvent evt) {
                panel.requestFocusInWindow();
            }
        });
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            MainFrame frame = new MainFrame();
            frame.setVisible(true);
            frame.requestFocusInWindow(); // Устанавливаем фокус на фрейм при отображении
        });
    }
}
