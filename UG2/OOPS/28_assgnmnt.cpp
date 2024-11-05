#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class gradecard {
private:
    string dept;
    string name;
    int roll;
    int sem;
    pair<string, int> subjects[5];
    double cg;

public:
    gradecard() : dept(""), name(""), roll(0), sem(0), cg(0.0) {}

    gradecard(const string& d, const string& n, int r, int s) : dept(d), name(n), roll(r), sem(s), cg(0.0) {}

    void subject(const string& sub, int marks, int i) {
        subjects[i] = make_pair(sub, marks);
    }

    static int random(int u, int l) {
        int r = u - l + 1;
        r = (rand() % r) + l;
        return r;
    }

    int getmarks(int index) const {
        return subjects[index].second;
    }

    void cgpa() {
        double credit = 0;
        double grade_point = 0;

        for (int i = 0; i < 5; i++) {
            int marks = subjects[i].second;
            if (marks >= 90)
                grade_point += 10.0;
            else if (marks >= 80)
                grade_point += 9.0;
            else if (marks >= 70)
                grade_point += 8.0;
            else if (marks >= 60)
                grade_point += 7.0;
            else if (marks >= 50)
                grade_point += 6.0;

            credit += 1;
        }

        if (credit > 0) {
            cg = grade_point/credit;
        }
    }

    double getcg() const {
        return cg;
    }

    int getroll() const {
        return roll;
    }

    string getname() const {
        return name;
    }

    string getdept() const {
        return dept;
    }
};

int main() {
    gradecard k[60];

    for (int i = 0; i < 60; i++) {
        string dept = "IT";
        string name = "student " + to_string(i + 11);
        int roll = 1000 + i;
        int sem = 3;

        gradecard g(dept, name, roll, sem);

        g.subject("math", g.random(100, 30), 0);
        g.subject("DSA", g.random(100, 30), 1);
        g.subject("OOP", g.random(100, 30), 2);
        g.subject("COA", g.random(100, 30), 3);
        g.subject("ASM", g.random(100, 30), 4);

        g.cgpa();
        k[i] = g;
    }

    cout << "Stud_name   dept   Roll   math   DSA   OOP   COA   ASM   CGPA" << endl;

        for (int i = 0; i < 60; i++) {
        cout << k[i].getname() << "    " << k[i].getdept() << "    " << k[i].getroll();
        for (int j = 0; j < 5; j++) {
            cout << "    " << k[i].getmarks(j);
        }
        cout << "    " << k[i].getcg() << endl;
    }
}
