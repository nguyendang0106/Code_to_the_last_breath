package c8;

public class Test {
    static String teamInfo(Person p1, Person p2) {

    p1.setName("a");
    p2.setName("b");
    return "Leader: " + p1.getName() + ", member: " + p2.getName();

    }
    public static void main(String arg[]) {
    
    Employee e = new Employee();
    Person p;
    p = e;
    p.setName("Hoa");
    ((Employee) p).setSalary(350000);

    e = new Employee();
    p = e; // upcasting
    Employee ee = (Employee) p; // downcasting
    Manager m = (Manager) ee; // run-time error

    Person p2 = new Manager();
    Employee e2 = (Employee) p2;
        
    Person p3 = new Employee();
    Manager e3 = (Manager) p3;
    
    }
}

