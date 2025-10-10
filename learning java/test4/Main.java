package test4;

class Example {
    Example() {
        this(10); // Gọi constructor với 1 tham số
        this.display(); // Gọi một phương thức thông thường
        System.out.println("Default Constructor");
    }

    Example(int x) {
        this(10, 20); // Gọi constructor với 2 tham số
        // this(5, 15); // Gọi lại constructor với 2 tham số thêm lần nữa
        System.out.println("Constructor with one parameter: " + x);
    }

    Example(int x, int y) {
        System.out.println("Constructor with two parameters: " + x + ", " + y);
    }

    void display() {
        System.out.println("Method display!");
    }
}

public class Main {
    public static void main(String[] args) {
        Example ex = new Example(); // Tạo đối tượng Example
    }
}

