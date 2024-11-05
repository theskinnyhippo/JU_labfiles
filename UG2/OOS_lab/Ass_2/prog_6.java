import java.util.concurrent.*;

class BinarySearchThread extends Thread{
    private int[] arr;
    private int element;
    private int startIndex;
    private int endIndex;
    private int result = -1;

    BinarySearchThread(int[] arr, int element, int startIndex, int endIndex){
        this.arr = arr;
        this.element = element;
        this.startIndex = startIndex;
        this.endIndex = endIndex;
    }

    public void run(){
        result = binarySearch(arr, element, startIndex, endIndex);
    }

    private int binarySearch(int[] arr, int element, int start, int end){
        while(start <= end){
            int mid = start +(end - start) / 2;
            if(arr[mid] == element)
                return mid;
            else if(arr[mid] < element)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    public int getResult(){
        return result;
    }
}
 
class Main{
    public static void main(String[] args){
        int n = 100; 
        int[] arr = new int[n];
        int element = 89; 
 
        for(int i = 0; i < n; i++){
            arr[i] = i + 1;
        }
   
        System.out.println("Searching Element : " + element);
 
        ExecutorService executor = Executors.newFixedThreadPool(n / 10);
 
        BinarySearchThread[] threads = new BinarySearchThread[n / 10];
        for(int i = 0; i < n / 10; i++){
            int startIndex = i * 10;
            int endIndex =(i + 1) * 10 - 1;
            threads[i] = new BinarySearchThread(arr, element, startIndex, endIndex);
            executor.execute(threads[i]);
        }
 
        executor.shutdown();
        try{
            executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        } catch(InterruptedException e){
            e.printStackTrace();
        }

 
        for(int i = 0; i < n / 10; i++){
            int result = threads[i].getResult();
            if(result != -1){
                System.out.println("Element found at index: " + result);
                return;
            }
        }
        System.out.println("Element not found.");
    }
}}
