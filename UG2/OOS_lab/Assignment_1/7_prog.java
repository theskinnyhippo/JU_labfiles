abstract class Publication{
    private int noOfPages;
    private double price;
    private String publisherName;

    public Publication(int noOfPages, double price, String publisherName){
        this.noOfPages = noOfPages;
        this.price = price;
        this.publisherName = publisherName;
    }

    public int getNoOfPages(){
        return noOfPages;
    }

    public double getPrice(){
        return price;
    }

    public String getPublisherName(){
        return publisherName;
    }

    public void setNoOfPages(int noOfPages){
        this.noOfPages = noOfPages;
    }

    public void setPrice(double price){
        this.price = price;
    }

    public void setPublisherName(String publisherName){
        this.publisherName = publisherName;
    }

    public abstract void displayDetails();
}

class Book extends Publication{
    private String title;
    private String author;

    public Book(String title, String author, int noOfPages, double price, String publisherName){
        super(noOfPages, price, publisherName);
        this.title = title;
        this.author = author;
    }

    @Override
    public void displayDetails(){
        System.out.println("Book Details:");
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Number of Pages: " + getNoOfPages());
        System.out.println("Price: " + getPrice());
        System.out.println("Publisher: " + getPublisherName());
        System.out.println("--------------------------");
    }
}

class Journal extends Publication{
    private String journalName;
    private int issueNumber;

    public Journal(String journalName, int issueNumber, int noOfPages, double price, String publisherName){
        super(noOfPages, price, publisherName);
        this.journalName = journalName;
        this.issueNumber = issueNumber;
    }

    @Override
    public void displayDetails(){
        System.out.println("Journal Details:");
        System.out.println("Journal Name: " + journalName);
        System.out.println("Issue Number: " + issueNumber);
        System.out.println("Number of Pages: " + getNoOfPages());
        System.out.println("Price: " + getPrice());
        System.out.println("Publisher: " + getPublisherName());
        System.out.println("--------------------------");
    }
}

class Library{
    private java.util.List<Publication> publications;

    public Library(){
        publications = new java.util.ArrayList<>();
    }

    public void addPublication(Publication publication){
        publications.add(publication);
    }

    public void displayAllPublications(){
        System.out.println("Details of all Publications in the Library:");
        for (Publication publication : publications){
            publication.displayDetails();
        }
    }
}
class Main{
    public static void main(String[] args){
        Library library = new Library();

        Book book1 = new Book("The Catcher in the Rye", "J.D. Salinger", 220, 15.99, "Little, Brown and Company");
        Book book2 = new Book("To Kill a Mockingbird", "Harper Lee", 300, 12.50, "J.B. Lippincott & Co.");
        Book book3 = new Book("1984", "George Orwell", 350, 18.99, "Secker & Warburg");

        Journal journal1 = new Journal("Science Journal", 25, 50, 5.99, "Nature Publishing Group");
        Journal journal2 = new Journal("Medical Journal", 18, 40, 7.99, "Elsevier");
 
        library.addPublication(book1);
        library.addPublication(book2);
        library.addPublication(book3);
        library.addPublication(journal1);
        library.addPublication(journal2);

        library.displayAllPublications();
    }
}
