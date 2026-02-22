import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.security.Key;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String[] args) {

        //game loop
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("WSAD Movement Game");
            GamePanel gamePanel = new GamePanel();

            frame.add(gamePanel);
            frame.setSize(520, 1040);
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
    public static Hra gameplay = new Hra();

    private final int moveSpeed = 1;

    private Set<Integer> pressedKeys = new HashSet<>();

    public GamePanel() {
        setBackground(Color.BLACK);
        addKeyListener(this);
        gameplay.newShape();

        // Game loop timer (60 FPS)
        Timer gameTimer = new Timer(16, e -> {
            update();
            repaint();
        });
        gameTimer.start();
    }

    private void update() {

        //configuration
        gameplay.setShowControls(true);

        boolean val = Hra.checkFuturePosition(gameplay.getX(), gameplay.getY()+1, gameplay.getRotation());
        //System.out.println(val);


        if(Hra.fall == 0) {
            if(val){
                gameplay.addY();
                gameplay.removeLineIfneeded();
            }
            else{

                gameplay.writeShapeIntoMatrix();
                gameplay.newShape();
            }

            //shape se posune 1 za 16clicku
            Hra.fall = 8;
        }
        else Hra.fall -= Hra.fallSpeed;

        // AD movement
        if (pressedKeys.contains(KeyEvent.VK_A) && Hra.shapeCords[0]-moveSpeed > 0){

            if(gameplay.checkFuturePosition(gameplay.getX()-1, gameplay.getY(), gameplay.getRotation())) gameplay.subX();
        }
        if (pressedKeys.contains(KeyEvent.VK_D) && Hra.shapeCords[0]+moveSpeed <= 10) {
            if(gameplay.checkFuturePosition(gameplay.getX()+1, gameplay.getY(), gameplay.getRotation())) gameplay.addX();
        }
        if (pressedKeys.contains(KeyEvent.VK_Q)){
            if(gameplay.checkFuturePosition(gameplay.getX(), gameplay.getY(), (gameplay.getRotation()+1)%4)) gameplay.rotate();
        }


        if (pressedKeys.contains(KeyEvent.VK_Z)) gameplay.logMatrix();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        Color bg = new Color(32,32,32);
        g.setColor(bg);
        g.fillRect(0,0,getWidth(),getHeight());

        //display matrix
        for(int j = 0; j<20; j++){
            for(int i = 0; i<10; i++){

                if(Hra.MATRIX[j][i+1] != 0){
                    g.setColor(Hra.colorArr[Hra.MATRIX[j][i+1]-1]);
                    g.fillRect(i*50, j*50, 50, 50);
                }
            }
        }

        //display shape
        g.setColor(Hra.colorArr[Hra.crrColor]);
        for(int j = 0; j<4; j++){
            for(int i = 0; i<4; i++){

                if(Hra.crrShape[Hra.rotation][j][i] != 0){
                    g.fillRect((Hra.shapeCords[0]+i-1)*50, (Hra.shapeCords[1]+j)*50, 50, 50);
                }
            }
        }

        // souradnice
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 16));
        g.drawString("Position: " + Hra.shapeCords[0] + ", " + Hra.shapeCords[1] + "r:" + Hra.rotation, 20, 55);

        if(Hra.showControls){

            g.setFont(new Font("Arial", Font.PLAIN, 14));
            g.drawString("W - Move Up", 20, getHeight() - 60);
            g.drawString("S - Move Down", 20, getHeight() - 40);
            g.drawString("A - Move Left", 20, getHeight() - 20);
            g.drawString("D - Move Right", 120, getHeight() - 20);
        }
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
