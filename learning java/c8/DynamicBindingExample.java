package c8;

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
}

class Cat extends Animal {
    @Override
    public void sound() {
        System.out.println("Cat meows");
    }
}

public class DynamicBindingExample {
    public static void main(String[] args) {
        // Tạo các đối tượng với kiểu tham chiếu là lớp cơ sở
        Animal animal1 = new Dog();
        Animal animal2 = new Cat();
        Animal animal3 = new Animal();

        // Gọi phương thức sound()
        animal1.sound(); // Gọi phương thức của Dog
        animal2.sound(); // Gọi phương thức của Cat
        animal3.sound(); // Gọi phương thức của Animal
    }
}

