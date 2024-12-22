import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;

public class RadioButtonsApp extends JFrame {
    public RadioButtonsApp() {
        setTitle("RadioButtonsApp");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(3, 1));

        JRadioButton button1 = createRadioButton("Минская область");
        JRadioButton button2 = createRadioButton("Гродненская область");
        JRadioButton button3 = createRadioButton("Витебская область");

        ButtonGroup group = new ButtonGroup();
        group.add(button1);
        group.add(button2);
        group.add(button3);

        add(button1);
        add(button2);
        add(button3);
    }

    private JRadioButton createRadioButton(String text) {
        JRadioButton radioButton = new JRadioButton(text);

        Icon defaultIcon = createIcon(Color.GRAY);
        Icon selectedIcon = createIcon(Color.GREEN);
        Icon rolloverIcon = createIcon(Color.YELLOW);
        Icon pressedIcon = createIcon(Color.RED);

        radioButton.setIcon(defaultIcon);
        radioButton.setSelectedIcon(selectedIcon);
        radioButton.setRolloverIcon(rolloverIcon);
        radioButton.setPressedIcon(pressedIcon);

        radioButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                radioButton.setIcon(rolloverIcon);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                radioButton.setIcon(defaultIcon);
            }

            @Override
            public void mousePressed(MouseEvent e) {
                radioButton.setIcon(pressedIcon);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                radioButton.setIcon(radioButton.isSelected() ? selectedIcon : defaultIcon);
            }
        });

        return radioButton;
    }

    private Icon createIcon(Color color) {
        int size = 20;
        Image image = new BufferedImage(size, size, BufferedImage.TYPE_INT_ARGB);
        Graphics g = image.getGraphics();
        g.setColor(color);
        g.fillOval(0, 0, size, size);
        g.dispose();
        return new ImageIcon(image);
    }
}
