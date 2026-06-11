#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int age;

    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void display() {
        cout << "Roll: " << roll
             << " | Name: " << name
             << " | Age: " << age << endl;
    }
};

//ADD STUDENT 
void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    s.input();
    file << s.roll << " " << s.name << " " << s.age << endl;

    file.close();
    cout << "Student Added Successfully!\n";
}

// DISPLAY STUDENTS
void displayStudents() {
    Student s;
    ifstream file("students.txt");

    cout << "\n--- Student Records ---\n";

    while (file >> s.roll >> s.name >> s.age) {
        s.display();
    }

    file.close();
}

//UPDATE STUDENT
void updateStudent() {
    int rollNo;
    cout << "Enter Roll No to Update: ";
    cin >> rollNo;

    Student s;
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    bool found = false;

    while (file >> s.roll >> s.name >> s.age) {
        if (s.roll == rollNo) {
            cout << "Enter new details:\n";
            s.input();
            found = true;
        }
        temp << s.roll << " " << s.name << " " << s.age << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student Updated Successfully!\n";
    else
        cout << "Student Not Found!\n";
}

//  DELETE STUDENT
void deleteStudent() {
    int rollNo;
    cout << "Enter Roll No to Delete: ";
    cin >> rollNo;

    Student s;
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    bool found = false;

    while (file >> s.roll >> s.name >> s.age) {
        if (s.roll == rollNo) {
            found = true;
            continue; 
        }
        temp << s.roll << " " << s.name << " " << s.age << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student Deleted Successfully!\n";
    else
        cout << "Student Not Found!\n";
}


int main() {
    int choice;

    while (true) {
        cout << "\n Student Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
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
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid Choice!\n";
        }
    }
}