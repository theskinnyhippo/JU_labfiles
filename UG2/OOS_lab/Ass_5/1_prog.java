interface Shape{
    void draw();
}

class Circle implements Shape{
    @Override
    public void draw(){
        System.out.println("Drawing Circle");
    }
}
class Rectangle implements Shape{
    @Override
    public void draw(){
        System.out.println("Drawing Rectangle");
    }
}
class Square implements Shape{
    @Override
    public void draw(){
        System.out.println("Drawing Square");
    }
}
enum ShapeType{
    CIRCLE,
    RECTANGLE,
    SQUARE
}
class ShapeFactory{
    public static Shape createShape(ShapeType shapeType){
        switch(shapeType){
            case CIRCLE:
                return new Circle();
            case RECTANGLE:
                return new Rectangle();
            case SQUARE:
                return new Square();
            default:
                throw new IllegalArgumentException("Invalid shape type: " + shapeType);
        }
    }
}
class FactoryPatternExample{
    public static void main(String[] args){
        Shape circle = ShapeFactory.createShape(ShapeType.CIRCLE);
        Shape rectangle = ShapeFactory.createShape(ShapeType.RECTANGLE);
        Shape square = ShapeFactory.createShape(ShapeType.SQUARE);
        circle.draw();
        rectangle.draw();
        square.draw();
    }
}

