package test2;

class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    private String print1() {
        return name;
    }

    protected String print2() {
        return name.toUpperCase();
    }

    protected String print3() {
        return name.toLowerCase();
    }
}
