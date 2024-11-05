interface Shape {
    void draw();
}

class Circle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Circle");
    }
}

class Rectangle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Rectangle");
    }
}

abstract class ShapeDecorator implements Shape {
    protected Shape decoratedShape;

    public ShapeDecorator(Shape decoratedShape) {
        this.decoratedShape = decoratedShape;
    }

    @Override
    public void draw() {
        decoratedShape.draw();
    }
}

class RedShapeDecorator extends ShapeDecorator {
    public RedShapeDecorator(Shape decoratedShape) {
        super(decoratedShape);
    }

    @Override
    public void draw() {
        super.draw();
        setRedBorder();
    }

    private void setRedBorder() {
        System.out.println("Setting red border");
    }
}
class DecoratorPatternExample {
    public static void main(String[] args) {
        Shape circle = new Circle();
        Shape redCircle = new RedShapeDecorator(new Circle());
        Shape rectangle = new Rectangle();
        Shape redRectangle = new RedShapeDecorator(new Rectangle());

        System.out.println("Normal Circle:");
        circle.draw();

        System.out.println("\nCircle with Red Border:");
        redCircle.draw();

        System.out.println("\nNormal Rectangle:");
        rectangle.draw();

        System.out.println("\nRectangle with Red Border:");
        redRectangle.draw();
    }
}
