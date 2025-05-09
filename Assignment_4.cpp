#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
using namespace std;

// --- Custom Exceptions ---
class UniversityException : public exception {
    string msg;
public:
    UniversityException(string m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

// --- Basic Classes ---
class Student {
    string id, name;
    float gpa;
public:
    Student(string i, string n, float g) : id(i), name(n), gpa(g) {
        if (g < 0 || g > 4) throw UniversityException("GPA must be between 0 and 4");
    }

    string getID() const { return id; }
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }
};

class GradeBook {
    map<string, float> grades;
public:
    void addGrade(string id, float grade) {
        if (grade < 0 || grade > 100) throw UniversityException("Invalid grade");
        grades[id] = grade;
    }

    void showGrades() const {
        for (auto& g : grades)
            cout << "Student " << g.first << ": " << g.second << endl;
    }
};

// --- University System ---
class UniversitySystem {
    vector<Student> students;
    GradeBook gb;

public:
    void addStudent(string id, string name, float gpa) {
        try {
            students.emplace_back(id, name, gpa);
            cout << "Student added.\n";
        } catch (exception& e) {
            cout << e.what() << endl;
        }
    }

    void enterGrade(string id, float grade) {
        try {
            gb.addGrade(id, grade);
            cout << "Grade recorded.\n";
        } catch (exception& e) {
            cout << e.what() << endl;
        }
    }

    void report() const {
        cout << "\n--- Students ---\n";
        for (const auto& s : students) s.display();
        cout << "--- Grades ---\n";
        gb.showGrades();
    }
};

// --- Main Menu ---
int main() {
    UniversitySystem us;
    int choice;
    string id, name;
    float gpa, grade;

    while (true) {
        cout << "\n1.Add Student 2.Enter Grade 3.Report 0.Exit\nChoice: ";
        cin >> choice;
        if (choice == 0) break;
        switch (choice) {
            case 1:
                cout << "ID Name GPA: ";
                cin >> id >> name >> gpa;
                us.addStudent(id, name, gpa);
                break;
            case 2:
                cout << "Student ID and Grade: ";
                cin >> id >> grade;
                us.enterGrade(id, grade);
                break;
            case 3:
                us.report();
                break;
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}