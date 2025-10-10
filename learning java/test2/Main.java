package test2;

// Lớp cha
class Parent {
    Parent() {
        System.out.println("Constructor của lớp cha được gọi");
    }
}

// Lớp thành phần
class Component {
    Component() {
        System.out.println("Constructor của đối tượng thành phần được gọi");
    }
}

// Lớp hiện tại
class Child extends Parent {
    Component component = new Component(); // Thành phần trong lớp hiện tại

    Child() {
        System.out.println("Constructor của lớp hiện tại được gọi");
    }
}

// Main
public class Main {
    public static void main(String[] args) {
        Child child = new Child();

        Employee emp = new Employee("John Doe");

        System.out.println(emp.print2()); // In: JOHN DOE
        System.out.println(emp.print3()); // In: john doe
    }
    
}

// Constructor của lớp cha được gọi
// Constructor của đối tượng thành phần được gọi
// Constructor của lớp hiện tại được gọi

