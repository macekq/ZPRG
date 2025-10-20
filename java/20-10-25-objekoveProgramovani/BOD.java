// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class BOD{
    private float x;
    private float y;

    public BOD(){}

    public void setX(float x){
        this.x = x;
    }
    public void setY(float y){
        this.y = y;
    }
    public int kvadrant(){
        if(x<0){
            if(y<0) return 3;
            else return 2;
        }else{
            if(y<0) return 4;
        }
        return 1;
    }
    public double vzdalenostOdBodu(float x2, float y2){

        return Math.sqrt(Math.pow(x-x2, 2)+Math.pow(y-y2, 2));
    }
}
