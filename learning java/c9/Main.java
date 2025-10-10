package c9;
import c4c10.Person;
import java.awt.Point;
import java.util.ArrayList;
import java.util.List;


public class Main {
    public static void main(String[] args) {
        Information<String> info1 = new Information<String>("Hello");
        System.out.println(info1.getValue()); // Output: Hello
        
        Information<Integer> info2 = new Information<>(123);
        System.out.println(info2.getValue()); // Output: 123
        
        Information<Person> info3 = new Information<>(new Person("Alice", 25));
        info3.getValue().introduce(); // Output: Hello, my name is Alice and I am 25 years old.

        String[] str = new String[5];
        Point[] p = new Point[3];
        int[] intnum = new int[2];

        Arraytool.print(str);
        Arraytool.print(p);

        List<String> myList = new ArrayList<String>();
        myList.add("Fred"); // OK
        // myList.add(new Dog()); //Compile error!

        String s = myList.get(0);
        System.out.println(s);
    }
    
}   
