package c9;

public class Information<T> {
    private T value;
    public Information(T value) {
        this.value = value;
    }
    public T getValue() {
        return value;
    }
    
}
