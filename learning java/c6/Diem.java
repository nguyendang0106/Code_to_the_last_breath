package c6;

public class Diem {
    private int x, y;
    public Diem(){}
    public Diem(int x, int y) {
        this.x = x; this.y = y;
    
    }
    public void setX(int x){ this.x = x; }
    public int getX() { return x; }
    public void printDiem(){
    
        System.out.print("(" + x + ", " + y + ")");
    
    }
}
