import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class DrawingPanel extends JPanel {
    private BufferedImage image;
    private Graphics2D graphics2D;
    private Color currentColor = Color.RED;

    public DrawingPanel() {
        super();

        image = new BufferedImage(1600, 1200, BufferedImage.TYPE_INT_RGB);
        graphics2D = image.createGraphics();
        graphics2D.setColor(Color.WHITE);
        graphics2D.fillRect(0, 0, image.getWidth(), image.getHeight());

        this.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent event) {
                graphics2D.setColor(currentColor);
                graphics2D.fillOval(event.getX(), event.getY(), 10, 10);
                repaint();
            }

            @Override
            public void mouseMoved(MouseEvent mouseEvent) {

            }
        });
    }

    @Override
    protected void paintComponent(Graphics graphics) {
        super.paintComponent(graphics);
        graphics.drawImage(image, 0, 0, null);
    }

    public void setCurrentColor(Color value) {
        currentColor = value;
    }

    public void loadImageFromFile(File file) throws IOException {
        image = ImageIO.read(file);
        graphics2D = image.createGraphics();
        this.repaint();
    }

    public void saveImageToFile(File file) throws  IOException {
        ImageIO.write(image, "png", file);
    }
}
