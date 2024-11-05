class Sort {
 
    public static <T extends Comparable<T>> void quickSort(T[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    private static <T extends Comparable<T>> int partition(T[] arr, int low, int high) {
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j].compareTo(pivot) < 0) {
                i++;
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        T temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    public static <T> void printArray(T[] arr) {
        for (T a : arr) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Integer[] intArr = {5, 8, 3, 7, 2, 0, 1, 6, 3, 11, 29, 12, 9, 7};
        System.out.println("Initial Integer Array:");
        printArray(intArr);
        quickSort(intArr, 0, intArr.length - 1);
        System.out.println("Sorted Integer Array:");
        printArray(intArr);

        String[] strArr = {"h", "t", "b", "e", "f", "d", "c"};
        System.out.println("Initial String Array:");
        printArray(strArr);
        quickSort(strArr, 0, strArr.length - 1);
        System.out.println("Sorted String Array:");
        printArray(strArr);
    }
}
