import java.util.ArrayList;

public class cisla{

    public ArrayList<Integer> nums = new ArrayList<Integer>();

    public cisla(){
        while(pridatCislo());
        vypis();
    }
    private boolean pridatCislo(){
        int num = (int)(Math.random()*21)-10;
        if(num == 0) return false;

        nums.add(num);
        return true;
    }
    public void vypis(){
        System.out.println("nums:\n===========");
        for(int i=0; i<nums.size(); i++){
            System.out.print(nums.get(i) + ", ");
        }
        System.out.println("\nabsolutni:\n===========");
        for(int i=0; i<nums.size(); i++){
            System.out.print(Math.abs(nums.get(i)) + ", ");
        }
    }
}
