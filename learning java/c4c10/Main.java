package c4c10;
public class Main {
    public static void main(String[] args) {
        Person person = new Person("Bob", 30);

        person.name = "Alice";
        person.age = 25;
        person.introduce(); // Output: Hello, my name is Alice and I am 25 years old.

        Greeting greeting = new Greeting();
        greeting.sayHello(person); // Output: Hello, Daisy!

        Person person1 = person.createPerson("Emma", 26);
        person1.introduce(); // Output: Hello, my name is Emma and I am 26 years old.

    }
}