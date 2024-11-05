import java.util.ArrayList;
import java.util.List;

class Account{
    Account(int accountNumber, String holderName, double balance){
        this.accountNumber = accountNumber;
        this.holderName = holderName;
        this.balance = balance;
    }

    int getAccountNumber(){
        return accountNumber;
    }

    String getHolderName(){
        return holderName;
    }

    double getBalance(){
        return balance;
    }

    void setBalance(double balance){
        this.balance = balance;
    }

    @Override
    public String toString(){
        return "\nAccount Number = " + accountNumber +
                "\nHolder Name = " + holderName +
                "\nBalance = " + balance + " INR";
    }

    private final int accountNumber;
    private final String holderName;
    private double balance;
}

class SavingsAccount extends Account{
    SavingsAccount(int accountNumber, String holderName, double balance){
        super(accountNumber, holderName, balance);
    }

    void setInterestRate(double newRate){
        this.interestRate = newRate;
    }

    double getInterestRate(){
        return interestRate;
    }

    double calculateYearlyInterest(){
        return getBalance() * interestRate;
    }

    @Override
    public String toString(){
        return super.toString() +
                "\nInterest Rate = " + interestRate;
    }

    private double interestRate = 0.05;
}

class CurrentAccount extends Account{
    CurrentAccount(int accountNumber, String holderName, double balance){
        super(accountNumber, holderName, balance);
    }
}

class Manager{
    Manager(){
        this.accounts = new ArrayList<>();
    }

    void addAccount(Account account){
        accounts.add(account);
    }

    List<Account> getAccounts(){
        return accounts;
    }

    private final List<Account> accounts;
}

class Main{
    public static void main(String[] args){
        Manager manager = new Manager();

        manager.addAccount(new SavingsAccount(100, "Ashutosh Bagchi", 10000));
        manager.addAccount(new SavingsAccount(200, "Savage Iyer", 20000));

        manager.addAccount(new CurrentAccount(300, "Anjana Mallik", 10000));
        manager.addAccount(new CurrentAccount(400, "Shannidha Bose", 20000));
        manager.addAccount(new CurrentAccount(500, "Jotayu Sen", 30000));

        for(Account account : manager.getAccounts()){
            System.out.println(account);
            if (account instanceof SavingsAccount){
                SavingsAccount savingsAccount = (SavingsAccount) account;
                System.out.println("Yearly interest: " + savingsAccount.calculateYearlyInterest());
            }
        }
    }
}

