class Room{
	double height, width, breadth;

	public Room(double a, double b, double c){
		this.height = a;
		this.width = b;
		this.breadth = c;
	}

	double volume(){
		return height*width*breadth;
	}
}

class RoomDemo{
	public static void main(String[] args){
		Room bedroom = new Room(12, 10, 10);
		Room dining = new Room(10, 10.5, 9.5);

		double bedR, dinR;
		bedR = bedroom.volume();
		dinR = dining.volume();

		System.out.println("bedroom size " + bedR + " cubic feet");
		 System.out.println("diningroom size " + dinR + " cubic feet");
	}
}

	
