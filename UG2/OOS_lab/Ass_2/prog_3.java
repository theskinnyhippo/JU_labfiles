class SequenceGenerator {
    private int Num;
    private int n = 1;
    private boolean ready = false;
    private double fact = 1;
    private double result = 1;

    SequenceGenerator(int Num) {
        this.Num = Num;
    }

    synchronized void factorial() {
        while (n <= Num) {
            if (!ready) {
                fact = 1;
                for (int i = 1; i <= n; i++) {
                    fact *= i;
                }
                ready = true;
            } else {
                try {
                    wait();
                } catch (InterruptedException e) {
                    System.out.println("Factorial Interrupted");
                }
            }
            notify();
        }
    }

    synchronized void addSum() {
        while (n <= Num) {
            if (ready) {
                result += 1.0 / fact;
                n++;
                ready = false;
            } else {
                try {
                    wait();
                } catch (InterruptedException e) {
                    System.out.println("Sum Interrupted");
                }
            }
            notify();
        }
    }

    double getResult() {
        return result;
    }
}

class Producer extends Thread {
    private SequenceGenerator generator;

    Producer(SequenceGenerator generator) {
        this.generator = generator;
    }

    @Override
    public void run() {
        generator.factorial();
    }
}

class Consumer extends Thread {
    private SequenceGenerator generator;

    Consumer(SequenceGenerator generator) {
        this.generator = generator;
    }

    @Override
    public void run() {
        generator.addSum();
    }
}

class Main {
    public static void main(String[] args) {
        int Num = 20;
        SequenceGenerator obj = new SequenceGenerator(Num);

        Producer t1 = new Producer(obj);
        Consumer t2 = new Consumer(obj);

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            System.out.println("Interrupted Join");
        }
        System.out.println("Sum of sequence: " + obj.getResult());
    }
}
