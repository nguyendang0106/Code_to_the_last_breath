package c5;

class TestStatic{
    public static int iStatic;
    public int iNonStatic;
}

public class Test {

    public static void change(Student std){

        std.setYear(2000);
        
    }
    public static void tricky(Point arg1, Point arg2) {
        arg1.setX(100); arg1.setY(100);
        Point temp = arg1;
        arg1 = arg2; arg2 = temp;
    }

    public static int plus(int... arr) {
        int result = 0;
        for (int i : arr) {
        result += i;
        }
        return result;
    }
    public static void main(String args[]) {
        MyClass m = new MyClass();
        // m.myMethod(); // error do không có method phù hợp
        // m.myMethod(9, 10); // error do có 2 phiên bản method phù hợp

        BankAccount acc1 = new BankAccount();
        BankAccount acc2 = new BankAccount("Thuy", 100);

        TestStatic obj1 = new TestStatic();

        obj1.iStatic = 10; obj1.iNonStatic = 11;
        System.out.println(obj1.iStatic + "," + obj1.iNonStatic);
        TestStatic obj2 = new TestStatic();
        System.out.println(obj2.iStatic + "," + obj2.iNonStatic);
        obj2.iStatic = 12;
        System.out.println(obj1.iStatic + "," + obj1.iNonStatic);

        Student std = new Student("Nam", 1990);
        System.out.println(std.getYear());
        change(std);
        System.out.println(std.getYear());

        Point pnt1 = new Point(0,0);
        Point pnt2 = new Point(0,0);
        pnt1.printPoint(); pnt2.printPoint();
        System.out.println(); tricky(pnt1, pnt2);
        pnt1.printPoint(); pnt2.printPoint();

        System.out.println(plus(1, 2, 3, 4, 5));

        System.out.println("answer = " + 1 + 2 + 3);
        System.out.println("answer = " + (1+2+3));
    }
}
