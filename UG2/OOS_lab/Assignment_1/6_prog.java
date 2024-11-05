import java.util.ArrayList;

class Employee{
    private String name;
    private int id;
    private String address;
    private double salary;

    public Employee(String name, int id, String address, double salary){
        this.name = name;
        this.id = id;
        this.address = address;
        this.salary = salary;
    }

    public double getSalary(){
        return salary;
    }
}

class Dept{
    private String name;
    private String location;
    private ArrayList<Employee> employees;

    public Dept(String name, String location){
        this.name = name;
        this.location = location;
        this.employees = new ArrayList<>();
    }
    
    public String getName(){
        return this.name;
    }

    public void addEmployee(Employee employee){
        employees.add(employee);
    }

    public void removeEmployee(Employee employee){
        employees.remove(employee);
    }

    public double calculateYearlyExpenditure(){
        double yearlyExpendITdre = 0;
        for (Employee employee : employees){
            yearlyExpendITdre += employee.getSalary();
        }
        return yearlyExpendITdre;
    }
}

class Main{
    public static void main(String[] args){
        Dept ITdept = new Dept("Information Technology", "Salt Lake");

        ITdept.addEmployee(new Employee("Dhattarwal", 101, "123 Main LM", 61000));
        ITdept.addEmployee(new Employee("Singh", 102, "456 2nd St", 75000));
        ITdept.addEmployee(new Employee("Arora", 103, "789 3rd Rd", 80000));
        ITdept.addEmployee(new Employee("Rana", 104, "101 4th Rd", 110000));
        ITdept.addEmployee(new Employee("Hapal", 105, "202 5th St", 270000));

        System.out.println("Yearly Expenditure for " + ITdept.getName() + " department: $" + ITdept.calculateYearlyExpenditure());
    }
}
