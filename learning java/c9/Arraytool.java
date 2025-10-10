package c9;

import java.util.Iterator;

public class Arraytool {
    // Phương thức in các phần tử trong mảng String
    public static void print(String[] a) {
        for (String e : a) System.out.print(e + " ");
            System.out.println();
    }
    
    // Phương thức in các phần tử trong mảng với kiểu
    // dữ liệu bất kỳ
    public static <E> void print(E[] a) {
        for (E e : a) System.out.print(e + " ");
            System.out.println();
    }

    // Dành cho mảng int[]
    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public interface List<E> {
        void add(E x);
        Iterator<E> iterator();
    }
    
}
