import java.lang.Math;
class Complex{
    double real, img;
    
    public Complex(){
        real = 0;
        img = 0;
    }
    
    public Complex(double r, double i){
        real = r;
        img = i;
    }
    
    public Complex(Complex obj){
        this.real = obj.real;
        this.img = obj.img;
    }
    
    Complex add(Complex target){
        Complex temp = new Complex(this.real + target.real, this.img + target.img);
        return temp;
    }
    
    Complex substract(Complex target){
        Complex temp = new Complex(this.real - target.real, this.img - target.img);
        return temp;
    }
    
    Complex mul(Complex target){
        Complex temp = new Complex((this.real*target.real)-(this.img*target.img),(this.real*target.img)+(this.img*target.real));
        return temp;
    }
    
    Complex div(Complex target){
            double k = Math.sqrt(target.real*target.real - target.img*target.img);
        if(k != 0){
            Complex temp = new Complex((this.real*target.real)+(this.img*target.img),(this.img*target.real)-(this.real*target.img));
            return temp;
        }else{
            System.out.println("Zero error!");
            return null;
        }
    }
    
    void display(){
        System.out.println(real + " + " + img + "i");
    }
    
    public static void main(String[] args){
        Complex c1 = new Complex(3,2);
        Complex c2 = new Complex(4,-2);
        
        Complex c3 = c1.add(c2);
        Complex c4 = c1.mul(c2);
        
        System.out.print("c1 = ");
        c1.display();
        
        System.out.print("c2 = ");
         c2.display();
         
        System.out.println("============");
        
        System.out.print("Summation = ");
        c3.display();
        System.out.print("Product = ");
        c4.display();
    }
}
