#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include<algorithm>
using namespace std;

// ---------- Base Class ----------
class Person {
protected:
    string name;
    int age;
    string ID;
    string contact;

public:
    Person() {}
    Person(string n, int a, string id, string c) {
        setName(n);
        setAge(a);
        ID = id;
        contact = c;
    }

    virtual ~Person() {}

    // Encapsulation
    void setName(string n) {
        if (n.empty()) throw invalid_argument("Name cannot be empty");
        name = n;
    }

    void setAge(int a) {
        if (a <= 0 || a > 120) throw invalid_argument("Invalid age");
        age = a;
    }

    string getName() const { return name; }
    int getAge() const { return age; }

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << ", Contact: " << contact << endl;
    }

    virtual double calculatePayment() const {
        return 0.0;
    }
};

// ---------- Derived Classes ----------
class Student : public Person {
protected:
    string enrollmentDate;
    string program;
    float GPA;

public:
    Student(string n, int a, string id, string c, string ed, string p, float g)
        : Person(n, a, id, c), enrollmentDate(ed), program(p), GPA(g) {
        setGPA(g);
    }

    void setGPA(float g) {
        if (g < 0.0 || g > 4.0) throw invalid_argument("Invalid GPA");
        GPA = g;
    }

    float getGPA() const { return GPA; }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << GPA << ", Enrollment Date: " << enrollmentDate << endl;
    }

    double calculatePayment() const override {
        return 1000.0;  // Placeholder tuition
    }
};

class Professor : public Person {
    string department;
    string specialization;
    string hireDate;

public:
    Professor(string n, int a, string id, string c, string d, string s, string h)
        : Person(n, a, id, c), department(d), specialization(s), hireDate(h) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << ", Specialization: " << specialization << ", Hire Date: " << hireDate << endl;
    }

    double calculatePayment() const override {
        return 5000.0;  // Placeholder salary
    }
};

// ---------- Other Core Classes ----------
class Course {
    string code, title, description;
    int credits;

public:
    Course(string c, string t, int cr, string d) : code(c), title(t), credits(cr), description(d) {
        if (credits <= 0) throw invalid_argument("Invalid course credits");
    }

    void display() const {
        cout << "Course Code: " << code << ", Title: " << title << ", Credits: " << credits << endl;
    }
};

class Department {
    string name, location;
    float budget;

public:
    Department(string n, string l, float b) : name(n), location(l), budget(b) {}

    void display() const {
        cout << "Department: " << name << ", Location: " << location << ", Budget: $" << budget << endl;
    }
};

// ---------- Encapsulation ----------
class GradeBook {
    map<string, float> grades;

public:
    void addGrade(string studentID, float grade) {
        if (grade < 0.0 || grade > 100.0) throw invalid_argument("Invalid grade");
        grades[studentID] = grade;
    }

    float calculateAverageGrade() const {
        float sum = 0;
        for (auto &g : grades) sum += g.second;
        return grades.empty() ? 0.0 : sum / grades.size();
    }

    float getHighestGrade() const {
        float max = 0;
        for (auto &g : grades) if (g.second > max) max = g.second;
        return max;
    }
};

class EnrollmentManager {
    map<string, vector<string>> enrollment;

public:
    void enrollStudent(string courseCode, string studentID) {
        enrollment[courseCode].push_back(studentID);
    }

    void dropStudent(string courseCode, string studentID) {
        auto &students = enrollment[courseCode];
        students.erase(remove(students.begin(), students.end(), studentID), students.end());
    }

    int getEnrollmentCount(string courseCode) const {
        auto it = enrollment.find(courseCode);
        return it == enrollment.end() ? 0 : it->second.size();
    }
};

// ---------- Test Program ----------
int main() {
    try {
        Student s1("Alice", 20, "S101", "1234567890", "2023-01-01", "CS", 3.8);
        Student s2("Bob", 22, "S102", "0987654321", "2023-01-01", "IT", 3.5);

        Professor p1("Dr. Smith", 45, "P201", "555-1234", "CS", "AI", "2010-08-01");
        Professor p2("Dr. Jane", 50, "P202", "555-5678", "Math", "Statistics", "2008-09-01");

        Course c1("CS101", "Intro to C++", 3, "Basics of C++");
        Department d1("Computer Science", "Block A", 1000000);

        // Display polymorphic behavior
        vector<Person*> people = { &s1, &s2, &p1, &p2 };
        for (Person* person : people) {
            person->displayDetails();
            cout << "Payment: $" << person->calculatePayment() << endl;
            cout << "--------------------" << endl;
        }

        GradeBook gb;
        gb.addGrade("S101", 85);
        gb.addGrade("S102", 90);
        cout << "Average Grade: " << gb.calculateAverageGrade() << ", Highest Grade: " << gb.getHighestGrade() << endl;

        EnrollmentManager em;
        em.enrollStudent("CS101", "S101");
        em.enrollStudent("CS101", "S102");
        cout << "Enrollment in CS101: " << em.getEnrollmentCount("CS101") << endl;
    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}