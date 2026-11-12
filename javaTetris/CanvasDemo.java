package com.example.tetris;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import java.io.IOException;

/*
public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 320, 240);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}
*/
public class CanvasDemo extends Application {

    private Integer[][] MATRIX = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}
    };
    private Integer[][][][] SHAPES = {
            {
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
                            {1,0,0,0},
                            {1,1,1,0}
                    }

            },
    };

    public void PaintShape(GraphicsContext gc, int X, int Y, int shape, int rotation, Color color) {
        Integer[][] shapeMatrix = SHAPES[shape][rotation];

        gc.setFill(color);
        int y = 0, x = 0;
        for(Integer[] row : shapeMatrix) {
            for(Integer i : row) {

                if(i == 1){
                    gc.fillRect((X+x)*50, (Y+y)*50, 50, 50);
                }
                x++;
            }
            x=0;
            y++;
        }
    }
    @Override
    public void start(Stage stage) {
        Canvas canvas = new Canvas(500, 1000);
        GraphicsContext gc = canvas.getGraphicsContext2D();

        while(true){

            gc.setFill(Color.LIGHTGRAY);
            gc.fillRect(0, 0, 500, 1000);
/*
            gc.setFill(Color.RED);
            gc.fillOval(50, 50, 100, 100);

            gc.setStroke(Color.BLUE);
            gc.setLineWidth(3);
            gc.strokeLine(200, 50, 350, 200);

            gc.setFill(Color.BLACK);
            gc.fillText("Hello Canvas", 150, 250);
*/
            this.PaintShape(gc, 2, 3, 0, 0,  Color.RED);

            stage.setScene(new Scene(new StackPane(canvas)));
            stage.show();

        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}