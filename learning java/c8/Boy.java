package c8;

public class Boy extends Human { 
    public static void walk() { 
        System.out.println("Boy walks"); 
    }
public static void main(String args[]) { 
    // Reference is of Human type and object is Boy type
    Human obj1 = new Boy();
    // Reference is of Human type and object is Human type.
    Human obj2 = new Human();
    // Reference is of Human type and object is Human type.
    Boy obj3 = new Boy();
    obj1.walk(); obj2.walk(); obj3.walk();
    obj1 = obj3;
    obj1.walk();
    }
}
