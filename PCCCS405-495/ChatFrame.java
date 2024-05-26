import javax.swing.*;

public class ChatFrame {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Chat Frame");
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("File");
        JMenuItem exitItem = new JMenuItem("Exit");
        menu.add(exitItem);
        menuBar.add(menu);
        frame.setJMenuBar(menuBar);

        JPanel panel = new JPanel();
        JLabel label = new JLabel("Enter your message:");
        JTextField textField = new JTextField(20);
        JButton sendButton = new JButton("Send");

        panel.add(label);
        panel.add(textField);
        panel.add(sendButton);

        frame.add(panel);
        frame.setSize(400, 200);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
