package c6;

public class HinhVuong extends TuGiac {
    public HinhVuong(){
        super(new Diem(0,0), new Diem(0,1),
        new Diem(1,1),new Diem(1,0));
    
        d1 = new Diem(0,0); d2 = new Diem(0,1);
        d3 = new Diem(1,0); d4 = new Diem(1,1);
    
    }
}
