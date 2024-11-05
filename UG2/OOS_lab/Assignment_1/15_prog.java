class Tollbooth{
    private int carsWithoutPaying;
    private int totalCars;
    private double totalCashCollected;

    public Tollbooth(){
        carsWithoutPaying = 0;
        totalCars = 0;
        totalCashCollected = 0.0;
    }

    public void carPasses(){
        totalCars++;
        totalCashCollected += 50.0;
    }

    public void carPassesWithoutPaying(){
        carsWithoutPaying++;
        totalCars++;
    }

    public void displayResults(){
        System.out.println("Results:");
        System.out.println("Total number of cars passed by without paying: " + carsWithoutPaying);
        System.out.println("Total number of cars passed by: " + totalCars);
        System.out.println("Total cash collected: Rs. " + totalCashCollected);
    }
}

class Main{
    public static void main(String[] args){
        Tollbooth tollbooth = new Tollbooth();

        tollbooth.carPasses();
        tollbooth.carPasses();
        tollbooth.carPasses();
        tollbooth.carPasses();
        tollbooth.carPassesWithoutPaying();
        tollbooth.carPassesWithoutPaying();
        tollbooth.carPasses();
        tollbooth.carPassesWithoutPaying();
        tollbooth.carPasses();

        tollbooth.displayResults();
    }
}
