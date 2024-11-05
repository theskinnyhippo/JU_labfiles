import java.lang.reflect.*;

class Main {
    public static void main(String[] args) {
        MyClass obj = new MyClass();

        Class<?> clazz = obj.getClass();
        System.out.println("Class Name: " + clazz.getName());

        Method[] methods = clazz.getMethods();
        System.out.println("Methods:");
        for (Method method : methods) {
            System.out.println(method.getName());
        }

        Constructor<?>[] constructors = clazz.getConstructors();
        System.out.println("Constructors:");
        for (Constructor<?> constructor : constructors) {
            System.out.println(constructor.getName());
        }

        try {
            Method setNameMethod = clazz.getDeclaredMethod("setName", String.class);
            System.out.println("Declared method: " + setNameMethod.getName());
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }

        try {
            Field ageField = clazz.getDeclaredField("age");
            System.out.println("Declared field: " + ageField.getName());
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        }

        try {
            Field ageField = clazz.getDeclaredField("age");
            ageField.setAccessible(true);
            ageField.setInt(obj, 30);
            System.out.println("Age set via reflection: " + obj.getAge());
        } catch (NoSuchFieldException | IllegalAccessException e) {
            e.printStackTrace();
        }
    }
}

class MyClass {
    private String name;
    private int age;

    public MyClass() {}

    public MyClass(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}
