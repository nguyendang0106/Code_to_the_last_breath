package c7;

import java.awt.Graphics;

public class Circle extends Shape implements Actable {
    private int radius;
    public Circle(String n, int x, int y, int r) {
    super(n, x, y); radius = r;
    }
    public float calculateArea() {
    float area = (float) (3.14 * radius * radius);
    return area;
    }
    public void draw(Graphics g) {
    System.out.println("Draw circle at ("
    + x + "," + y + ")");

    g.drawOval(x-radius,y-radius,2*radius,2*radius);
    }
    public void moveTo(Graphics g, int x1, int y1) {
    erase(g); x = x1; y = y1; draw(g);
    }
    public void erase(Graphics g) {
    System.out.println("Erase circle at ("

    + x + "," + y + ")");
    // paint the circle with background color...
        
    }
}