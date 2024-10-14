import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            App app = new App();
            app.setVisible(true);
            app.setFont(new Font("Courier", Font.PLAIN,75)); // Установите желаемый размер шрифта
        });
    }
}