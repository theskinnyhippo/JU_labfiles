import java.util.ArrayList;

class Stack{
    ArrayList<Integer> data;
    int size;
    int top;
    
    public Stack(int vol){
        this.top = -1;
        this.size = vol;
        this.data = new ArrayList<>();
    }
    
    void push(int m){
        if(this.top == size-1){
            System.out.println("Stack Overflow!");
        }else{
            data.add(m);
            this.top++;
        }
    }
    
    void pop(){
        if(this.top == -1){
            System.out.println("Stack Underflow!");
        }else{
            data.remove(top--);
        }
    }
    
    void print(){
        System.out.println("Stack...");
        for(int i : data){
            System.out.println(i);
        }
    }
}

class Main{
    public static void main(String[] args){
        Stack s = new Stack(30);
        
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(15);
        s.push(19);
        
        s.print();
        
        s.pop();
        s.pop();
        s.pop();
	System.out.println("popped 3 times");        

        s.print();
    }
}	
