#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string course;
    float marks;
};

void addStudent() {
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Course: ";
    cin >> s.course;

    cout << "Enter Marks: ";
    cin >> s.marks;

    ofstream file("students.txt", ios::app);

    file << s.rollNo << " "
         << s.name << " "
         << s.course << " "
         << s.marks << endl;

    file.close();

    cout << "\nStudent added successfully!\n";
}

void displayStudents() {
    Student s;

    ifstream file("students.txt");

    cout << "\n----- Student Records -----\n";

    while (file >> s.rollNo >> s.name >> s.course >> s.marks) {
        cout << "\nRoll Number: " << s.rollNo;
        cout << "\nName: " << s.name;
        cout << "\nCourse: " << s.course;
        cout << "\nMarks: " << s.marks << endl;
    }

    file.close();
}

void updateStudent() {
    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    Student s;
    bool found = false;

    while (file >> s.rollNo >> s.name >> s.course >> s.marks) {

        if (s.rollNo == roll) {
            found = true;

            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Course: ";
            cin >> s.course;

            cout << "Enter New Marks: ";
            cin >> s.marks;
        }

        temp << s.rollNo << " "
             << s.name << " "
             << s.course << " "
             << s.marks << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent updated successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    Student s;
    bool found = false;

    while (file >> s.rollNo >> s.name >> s.course >> s.marks) {

        if (s.rollNo == roll) {
            found = true;
            continue;
        }

        temp << s.rollNo << " "
             << s.name << " "
             << s.course << " "
             << s.marks << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent deleted successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            updateStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "\nThank you!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
