import javax.swing.*;
import java.awt.*;

public class Frame
{
    private JFrame frame;
    
    public Frame(String nome, int x, int y, int larghezza, int altezza)
    {
        frame = new JFrame(nome);
        frame.setBounds(x, y, x + larghezza, y + altezza);
        frame.setResizable(false);
        frame.setVisible(false);
    }
    
    public JFrame getJFrame()
    {
        return frame;
    }
}