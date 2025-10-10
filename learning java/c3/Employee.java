package c3;

public class Employee extends Person {
    String name;
    public void setName(String name) {
        this.name = name;
    }

    public int setSalary(int salary) {
        this.salary = salary;
        return salary;
    }
    
}
