#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int marks[5];
    float average;
    Student* next;

   
    Student(string n, int r, int m[]) {
   name = n;
 rollNumber = r;
    for (int i = 0; i < 5; i++) {
      marks[i] = m[i];
}
        calculateAverage();
        next = NULL; 
    }

  
    void calculateAverage() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        average = sum / 5.0;
    }
};

class StudentList {
public:
    Student* head;

    StudentList() {
        head = NULL; 
		// nullptr ki jagah NULL
    }

    void addStudent(string name, int rollNumber, int marks[]) {
        Student* newStudent = new Student(name, rollNumber, marks);
        if (!head || newStudent->average > head->average) {
            newStudent->next = head;
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next && temp->next->average > newStudent->average) {
                temp = temp->next;
            }
            newStudent->next = temp->next;
            temp->next = newStudent;
        }
    }

    void displayStudents() {
        Student* temp = head;
        while (temp) {
   cout << "Name: " << temp->name << ", Roll Number: " << temp->rollNumber << ", Average Marks: " << temp->average << endl;
    temp = temp->next;
    }
    }

    ~StudentList() {
     Student* temp;
while (head) {
   temp = head;
  head = head->next;
cout << "Memory released for " << temp->name << endl;
  delete temp;
 }
    }
};

int main() {
    StudentList students;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
 string name;
  int rollNumber, marks[5];
  cout << "Enter name, roll number, and 5 subject marks for student " << i + 1 << ": ";
  cin >> name >> rollNumber;
    for (int j = 0; j < 5; j++) {
    cin >> marks[j];
    }
    students.addStudent(name, rollNumber, marks);
    }

    cout << "\nSorted Student Details (by highest average marks):" << endl;
    students.displayStudents();

    return 0;
}