#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------- Base Classes ----------
class Person {
protected:
    string name, id;
    int age;
public:
    Person(string n, int a, string i) : name(n), age(a), id(i) {}
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << endl;
    }
    virtual double calculatePayment() { return 0.0; }
};

class Student : public Person {
protected:
    float gpa;
public:
    Student(string n, int a, string i, float g) : Person(n, a, i), gpa(g) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "GPA: " << gpa << endl;
    }
    double calculatePayment() override { return 1500.0; }
};

class Professor : public Person {
protected:
    string department;
public:
    Professor(string n, int a, string i, string d) : Person(n, a, i), department(d) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << department << endl;
    }
    double calculatePayment() override { return 5000.0; }
};

// ---------- Extended Subclasses ----------
class UndergraduateStudent : public Student {
    string major;
public:
    UndergraduateStudent(string n, int a, string i, float g, string m)
        : Student(n, a, i, g), major(m) {}
    void displayDetails() override {
        Student::displayDetails();
        cout << "Major: " << major << endl;
    }
};

class GraduateStudent : public Student {
    string thesis;
public:
    GraduateStudent(string n, int a, string i, float g, string t)
        : Student(n, a, i, g), thesis(t) {}
    void displayDetails() override {
        Student::displayDetails();
        cout << "Thesis: " << thesis << endl;
    }
};

class AssistantProfessor : public Professor {
    int experience;
public:
    AssistantProfessor(string n, int a, string i, string d, int e)
        : Professor(n, a, i, d), experience(e) {}
    void displayDetails() override {
        Professor::displayDetails();
        cout << "Experience: " << experience << " years\n";
    }
    double calculatePayment() override {
        return 5000 + experience * 200;
    }
};

// ---------- Aggregation & Composition ----------
class Course {
    string title;
    Professor* instructor;
    vector<Student*> students;
public:
    Course(string t, Professor* p) : title(t), instructor(p) {}
    void enroll(Student* s) {
        students.push_back(s);
    }
    void displayCourse() {
        cout << "\nCourse: " << title << endl;
        cout << "Instructor:\n";
        instructor->displayDetails();
        cout << "Enrolled Students:\n";
        for (Student* s : students) s->displayDetails();
    }
};

class Department {
    string name;
    vector<Professor*> profs;
public:
    Department(string n) : name(n) {}
    void addProfessor(Professor* p) {
        profs.push_back(p);
    }
    void displayDept() {
        cout << "\nDepartment: " << name << endl;
        for (Professor* p : profs) p->displayDetails();
    }
};

// ---------- Test Program ----------
int main() {
    UndergraduateStudent* s1 = new UndergraduateStudent("Alice", 19, "S001", 3.8, "CSE");
    GraduateStudent* s2 = new GraduateStudent("Bob", 24, "S002", 3.6, "AI in Healthcare");

    AssistantProfessor* p1 = new AssistantProfessor("Dr. Khan", 40, "P001", "Computer Science", 10);

    Course* c1 = new Course("AI Basics", p1);
    c1->enroll(s1);
    c1->enroll(s2);

    Department dept("Computer Science");
    dept.addProfessor(p1);

    cout << "===== UNIVERSITY DETAILS =====" << endl;
    dept.displayDept();
    c1->displayCourse();

    // Clean up
    delete s1;
    delete s2;
    delete p1;
    delete c1;

    return 0;
}