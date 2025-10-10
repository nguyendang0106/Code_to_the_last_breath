package c4c10;

public class Person {
    // Thuộc tính (fields)
    String name;
    int age;

    // Constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Phương thức (methods)
    public void introduce() {
        System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
    }

    public Person createPerson(String name, int age) {
        return new Person(name, age);
    }
}
