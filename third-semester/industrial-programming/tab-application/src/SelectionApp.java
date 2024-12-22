import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class SelectionApp extends JFrame {
    private JList<String> leftList;
    private JList<String> rightList;
    private DefaultListModel<String> leftModel;
    private DefaultListModel<String> rightModel;
    private JButton moveRightButton;
    private JButton moveLeftButton;

    public SelectionApp() {
        setTitle("Selection App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 300);
        setLayout(new BorderLayout());

        leftModel = new DefaultListModel<>();
        rightModel = new DefaultListModel<>();

        leftModel.addElement("Element 1");
        leftModel.addElement("Element 2");
        leftModel.addElement("Element 3");
        leftModel.addElement("Element 4");

        leftList = new JList<>(leftModel);
        rightList = new JList<>(rightModel);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(2, 1, 5, 5));

        moveRightButton = new JButton(">");
        moveLeftButton = new JButton("<");

        buttonPanel.add(moveRightButton);
        buttonPanel.add(moveLeftButton);

        moveRightButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                moveSelectedItems(leftList, leftModel, rightModel);
            }
        });

        moveLeftButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                moveSelectedItems(rightList, rightModel, leftModel);
            }
        });

        add(new JScrollPane(leftList), BorderLayout.WEST);
        add(buttonPanel, BorderLayout.CENTER);
        add(new JScrollPane(rightList), BorderLayout.EAST);
    }

    private void moveSelectedItems(JList<String> sourceList, DefaultListModel<String> sourceModel, DefaultListModel<String> targetModel) {
        List<String> selectedValues = sourceList.getSelectedValuesList();
        for (String value : selectedValues) {
            targetModel.addElement(value);
            sourceModel.removeElement(value);
        }
    }
}
