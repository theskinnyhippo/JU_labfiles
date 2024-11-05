class SeriesCalculator{
    private int start;
    private int end;
    private int result;

    public SeriesCalculator(int start, int end){
        this.start = start;
        this.end = end;
        this.result = 0;
    }

    public int getResult(){
        return result;
    }

    public void calculateSeries(){
        for(int i = start; i <= end; i += 2){
            result += i;
        }
    }
}

class SeriesThread extends Thread{
    private SeriesCalculator calculator;

    public SeriesThread(SeriesCalculator calculator){
        this.calculator = calculator;
    }

    @Override
    public void run(){
        calculator.calculateSeries();
    }
}

class Main{
    public static void main(String[] args) throws InterruptedException{
        int n = 100;

        SeriesCalculator calculator1 = new SeriesCalculator(1, n - 1);
        SeriesCalculator calculator2 = new SeriesCalculator(2, n);

        SeriesThread thread1 = new SeriesThread(calculator1);
        SeriesThread thread2 = new SeriesThread(calculator2);

        thread1.start();
        thread2.start();

        thread1.join();
        thread2.join();

        int finalSum = calculator1.getResult() + calculator2.getResult();

        System.out.println("Final Sum: " + finalSum);
    }
}
