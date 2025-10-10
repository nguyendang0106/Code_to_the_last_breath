package c6;

public class Main {
    public static void main(String[] args) {
        // Tạo các đối tượng Diem
        Diem p1 = new Diem(0, 0);
        Diem p2 = new Diem(0, 1);
        Diem p3 = new Diem(1, 1);
        Diem p4 = new Diem(1, 0);

        // Tạo một đối tượng TuGiac bằng cách truyền vào các đối tượng Diem
        TuGiac tg = new TuGiac(p1, p2, p3, p4);

        // In tọa độ các điểm của tứ giác
        tg.printTuGiac();

        // Đối tượng Diem vẫn tồn tại độc lập
        System.out.println("Điểm p1:");
        p1.printDiem();
    }
}
