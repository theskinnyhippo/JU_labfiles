import java.util.ArrayList;
class Person{
    private int age, weight, height;
    private String dateOfBirth, address;
    public Person(int age, int weight, int height, String dateOfBirth, String address){
        this.age = age;
        this.weight = weight;
        this.height = height;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
    }
    public int getAge(){
        return age;
    }
    public void setAge(int age){
        this.age = age;
    }
    public int getWeight(){
        return weight;
    }
    public void setWeight(int weight){
        this.weight = weight;
    }
    public int getHeight(){
        return height;
    }
    public void setHeight(int height){
        this.height = height;
    }
    public String getDateOfBirth(){
        return dateOfBirth;
    }
    public void setDateOfBirth(String dateOfBirth){
        this.dateOfBirth = dateOfBirth;
    }
    public String getAddress(){
        return address;
    }
    public void setAddress(String address){
        this.address = address;
    }
}
class Employee extends Person{
    private int salary, experience;
    private String dateOfJoining;
    public Employee(int age, int weight, int height, String dateOfBirth, String address, int salary, String dateOfJoining, int experience){
        super(age, weight, height, dateOfBirth, address);
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.experience = experience;
    }
    public int getSalary(){
        return salary;
    }
    public void setSalary(int salary){
        this.salary = salary;
    }
    public String getDateOfJoining(){
        return dateOfJoining;
    }
    public void setDateOfJoining(String dateOfJoining){
        this.dateOfJoining = dateOfJoining;
    }
    public int getExperience(){
        return experience;
    }
    public void setExperience(int experience){
        this.experience = experience;
    }
    void displayInfo(){
        System.out.println("Employee Details:");
        System.out.println("Age: " + getAge());
        System.out.println("Weight: " + getWeight());
        System.out.println("Height: " + getHeight());
        System.out.println("Date of Birth: " + getDateOfBirth());
        System.out.println("Address: " + getAddress());
        System.out.println("Salary: " + salary);
        System.out.println("Date of Joining: " + dateOfJoining);
        System.out.println("Experience: " + experience + " years");
        System.out.println("--------------------------");
    }
}
class Student extends Person{
    private int roll;
    private ArrayList<String> listOfSubjects;
    private ArrayList<Double> marks;
    public Student(int age, int weight, int height, String dateOfBirth, String address, int roll){
        super(age, weight, height, dateOfBirth, address);
        this.roll = roll;
        this.listOfSubjects = new ArrayList<>();
        this.marks = new ArrayList<>();
    }
    public int getRoll(){
        return roll;
    }
    public void setRoll(int roll){
        this.roll = roll;
    }
    public ArrayList<String> getListOfSubjects(){
        return listOfSubjects;
    }
    public void setListOfSubjects(ArrayList<String> listOfSubjects){
        this.listOfSubjects = listOfSubjects;
    }
    public ArrayList<Double> getMarks(){
        return marks;
    }
    public void setMarks(ArrayList<Double> marks){
        this.marks = marks;
    }
    char calculateGrade(){
        double totalMarks = 0;
        for (double mark : marks){
            totalMarks += mark;
        }
        double percentage = totalMarks / marks.size();
        if (percentage >= 90){
            return 'A';
        } else if (percentage >= 80){
            return 'B';
        } else if (percentage >= 70){
            return 'C';
        } else if (percentage >= 60){
            return 'D';
        } else{
            return 'F';
        }
    }
    void displayInfo(){
        System.out.println("Student Details:");
        System.out.println("Age: " + getAge());
        System.out.println("Weight: " + getWeight());
        System.out.println("Height: " + getHeight());
        System.out.println("Date of Birth: " + getDateOfBirth());
        System.out.println("Address: " + getAddress());
        System.out.println("Roll: " + roll);
        System.out.println("List of Subjects: " + listOfSubjects);
        System.out.println("Marks: " + marks);
        System.out.println("Grade: " + calculateGrade());
        System.out.println("--------------------------");
    }
}
class Technician extends Employee{
    private String dept;
    public Technician(String dept, int age, int weight, int height, String dateOfBirth, String address, int salary, String dateOfJoining, int experience){
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
        this.dept = dept;
    }
    public String getDept(){
        return dept;
    }
    public void setDept(String dept){
        this.dept = dept;
    }
}
class Professor extends Employee{
    private ArrayList<String> courses;
    private ArrayList<Student> listOfAdvisee;
    public Professor(int age, int weight, int height, String dateOfBirth, String address, int salary, String dateOfJoining, int experience){
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
        this.courses = new ArrayList<>();
        this.listOfAdvisee = new ArrayList<>();
    }
    void addCourse(String course){
        courses.add(course);
    }
    void removeCourse(String course){
        courses.remove(course);
    }
    void addAdvisee(Student student){
        listOfAdvisee.add(student);
    }
    void removeAdvisee(Student student){
        listOfAdvisee.remove(student);
    }
    void displayInfo(){
        super.displayInfo();
        System.out.println("Professor Details:");
        System.out.println("Courses: " + courses);
        System.out.println("List of Advisees: " + listOfAdvisee);
        System.out.println("--------------------------");
    }
}
class Main{
    public static void main(String[] args){
        Employee employee = new Employee(30, 70, 180, "1990-11-01", "123 Main St", 50000, "2022-01-01", 5);
        Student student = new Student(20, 60, 160, "1995-01-01", "456 College Ave", 101);
        Technician technician = new Technician("IT", 25, 65, 175, "2000-01-01", "789 Tech St", 40000, "2020-10-01", 2);
        Professor professor = new Professor(40, 75, 175, "1980-01-01", "987 University Blvd", 80000, "2015-01-01", 15);
        student.getListOfSubjects().add("Math");
        student.getListOfSubjects().add("Physics");
        student.getMarks().add(95.0);
        student.getMarks().add(85.0);
        professor.addCourse("Computer Science");
        professor.addCourse("Data Structures");
        professor.addAdvisee(student);
        employee.displayInfo();
        student.displayInfo();
        technician.displayInfo();
        professor.displayInfo();
    }
}
