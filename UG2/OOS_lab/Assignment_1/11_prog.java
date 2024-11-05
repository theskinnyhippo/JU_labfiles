class Date {
    private int day, month, year;
    
    public Date() {
        this(1, 1, 1970);
    }

    public Date(int day) {
        this(day, 1, 1970);
    }

    public Date(int day, int month) {
        this(day, month, 1970);
    }

    public Date(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public Date getPreviousDay() {
        if (day > 1) {
            return new Date(day - 1, month, year);
        } else {
            if (month > 1) {
                int previousMonthDays = getDaysInMonth(month - 1, year);
                return new Date(previousMonthDays, month - 1, year);
            } else {
                return new Date(31, 12, year - 1);
            }
        }
    }

    public Date getNextDay() {
        int daysInMonth = getDaysInMonth(month, year);
        if (day < daysInMonth) {
            return new Date(day + 1, month, year);
        } else {
            if (month < 12) {
                return new Date(1, month + 1, year);
            } else {
                return new Date(1, 1, year + 1);
            }
        }
    }

    public void printDate() {
        System.out.println(day + "/" + month + "/" + year);
    }

    private int getDaysInMonth(int month, int year) {
        if (month == 2) {
            return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28; 
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }
}

class Main {
    public static void main(String[] args) {
        Date date1 = new Date(1, 3, 2001);
        Date date2 = new Date(30, 1);
        Date date3 = new Date();
        Date date4 = new Date(6);
        Date date5 = new Date(1, 3, 2024);

        Date nextDay1 = date1.getNextDay();
        System.out.println("Next day: ");
        nextDay1.printDate();
        Date previousDay1 = date1.getPreviousDay();
        System.out.println("Previous day: ");
        previousDay1.printDate();

        System.out.println();
        
        Date nextDay2 = date2.getNextDay();
        System.out.println("Next day: ");
        nextDay2.printDate();
        Date previousDay2 = date2.getPreviousDay();
        System.out.println("Previous day: ");
        previousDay2.printDate();
        
        System.out.println();

        Date nextDay3 = date3.getNextDay();
        System.out.println("Next day: ");
        nextDay3.printDate();
        Date previousDay3 = date3.getPreviousDay();
        System.out.println("Previous day: ");
        previousDay3.printDate();
        
        System.out.println();

        Date nextDay4 = date4.getNextDay();
        System.out.println("Next day: ");
        nextDay4.printDate();
        Date previousDay4 = date4.getPreviousDay();
        System.out.println("Previous day: ");
        previousDay4.printDate();
        
        System.out.println();

        Date nextDay5 = date5.getNextDay();
        System.out.println("Next day: ");
        nextDay5.printDate();
        Date previousDay5 = date5.getPreviousDay();
        System.out.println("Previous day: ");
        previousDay5.printDate();
    }
}
