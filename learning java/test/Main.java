package test;

import java.util.ArrayList;
import java.util.List;

class Animal {
    public Animal() {
        System.out.println("Animal constructor called");
    }
}

class Dog extends Animal {
    public Dog() {
        System.out.println("Dog constructor called");
    }
}

class Parent {
    public Parent() {
        System.out.println("1. Constructor của Parent được gọi");
    }
}

class Component {
    public Component() {
        System.out.println("2. Constructor của Component được gọi");
    }
}

class Whole extends Parent {
    private Component component = new Component(); // Thành phần của lớp toàn thể

    public Whole() {
        System.out.println("3. Constructor của Whole được gọi");
    }
}

class Child extends Parent {}
class GrandChild extends Child {}

public class Main {
    public static void main(String[] args) {
        Dog dog = new Dog();

        Whole whole = new Whole();

        List<? super Child> myList = new ArrayList<Parent>();
        
        myList.add(new Child());       // Hợp lệ
        myList.add(new GrandChild());  // Hợp lệ
        // myList.add(new Parent());      // Lỗi! Không thể thêm Parent

        // Đọc phần tử từ danh sách
        Object obj = myList.get(0);    // Đọc ra là Object
        System.out.println(obj);      // In ra đối tượng, ví dụ: Child@hashcode
    }
}


