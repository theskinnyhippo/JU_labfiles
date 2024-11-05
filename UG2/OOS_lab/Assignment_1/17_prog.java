
class Book{
    private String title;
    private String author;
    private String publisher;
    private double cost;
    private int stock;

    public Book(String title, String author, String publisher, double cost, int stock){
        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.cost = cost;
        this.stock = stock;
    }

    public void displayDetails(){
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Publisher: " + publisher);
        System.out.println("Cost: " + cost);
        System.out.println("Stock: " + stock);
    }

    public void checkAvailability(int requiredCopies){
        if (stock >= requiredCopies){
            System.out.println("Book is available.");
            displayDetails();
            processSale(requiredCopies);
            System.out.println();
        }else{
            System.out.println("Book is not in stock.");
            System.out.println();
        }
    }

    private void processSale(int requiredCopies){
        if (stock >= requiredCopies){
            double totalCost = cost * requiredCopies;
            System.out.println("Total cost for " + requiredCopies + " copies: " + totalCost);
            stock -= requiredCopies;
        }else{
            System.out.println("Required copies not in stock.");
        }
    }

    public static void main(String[] args){
        Book book1 = new Book("The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", 15.99, 10);
        Book book2 = new Book("The Apple of my Eye", "Unknown", "Sundar and Lishoah prod.", 19.99, 21);

        book1.checkAvailability(3);
        book2.checkAvailability(8);
    }
}
