import java.util.ArrayList;

class MathOperations<T extends Number> {
    private T value;

    public MathOperations(T value) {
        this.value = value;
    }

    public void add(T other) {
        if (value instanceof Integer) {
            value = (T) Integer.valueOf(value.intValue() + other.intValue());
        } else if (value instanceof Double) {
            value = (T) Double.valueOf(value.doubleValue() + other.doubleValue());
        } else if (value instanceof Float) {
            value = (T) Float.valueOf(value.floatValue() + other.floatValue());
        } else if (value instanceof Long) {
            value = (T) Long.valueOf(value.longValue() + other.longValue());
        } else if (value instanceof Short) {
            value = (T) Short.valueOf((short) (value.shortValue() + other.shortValue()));
        } else if (value instanceof Byte) {
            value = (T) Byte.valueOf((byte) (value.byteValue() + other.byteValue()));
        } else {
            throw new UnsupportedOperationException("Unsupported type");
        }
    }

    public T getValue() {
        return value;
    }
}

class Dict<T1 extends Comparable<T1>, T2 extends Number> {
    ArrayList<T1> keys;
    ArrayList<MathOperations<T2>> values;

    Dict() {
        keys = new ArrayList<>();
        values = new ArrayList<>();
    }

    int find(T1 element) {
        if (keys.size() == 0)
            return -1;
        int val = -1;
        for (int i = 0; i < keys.size(); i++) {
            if (keys.get(i).compareTo(element) == 0) {
                val = i;
                break;
            }
        }
        return val;
    }

    void insert(T1 key, T2 obj) {
        int i = find(key);
        if (i == -1) {
            keys.add(key);
            values.add(new MathOperations<>(obj));
        } else {
            values.set(i, new MathOperations<>(obj));
        }
    }

    T2 get(T1 key) {
        int i = find(key);
        if (i != -1) {
            return values.get(i).getValue();
        } else return null;
    }
}

class FindDuplicate {
    static <T extends Comparable<T>> ArrayList<T> find(T[] arr) {
        ArrayList<T> dup = new ArrayList<>();
        Dict<T, Integer> dict = new Dict<>();
        for (T a : arr) {
            int i = dict.find(a);
            if (i == -1) {
                dict.insert(a, 1);
            } else {
                dict.values.get(i).add(1);
            }
        }
        for (int i = 0; i < dict.values.size(); i++) {
            int a = (int) dict.get(dict.keys.get(i));
            if (a > 1)
                dup.add(dict.keys.get(i));
        }
        return dup;
    }
}

class Main {
    public static void main(String[] args) {
        Integer[] arr = {1, 2, 1, 2, 1, 3, 4, 3, 6, 6, 2, 2, 3};
        ArrayList<Integer> arr_dup = FindDuplicate.find(arr);
        System.out.println(arr_dup);

        Double[] arr1 = {1.45, 2.86, 1.45, 2.86, 1.34, 3.56, 4.01, 3.56, 1.45, 6.18, 2.86};
        ArrayList<Double> arr_dup1 = FindDuplicate.find(arr1);
        System.out.println(arr_dup1);

        String[] arr2 = {"banana", "melon", "orange", "orange", "grape", "grape", "melon"};
        ArrayList<String> arr_dup2 = FindDuplicate.find(arr2);
        System.out.println(arr_dup2);
    }
}