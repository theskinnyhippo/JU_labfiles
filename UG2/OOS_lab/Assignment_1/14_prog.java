interface Shape{
    double area();
    void draw();
    void rotate();
    void move(int x, int y);
}

class Circle implements Shape{
    private double radius;
    private int x, y;

    public Circle(double radius){
        this.radius = radius;
    }

    @Override
    public double area(){
        return Math.PI * radius * radius;
    }

    @Override
    public void draw(){
        System.out.println("Drawing a circle.");
    }

    @Override
    public void rotate(){
        System.out.println("Rotating the circle.");
    }

    @Override
    public void move(int x, int y){
        this.x = x;
        this.y = y;
        System.out.println("Moving the circle to coordinates (" + x + ", " + y + ").");
    }
}

class Rectangle implements Shape{
    private double length, width;
    private int x, y;

    public Rectangle(double length, double width){
        this.length = length;
        this.width = width;
    }

    @Override
    public double area(){
        return length * width;
    }

    @Override
    public void draw(){
        System.out.println("Drawing a rectangle.");
    }

    @Override
    public void rotate(){
        System.out.println("Rotating the rectangle.");
    }

    @Override
    public void move(int x, int y){
        this.x = x;
        this.y = y;
        System.out.println("Moving the rectangle to coordinates (" + x + ", " + y + ").");
    }
}

class Main{
    public static void main(String[] args){
        Circle circle1 = new Circle(5.0);
        Circle circle2 = new Circle(8.0);

        Rectangle rectangle1 = new Rectangle(4.0, 6.0);
        Rectangle rectangle2 = new Rectangle(7.0, 10.0);
        Rectangle rectangle3 = new Rectangle(3.0, 4.0);

        System.out.println("Details before moving:");
        printDetails(circle1);
        printDetails(circle2);
        printDetails(rectangle1);
        printDetails(rectangle2);
        printDetails(rectangle3);

        circle1.move(2, 3);
        circle2.move(5, 7);
        rectangle1.move(1, 1);
        rectangle2.move(8, 9);
        rectangle3.move(3, 5);

        System.out.println("\nDetails after moving:");
        printDetails(circle1);
        printDetails(circle2);
        printDetails(rectangle1);
        printDetails(rectangle2);
        printDetails(rectangle3);
    }

    private static void printDetails(Shape shape){
        System.out.println("Area: " + shape.area());
        shape.draw();
        shape.rotate();
        System.out.println();
    }
}
