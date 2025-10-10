package c4c10;
class MultipleCatch1 {
    public static void main(String args[])
    {
        try {
            String inputArgs[] = {"5", "6", "7"};
            String num = inputArgs[1];
            int numValue = Integer.parseInt(num);
            System.out.println("Dien tich hv la: "
            
            + numValue * numValue);
        
        } catch(ArrayIndexOutOfBoundsException e1) {
            System.out.println("Hay nhap canh cua hv!");
        } catch(NumberFormatException e2){
            System.out.println("Hay nhap 1 so!");
        }
    }
}

    