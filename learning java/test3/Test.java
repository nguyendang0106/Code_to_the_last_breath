package test3;

public class Test {
    public static int example() {
        try {
            System.out.println("In try block");
            return 1; // Giá trị này được lưu tạm thời
        } finally {
            System.out.println("In finally block");
            // return 2; // Giá trị này ghi đè lên giá trị từ try
        }
    }

    public static void main(String[] args) {
        int result = example();
        System.out.println("Returned value: " + result);
    }
}
