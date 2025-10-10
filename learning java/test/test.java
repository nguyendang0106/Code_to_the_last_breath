package test;

public class test {
    int i = 111;
    static int j = 222;
    static void method(int i, int j) {
        System.out.print(i);
        System.out.print(j);
    }

    public static void main(String[] args) {
        test.method(333, 444);
    }
    
}
