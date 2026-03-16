import java.util.ArrayList;

public interface Knihovna{

    public boolean pujcitKnihu(Ctenar ctenar);
    public void vratitKnihu();
    public boolean odepsatKnihu(ArrayList<Kniha> list);
    public void vypisDostupnych();
    public void vypisPujcenych();


}
