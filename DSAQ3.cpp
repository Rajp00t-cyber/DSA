#include <iostream>
using namespace std;

struct Employee {
    string name;
    int empID;
    float basicSalary;
    float allowances[3];
    float totalEarnings;
    Employee* next; 
    Employee(string n, int id, float salary, float allow[]) {
        name = n;
        empID = id;
        basicSalary = salary;
        totalEarnings = salary;
        for (int i = 0; i < 3; i++) {
            allowances[i] = allow[i];
            totalEarnings += allow[i];
        }
        next = NULL;
    }
    void displayDetails() {
        cout << "Employee ID: " << empID << endl;
        cout << "Name: " << name << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "Allowances: $" << allowances[0] << ", $" << allowances[1] << ", $" << allowances[2] << endl;
        cout << "Total Earnings: $" << totalEarnings << endl;
        cout << "----------------------" << endl;
    }
};

class EmployeeList {
public:
    Employee* head;

    EmployeeList() {
        head = NULL;
    }
    void addEmployee(string name, int id, float salary, float allowances[]) {
        Employee* newEmployee = new Employee(name, id, salary, allowances);
        if (!head || newEmployee->totalEarnings > head->totalEarnings) {
            newEmployee->next = head;
            head = newEmployee;
        } else {
            Employee* temp = head;
            while (temp->next && temp->next->totalEarnings > newEmployee->totalEarnings) {
                temp = temp->next;
            }
            newEmployee->next = temp->next;
            temp->next = newEmployee;
        }
    }
    void displayEmployees() {
        Employee* temp = head;
        while (temp) {
            temp->displayDetails();
            temp = temp->next;
        }
    }
    ~EmployeeList() {
        Employee* temp;
        while (head) {
            temp = head;
            head = head->next;
            cout << "Memory released for Employee= " << temp->name << endl;
            delete temp;
        }
    }
};

int main() {
    EmployeeList employees;
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int id;
        float salary, allowances[3];

        cout << "Enter Employee Name= ";
        cin >> name;
        cout << "Enter Employee ID= ";
        cin >> id;
        cout << "Enter Basic Salary= ";
        cin >> salary;
        cout << "Enter 3 Allowances= ";
        for (int j = 0; j < 3; j++) {
            cin >> allowances[j];
        }
		employees.addEmployee(name, id, salary, allowances);
    }
    cout << "\nEmployee Details (Sorted by Highest Earnings)=\n";
    employees.displayEmployees();

    return 0;
}