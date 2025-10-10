package c7;

public class Square extends Shape {
    private int side;

    Square(String n, int s) {
    super(n,s,s);
    side = s;
    }
    public float calculateArea() {
    float area = (float) (side * side);
    return area;
    }
    
}
