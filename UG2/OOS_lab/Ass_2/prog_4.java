import java.io.FileReader;

class ReaderAndSum{
    int sum;
    private int number;
    private int ch;
    private FileReader fr;
    private boolean flag;
    boolean endRead, endAdd;

    ReaderAndSum(FileReader fr){
        number = 0;
        sum = 0;
        this.fr = fr;
        flag = false;
        endAdd = endRead = false;
    }

    synchronized void read() throws Exception{
        while(flag){
            try{
                wait();
            } catch(Exception e){
                e.printStackTrace();
            }
        }

        number = 0;
        ch = fr.read();
        while(ch >= 0){
            number = number * 10 +(ch - '0');
            ch = fr.read();
            if(ch == ' ')
                break;
        }

        if(ch < 0){
            endRead = true;
        }
        flag = true;
        notify();
    }

    synchronized void add(){
        while(!flag){
            try{
                wait();
            } catch(Exception e){
                e.printStackTrace();
            }
        }
        sum += number;

        flag = false;
        if(ch < 0)
            endAdd = true;
        notify();
    }

    public synchronized int getSum(){
        return sum;
    }
}

class Producer extends Thread{
    ReaderAndSum reader;

    Producer(ReaderAndSum reader){
        super("producer");
        this.reader = reader;
    }

    public void run(){
        while(!reader.endRead){
            try{
                reader.read();
            } catch(Exception e){
                e.printStackTrace();
                reader.endAdd = reader.endRead = true;
                reader.sum = -1;
                System.exit(0);
            }
        }
    }
}

class Consumer extends Thread{
    ReaderAndSum reader;

    Consumer(ReaderAndSum reader){
        super("consumer");
        this.reader = reader;
    }

    public void run(){
        while(!reader.endAdd)
            reader.add();
    }
}

class Main{
    public static void main(String[] args) throws Exception{
        int ch;
        FileReader fr = null;
        try{
            fr = new FileReader("file.txt");
        } catch(Exception e){
            System.out.println("File is not found");
            System.exit(0);
        }
        ReaderAndSum rm = new ReaderAndSum(fr);
        Producer pd = new Producer(rm);
        Consumer cm = new Consumer(rm);
        pd.start();
        cm.start();
        pd.join();
        cm.join();
        System.out.println(" Sum : " + rm.getSum());
    }
}

