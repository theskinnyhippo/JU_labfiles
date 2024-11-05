class Automobile{
    private String make;
    private String type;
    private int maxSpeed;
    private double price;
    private double mileage;
    private String registrationNumber;


    public Automobile(String make, String type, int maxSpeed, double price, double mileage, String registrationNumber){
        this.make = make;
        this.type = type;
        this.maxSpeed = maxSpeed;
        this.price = price;
        this.mileage = mileage;
        this.registrationNumber = registrationNumber;
    }


    public String getMake(){
        return make;
    }

    public void setMake(String make){
        this.make = make;
    }

    public String getType(){
        return type;
    }

    public void setType(String type){
        this.type = type;
    }

    public int getMaxSpeed(){
        return maxSpeed;
    }

    public void setMaxSpeed(int maxSpeed){
        this.maxSpeed = maxSpeed;
    }

    public double getPrice(){
        return price;
    }

    public void setPrice(double price){
        this.price = price;
    }

    public double getMileage(){
        return mileage;
    }

    public void setMileage(double mileage){
        this.mileage = mileage;
    }

    public String getRegistrationNumber(){
        return registrationNumber;
    }

    public void setRegistrationNumber(String registrationNumber){
        this.registrationNumber = registrationNumber;
    }
}

class Truck extends Automobile{
    private int capacity;
    private String hoodType;
    private int noOfWheels;


    public Truck(String make, String type, int maxSpeed, double price, double mileage, String registrationNumber,
                 int capacity, String hoodType, int noOfWheels){
        super(make, type, maxSpeed, price, mileage, registrationNumber);
        this.capacity = capacity;
        this.hoodType = hoodType;
        this.noOfWheels = noOfWheels;
    }


    public int getCapacity(){
        return capacity;
    }

    public void setCapacity(int capacity){
        this.capacity = capacity;
    }

    public String getHoodType(){
        return hoodType;
    }

    public void setHoodType(String hoodType){
        this.hoodType = hoodType;
    }

    public int getNoOfWheels(){
        return noOfWheels;
    }

    public void setNoOfWheels(int noOfWheels){
        this.noOfWheels = noOfWheels;
    }
}

class Car extends Automobile{
    private int noOfDoors;
    private int seatingCapacity;

    public Car(String make, String type, int maxSpeed, double price, double mileage, String registrationNumber,
               int noOfDoors, int seatingCapacity){
        super(make, type, maxSpeed, price, mileage, registrationNumber);
        this.noOfDoors = noOfDoors;
        this.seatingCapacity = seatingCapacity;
    }


    public int getNoOfDoors(){
        return noOfDoors;
    }

    public void setNoOfDoors(int noOfDoors){
        this.noOfDoors = noOfDoors;
    }

    public int getSeatingCapacity(){
        return seatingCapacity;
    }

    public void setSeatingCapacity(int seatingCapacity){
        this.seatingCapacity = seatingCapacity;
    }
}

class Main{
    public static void main(String[] args){
        Truck truck = new Truck("Bharat Benz", "Truck", 120, 50000.0, 12.5, "TRK123", 5000, "Open", 6);

        Car car = new Car("Mazerrati", "scorp", 150, 200000.0, 20.0, "CAR456", 2, 2);

        System.out.println("Truck details:");
        System.out.println("''''''''''''''");
        System.out.println("Make: " + truck.getMake());
        System.out.println("Type: " + truck.getType());
        System.out.println("Capacity: " + truck.getCapacity());
        System.out.println("Max Speed: " + truck.getMaxSpeed());
        System.out.println("Price: " + truck.getPrice());
        System.out.println("Mileage: " + truck.getMileage());
        System.out.println("Registration Number: " + truck.getRegistrationNumber());
        System.out.println("Hood Type: " + truck.getHoodType());
        System.out.println("No. of Wheels: " + truck.getNoOfWheels());

        
        
        System.out.println("\nCar details:");
        System.out.println("'''''''''''");
        System.out.println("Make: " + car.getMake());
        System.out.println("Type: " + car.getType());
        System.out.println("No. of Doors: " + car.getNoOfDoors());
        System.out.println("Seating Capacity: " + car.getSeatingCapacity());
        System.out.println("Max Speed: " + car.getMaxSpeed());
        System.out.println("Price: " + car.getPrice());
        System.out.println("Mileage: " + car.getMileage());
        System.out.println("Registration Number: " + car.getRegistrationNumber());
    }
}
