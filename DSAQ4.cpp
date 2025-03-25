#include <iostream>
#include <string>
using namespace std;
struct Student {
    string name;
    int rollNumber;
    int marks; 
    Student* next;
};

void insertStudent(Student*& head, string name, int rollNumber, int marks) {
    Student* newStudent = new Student{name, rollNumber, marks, nullptr};
    if (!head || head->rollNumber > rollNumber) {
        newStudent->next = head;
        head = newStudent;
        return;
    }
    Student* current = head;
    while (current->next && current->next->rollNumber < rollNumber) {
        current = current->next;
    }
    newStudent->next = current->next;
    current->next = newStudent;
}
void deleteStudent(Student*& head, int rollNumber) {
    if (!head) return; 
    if (head->rollNumber == rollNumber) { 
        Student* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Student* current = head;
    while (current->next && current->next->rollNumber != rollNumber) {
        current = current->next;
    }
    if (current->next) { 
        Student* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}
void displayStudents(Student* head) {
    Student* current = head;
    while (current) {
        cout << "Name: " << current->name << ", Roll Number: " << current->rollNumber << ", Marks: " << current->marks << endl;
        current = current->next;
    }
}

void clearDatabase(Student*& head) {
    while (head) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Student* database = nullptr;
    int numberOfStudents;

    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; i++) {
        string name;
        int rollNumber, marks;

        cout << "Enter name for student " << (i + 1) << ": ";
        cin >> name;
        cout << "Enter roll number for student " << (i + 1) << ": ";
        cin >> rollNumber;
        cout << "Enter marks for student " << (i + 1) << ": ";
        cin >> marks;

        insertStudent(database, name, rollNumber, marks);
    }

    cout << "\nStudent Records:\n";
    displayStudents(database);

    int rollToDelete;
    cout << "\nEnter Roll Number of Student to Delete: ";
    cin >> rollToDelete;
    deleteStudent(database, rollToDelete);

    cout << "Updated Student Records:\n";
    displayStudents(database);


    return 0;
}