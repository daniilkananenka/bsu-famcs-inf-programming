import javax.swing.*;

import java.awt.*;
import java.awt.event.*;

public class Main extends JFrame {
    static final int SCREEN_WIDTH = 1920;
    static final int SCREEN_HEIGHT = 1080;

    private final JTextField field;
    private final JButton button;
    private final Point point;
    private final Point pb;

    public Main(String title) {
        super(title);

        setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
        setLayout(null);

        addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
                showCoordinates(e);
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                showCoordinates(e);
            }
        });

        button = new JButton("Ctrl + Drag");
        button.setBounds(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT - 100, 200, 40);
        add(button);

        point = new Point(button.getX(), button.getY());
        pb = new Point(point);

        button.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseMoved(MouseEvent e) {
                field.setText(String.format("[%d, %d]", e.getXOnScreen(),  e.getYOnScreen()));

                showCoordinates(e);
            }

            @Override
            public void mouseDragged(MouseEvent e) {
                showCoordinates(e);

                if (e.isControlDown()) {
                    moveButton(e);
                }
            }
        });

        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                pb.move(e.getX() + 6, e.getY() + 26);
            }
        });

        button.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_BACK_SPACE) {
                    if (!button.getText().isEmpty())
                        button.setText(button.getText().substring(0, button.getText().length() - 1));
                } else if (Character.isLetterOrDigit(e.getKeyCode()) || "!@#$%^&*()_+-=[]{}|;':\\\",.<>/? ".indexOf(e.getKeyChar()) != -1) {
                    button.setText(button.getText() + e.getKeyChar());
                }
            }
        });

        field = new JTextField(30);
        field.setBounds(SCREEN_WIDTH / 2 - 30, 10, 60, 20);

        add(field);

        field.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
                showCoordinates(e);
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                showCoordinates(e);
            }
        });
    }

    private void moveButton(MouseEvent e) {
        int x = e.getXOnScreen() - this.getX() - pb.x;
        int y =e.getYOnScreen() - this.getY() - pb.y;

        point.move(x, y);
        button.setLocation(point);
    }

    private void showCoordinates(MouseEvent e) {
        int x = e.getXOnScreen() - this.getX();
        int y = e.getYOnScreen() - this.getY();

        field.setText(String.format("[%d, %d]", x, y));
    }

    public static void main(String[] args) {
        Main frame = new Main("Button Movement Demo");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
}