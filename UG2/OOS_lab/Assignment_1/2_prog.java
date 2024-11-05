class Student{
	String name;
	double j_marks, c_marks, p_marks ;
	
	Student(String n, double a, double b, double c){

		this.name = n;
		this.j_marks = a;
		this.c_marks = b;
		this.p_marks = c;
	}

	double total_average(){
		return (j_marks + c_marks + p_marks)/3;
	}

	void display(){
		System.out.println(name + " total marks :- " + (j_marks+c_marks+p_marks));
	}

	public static void main(String[] args){
		Student s1 = new Student("Mandir", 91, 95, 93);
		Student s2 = new Student("Sharmistha", 95, 92, 95);

		s1.display();
		s2.display();

		System.out.println("Average marks");
		System.out.println(s1.total_average());
		System.out.println(s2.total_average());
	}
}
		
