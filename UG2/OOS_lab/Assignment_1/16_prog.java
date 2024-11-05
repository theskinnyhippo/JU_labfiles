interface Fruit{
    void hasAPeel();
}

interface Vegetable{
    void hasARoot();
}

class Tomato implements Fruit, Vegetable{
    @Override
    public void hasAPeel(){
        System.out.println("Tomato has a peel.");
    }

    @Override
    public void hasARoot(){
        System.out.println("Tomato has a root.");
    }
}

class Main{
    public static void main(String[] args){
        Tomato tomato = new Tomato();

        System.out.println("Details of Tomato :-");
        System.out.println("```````````````````");
        tomato.hasAPeel();
        tomato.hasARoot();
    }
}

