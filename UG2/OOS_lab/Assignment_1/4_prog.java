class BankAccount {
    private int accountNumber;
    private double balance;
    private String ownerName;

    public BankAccount(int accountNumber, double balance, String ownerName){
        this.accountNumber = accountNumber;
        this.balance = balance;
        this.ownerName = ownerName;
    }

    public double getBalance(){
        return balance;
    }
	
    public int getAccountNumber(){
        return accountNumber;
    }
    
    public String getOwnerName(){
        return ownerName;
    }

    public void add(double amount){
        balance += amount;
        System.out.println("Deposited $" + amount + " into account " + accountNumber);
    }

    public void subtract(double amount){
        if (amount <= balance){
            balance -= amount;
            System.out.println("Withdrawn $" + amount + " from account " + accountNumber);
        } else {
            System.out.println("Insufficient funds in account " + accountNumber);
        }
    }
}

class AccountManager{
    private BankAccount[] acc;
    private int k;

    public AccountManager(int capacity){
        acc = new BankAccount[capacity];
        k = 0;
    }

    public void create(int accountNumber, double initialBalance, String ownerName){
        if (k < acc.length){
            BankAccount newAccount = new BankAccount(accountNumber, initialBalance, ownerName);
            acc[k] = newAccount;
            k++;
            System.out.println("Account created successfully.");
        }else{
            System.out.println("Cannot create more acc. Bank is at full capacity.");
        }
    }

    public void delete(int accountNumber){
        for (int i = 0; i < k; i++){
            if (acc[i].getAccountNumber() == accountNumber){
                acc[i] = acc[k - 1];
                acc[k - 1] = null;
                k--;
                System.out.println("Account deleted successfully.");
                return;
            }
        }
        System.out.println("Account with account number " + accountNumber + " not found.");
    }

    public void deposit(int accountNumber, double amount){
        for (BankAccount account : acc){
            if (account.getAccountNumber() == accountNumber){
                account.add(amount);
                return;
            }
        }
        System.out.println("Account with account number " + accountNumber + " not found.");
    }

    public void withdraw(int accountNumber, double amount){
        for (BankAccount account : acc){
            if (account.getAccountNumber() == accountNumber){
                account.subtract(amount);
                return;
            }
        }
        System.out.println("Account with account number " + accountNumber + " not found.");
    }

    public void printAccountDetails(){
        for (BankAccount account : acc){
            if (account != null){
                System.out.println("Account Number: " + account.getAccountNumber());
                System.out.println("Owner Name: " + account.getOwnerName());
                System.out.println("Balance: $" + account.getBalance());
                System.out.println("-----------------------");
	    }
        }
    }
}

class Bank{
    public static void main(String[] args){
        AccountManager accountManager = new AccountManager(5);

        accountManager.create(1001, 1500.0, "Person_1");
        accountManager.create(1002, 2000.0, "Person_2");
        accountManager.create(1003, 1000.0, "Person_3");
        accountManager.create(1004, 2500.0, "Person_4");
        accountManager.create(1005, 1800.0, "Person_5");
	
	System.out.println();
        System.out.println("Details of all acc in the bank:");
    	System.out.println("==============================");
	accountManager.printAccountDetails();
    }
}
