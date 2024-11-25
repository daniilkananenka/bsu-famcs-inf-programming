import javax.swing.*;
import java.awt.event.*;;

public class Main extends JFrame {
    private final JButton declineButton;

    public Main() {
        setLayout(null);

        JLabel questionLabel = new JLabel("Is your stipendia good?");
        questionLabel.setBounds(150, 50, 300, 30);
        add(questionLabel);

        JButton confirmButton = new JButton("Yes, it is");
        confirmButton.setBounds(150, 100, 100, 50);

        confirmButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "Perfect!!!!!");
            }
        });

        add(confirmButton);

        declineButton = new JButton("No....");
        declineButton.setBounds(300, 100, 100, 50);
        declineButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                int x = (int) (Math.random() * (getWidth() - declineButton.getWidth()));
                int y = (int) (Math.random() * (getHeight() - declineButton.getHeight()));
                declineButton.setLocation(x, y);
            }
        });
        add(declineButton);
    }

    public static void main(String[] args) {
        Main frame = new Main();

        frame.setTitle("Stipendia");
        frame.setBounds(600, 400, 600, 450);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}