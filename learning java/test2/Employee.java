package test2;

class Employee extends Person {
    // @Override
    // private void print1() {
    //     System.out.println(name);
    // }
    public Employee(String name) {
        super(name);
    }

    @Override
    protected String print2() {
        System.out.println(super.print2());
        return super.print2();
    }

    @Override
    protected String print3() {
        System.out.println(super.print3());
        return super.print3();
    }
}
