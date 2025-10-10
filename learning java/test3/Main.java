package test3;

interface A {
    void methodA();
}

interface B {
    void methodB();
}

class MyClass implements A, B {
    @Override
    public void methodA() {
        System.out.println("Method A");
    }

    @Override
    public void methodB() {
        System.out.println("Method B");
    }
}

public class Main {
    public static void main(String[] args) {
        MyClass obj = new MyClass();

        // Ép kiểu từ MyClass sang interface A
        A a = obj;
        a.methodA(); // Output: Method A

        // Ép kiểu từ MyClass sang interface B
        B b = obj;
        b.methodB(); // Output: Method B

        // Ép kiểu giữa các interface
        A a2 = (A) b; // Bản chất b cũng là A vì obj implements cả A và B
        a2.methodA(); // Output: Method A
    }
}

