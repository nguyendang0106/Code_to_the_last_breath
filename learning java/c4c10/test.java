package c4c10;

public class test {
    public static void main(String[] args) {
        BankAccount acc1 = new BankAccount("Alice");
        acc1.setOwner("Hoa");
        System.out.println(acc1.getOwner());
        
        acc1.methodA();
        acc1.methodB();
    }
}

class BankAccount {
    private String owner;
    private double balance;

    public BankAccount(String name) {
        setOwner(name);
    }

    public void setOwner(String o) {
        owner = o;
    }

    public String getOwner() {
        return owner;
    }

    // Phương thức gây ra ngoại lệ và xử lý tại chỗ
    public void methodA() {
        try {
            int[] numbers = {1, 2};
            System.out.println(numbers[2]); // Gây ra ArrayIndexOutOfBoundsException
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Exception handled in methodA: " + e.getMessage());
        }
    }

    // Phương thức gây ra ngoại lệ và ủy nhiệm
    public void methodB() throws ArrayIndexOutOfBoundsException {
        int[] numbers = {1, 2};
        System.out.println(numbers[2]); // Gây ra ArrayIndexOutOfBoundsException
    }

    public void methodC() {
        try {
            methodB(); // Xử lý ngoại lệ từ methodB
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Exception handled in methodC: " + e.getMessage());
        }
    }
}
