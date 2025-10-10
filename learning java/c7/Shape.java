package c7;

abstract class Shape {
    protected String name;
    protected int x, y;
    Shape(String n, int x, int y) {
    name = n; this.x = x; this.y = y;
    }
    public String getName() {
    return name;
    }
    public abstract float calculateArea();
    
}
