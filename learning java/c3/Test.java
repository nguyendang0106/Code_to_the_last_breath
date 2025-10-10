package c3;

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

    Employee e1 = new Employee();
    Employee e2 = new Employee();
    Manager m1 = new Manager();
    Manager m2 = new Manager();

    System.out.println(teamInfo(e1, e2));
    System.out.println(teamInfo(m1, m2));
    System.out.println(teamInfo(m1, e2));

    e = new Employee();
    p = e; // upcasting
    Employee ee = (Employee) p; // downcasting
    Manager m = (Manager) ee; // run-time error

    Person p2 = new Manager();
    e2 = (Employee) p2;
        
    Person p3 = new Employee();
    Manager e3 = (Manager) p3;
    
    }
}
