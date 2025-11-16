public class Jidlo{

    public Jidlo(){}

    public static int bobule(){
        return 250;
    }
    public static int ryba(){
        return 500;
    }

    public static int med(){
        return 1000;
    }

    public static Object[] hodnoty(){
        Object[] result = new Object[3];

        result[0] = bobule(); result[1] = ryba(); result[2] = med();
        return result;
    }
}