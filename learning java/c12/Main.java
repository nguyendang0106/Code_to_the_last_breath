package c12;

class Car {
    public static int numberOfCars = 0; // Classifier attribute (Thuộc tính mức lớp)

    public Car() {
        numberOfCars++; // Mỗi lần tạo đối tượng, giá trị này tăng
    }

    public static void displayTotalCars() { // Classifier method (Thao tác mức lớp)
        System.out.println("Total cars: " + numberOfCars);
    }
}

public class Main {
    public static void main(String[] args) {
        Car car1 = new Car();
        Car car2 = new Car();

        Car.displayTotalCars(); // Output: Total cars: 2
    }
}
