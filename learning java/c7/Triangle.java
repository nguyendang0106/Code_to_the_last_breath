package c7;

public class Triangle extends Shape {
    private int base, height;

    Triangle(String n, int b, int h) {
    super(n, b, h);
    base = b;
    height = h;
    }

    public float calculateArea() {
    float area = 0.5f * base * height;
    return area;
    }

}
