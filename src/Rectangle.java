public class Rectangle {
    private double height;
    private double width;
    private String color;

    public Rectangle() {
        this.setColor(color);
        this.setHeight(height);
        this.setWidth(width);
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getHeight() {
        return height;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getWidth() {
        return width;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getColor() {
        return color;
    }

    void getArea(double width,double heigth){
        System.out.println("面积："+ width* heigth);
    }

    void getLength(double width,double heigth){
        System.out.println("周长："+(width+ heigth)*2);
    }

public static void main(String[] args){
        Rectangle a=new Rectangle();
        a.setWidth(2);
        a.setWidth(3);
        a.setColor("blue");
        a.getArea(2,3);
        a.getLength(2,3);
    }
}
