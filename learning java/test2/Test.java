package test2;

// Lớp cha A
 class A {
    int i = 10; // Thuộc tính của lớp A

    public void printValue() {
        System.out.println("Value-A");
    }
}

// Lớp con B kế thừa từ A
 class B extends A {
    int i = 12; // Thuộc tính riêng của lớp B

    @Override
    public void printValue() {
        System.out.print("Value-B");
    }
}

// Lớp Test chứa hàm main
public class Test {
    public static void main(String[] args) {
        A a = new B(); // Biến tham chiếu kiểu A trỏ đến đối tượng B

        // Gọi phương thức printValue
        a.printValue(); // Kết quả: Value-B

        // Truy cập thuộc tính i của lớp A
        System.out.println(a.i); // Kết quả: 10

        // Ép kiểu để gọi thuộc tính i của lớp B
        B b = (B) a; // Ép kiểu từ A sang B
        System.out.println(b.i); // Kết quả: 12
    }
}

