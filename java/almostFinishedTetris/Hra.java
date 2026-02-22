import java.awt.*;

public class Hra {
    public static int[][] MATRIX = {
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    public static int[][][] L = {
            {
                {0,0,0,0},
                {1,0,0,0},
                {1,0,0,0},
                {1,1,0,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,1,0},
                {1,0,0,0}
            },
            {
                {0,0,0,0},
                {1,1,0,0},
                {0,1,0,0},
                {0,1,0,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {0,0,1,0},
                {1,1,1,0}
            }
    };
    public static int[][][] T = {
            {
                {0,0,0,0},
                {0,0,0,0},
                {0,1,0,0},
                {1,1,1,0}
            },
            {
                {0,0,0,0},
                {1,0,0,0},
                {1,1,0,0},
                {1,0,0,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,1,0},
                {0,1,0,0}
            },
            {
                {0,0,0,0},
                {0,1,0,0},
                {1,1,0,0},
                {0,1,0,0},
            }
    };
    public static int[][][] TBT = {
            {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,0,0},
                {1,1,0,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,0,0},
                {1,1,0,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,0,0},
                {1,1,0,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,0,0},
                {1,1,0,0}
            }
    };
    public static int[][][] OBF = {
            {
                {1,0,0,0},
                {1,0,0,0},
                {1,0,0,0},
                {1,0,0,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                {1,1,1,1}
            },
            {
                {1,0,0,0},
                {1,0,0,0},
                {1,0,0,0},
                {1,0,0,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                {1,1,1,1}
            }
    };
    public static int[][][][] ALL = {L, T, TBT, OBF};
    public static int[][][] crrShape = OBF;
    public static int rotation = 1;
    public static int fall = 16;
    public static int fallSpeed = 1;
    public static int crrColor = 0;
    public static Color[] colorArr = {Color.blue, Color.green, Color.red, Color.yellow, Color.magenta, Color.cyan};
    public static boolean showControls = false;
    public static int[] shapeCords = {4,0};

    public static int getY(){return shapeCords[1];}
    public static int getX(){return shapeCords[0];}
    public static int getRotation(){return rotation;}

    public static void addX(){shapeCords[0]++;}
    public static void subX(){shapeCords[0]--;}
    public static void addY(){ shapeCords[1]++; }

    public static void rotate(){
        rotation++;
        rotation %= 4;
        System.out.println(rotation);
    }
    public static void setShowControls(boolean val){
        showControls = val;
    }
    public static void newShape(){
        rotation = 0;
        shapeCords = new int[]{4,0};
        crrShape = ALL[(int)(Math.random()*ALL.length)];
        crrColor = (int)(Math.random()*colorArr.length);
    }
    public static void shiftMatrix(int rowToRemove){
        for (int y = rowToRemove; y > 0; y--) {
            for (int x = 0; x < MATRIX[y].length; x++) {
                MATRIX[y][x] = MATRIX[y - 1][x];
            }
        }

        MATRIX[0][0] = 1; MATRIX[0][MATRIX[0].length-1] = 1;
        for(int i = 1; i<=MATRIX[0].length-1; i++) MATRIX[0][i] = 0;
    }
    public static void removeLineIfneeded(){
        for(int y = 0; y<20; y++){
            boolean isFilled = true;
            for(int x = 0; x<10; x++){
                if(MATRIX[y][x+1] == 0) isFilled = false;
            }

            if(isFilled){
                shiftMatrix(y);
            }
        }

    }
    /*public static boolean overlayShapeAgainstMatrix(){

        for(int y = 0; y<4; y++){
            for(int x = 0; x<4; x++){

                if(crrShape[rotation][y][x] != 0){
                    try {//x+1 protoze je matrix posunut o 1;
                        if (MATRIX[shapeCords[1] + y][shapeCords[0] + x+1] != 0) return false;

                    }catch (ArrayIndexOutOfBoundsException chyba){
                        System.out.println(chyba);
                        return false;
                    }
                }
            }
        }
        return true;
    }*/
    public static void logMatrix(){
        for(int y = 0; y<MATRIX.length; y++){
            for(int x = 0; x<MATRIX[0].length; x++){
                System.out.print(MATRIX[y][x] + ", ");
            }
            System.out.println();
        }
    }
    public static boolean checkFuturePosition(int shapeX, int shapeY, int rotation){

        for(int y = 0; y<4; y++){
            for(int x = 0; x<4; x++){

                if(crrShape[rotation][y][x] != 0){
                    try {//x+1 protoze je matrix posunut o 1;
                        if (MATRIX[shapeY + y][shapeX + x] != 0) return false;

                    }catch (ArrayIndexOutOfBoundsException chyba){
                        System.out.println(chyba);
                        return false;
                    }
                }
            }
        }
        return true;
    }
    public static void writeShapeIntoMatrix(){

        for(int y = 0; y<4; y++){
            for(int x = 0; x<4; x++){
                if(crrShape[rotation][y][x] == 1) MATRIX[shapeCords[1] + y][shapeCords[0] + x] = crrColor+1;
            }
        }
    }
}
