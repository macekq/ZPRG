import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.security.Key;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("WSAD Movement Game");
            GamePanel gamePanel = new GamePanel();

            frame.add(gamePanel);
            frame.setSize(500, 1000);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);

            // Focus for keyboard input
            gamePanel.setFocusable(true);
            gamePanel.requestFocusInWindow();
        });
    }
}

class GamePanel extends JPanel implements KeyListener {
    private int playerX = 0;
    private int playerY = 0;
    private final int moveSpeed = 1;

    private Set<Integer> pressedKeys = new HashSet<>();

    public GamePanel() {
        setBackground(Color.BLACK);
        addKeyListener(this);

        // Game loop timer (60 FPS)
        Timer gameTimer = new Timer(16, e -> {
            update();
            repaint();
        });
        gameTimer.start();
    }

    private void update() {
        if(Hra.fall == 0) {
            playerY++;
            Hra.fall = 16;
        }
        else Hra.fall -= Hra.fallSpeed;

        // WSAD movement

        if(pressedKeys.contains(KeyEvent.VK_S) && playerY+moveSpeed < 20) {
            Hra.fallSpeed = 2;
        }

        if (pressedKeys.contains(KeyEvent.VK_A) && playerX-moveSpeed >= 0) {
            playerX -= moveSpeed;
        }
        if (pressedKeys.contains(KeyEvent.VK_D) && playerX+moveSpeed < 10) {
            playerX += moveSpeed;
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        Color bg = new Color(32,32,32);
        g.setColor(bg);
        g.fillRect(0,0,getWidth(),getHeight());

        g.setColor(Color.RED);

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
                    g.fillRect((playerX+i)*50, (playerY+j)*50, 50, 50);
                }
            }
        }

        // souradnice
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 16));
        g.drawString("Position: " + playerX + ", " + playerY, 20, 55);

        // controls
        g.setFont(new Font("Arial", Font.PLAIN, 14));
        g.drawString("W - Move Up", 20, getHeight() - 60);
        g.drawString("S - Move Down", 20, getHeight() - 40);
        g.drawString("A - Move Left", 20, getHeight() - 20);
        g.drawString("D - Move Right", 120, getHeight() - 20);
    }

    @Override
    public void keyPressed(KeyEvent e) {
        pressedKeys.add(e.getKeyCode());
    }

    @Override
    public void keyReleased(KeyEvent e) {
        pressedKeys.remove(e.getKeyCode());
    }

    @Override
    public void keyTyped(KeyEvent e) {
        // Not used
    }
}