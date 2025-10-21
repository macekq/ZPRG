import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    public static void main(String[] args) {

        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Java Canvas Example");
            GamePanel panel = new GamePanel();
            frame.add(panel);
            frame.setSize(500, 1000);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);

            // Start animation timer
            Timer timer = new Timer(16, new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    panel.update();
                    panel.repaint();
                }
            });
            timer.start();
        });
    }
}

class GamePanel extends JPanel {
    private int x = 50;
    private int y = 50;
    private int xSpeed = 2;
    private int ySpeed = 2;

    public GamePanel() {
        setBackground(Color.WHITE);
    }

    public void update() {
        
        x += xSpeed;
        y += ySpeed;

        if (x <= 0 || x >= 350) xSpeed = -xSpeed;
        if (y <= 0 || y >= 250) ySpeed = -ySpeed;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        Color bg = new Color(32,32,32);
        g.setColor(bg);
        g.fillRect(0,0,getWidth(),getHeight());

        // Draw a moving rectangle
        g.setColor(Color.RED);
        g.fillRect(x, y, 50, 50);

        for(int j = 0; j<20; j++){
            for(int i = 0; i<10; i++){

                if(Hra.MATRIX[j][i] != 0){
                    g.fillRect(i*50, j*50, 50, 50);
                }
            }
        }

        //display shape
        for(int j = 0; j<4; j++){
            for(int i = 0; i<4; i++){

                if(Hra.crrShape[Hra.rotation][j][i] != 0){
                    g.fillRect((i+Hra.souradnice[0])*50, (j+Hra.souradnice[1])*50, 50, 50);
                }
            }
        }
    }
}