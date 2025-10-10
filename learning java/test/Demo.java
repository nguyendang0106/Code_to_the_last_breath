package test;

class Animal {
    public void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    public void sound() {
        System.out.println("Dog barks");
    }

    public void wagTail() {
        System.out.println("Dog wags its tail");
    }
}

public class Demo {
    public static void main(String[] args) {
        Dog dog = new Dog(); // Đối tượng thuộc lớp Dog
        Animal animal = dog; // Upcasting từ Dog sang Animal

        animal.sound(); // Gọi phương thức của lớp cha (hoặc lớp con nếu được override)
        // animal.wagTail(); // Lỗi biên dịch: Animal không có phương thức wagTail()

        // Option 1: Downcasting
        ((Dog) animal).wagTail();
        
        // Option 2: Use Dog reference directly
        dog.wagTail();
    }
}

