#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    string model;
    float price;
    Car* next;
    Car(string b, string m, float p) {
        brand = b;
        model = m;
        price = p;
        next = nullptr;
    }
};

class CarShowroom {
private:
    Car* head;
public:
    CarShowroom() { head = nullptr; }
    void addCar(string brand, string model, float price) {
        Car* newCar = new Car(brand, model, price);
        newCar->next = head;
        head = newCar;
    }
    void displayCars() {
        Car* current = head;
        while (current) {
            cout << "Brand: " << current->brand << ", Model: " << current->model << ", Price: $" << current->price << endl;
            current = current->next;
        }
    }
    void deleteCar(string model) {
        if (!head) return;
        if (head->model == model) {
            Car* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Car* current = head;
        while (current->next && current->next->model != model) {
            current = current->next;
        }
        if (current->next) {
            Car* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
    ~CarShowroom() {
        while (head) {
            Car* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    CarShowroom showroom;
    showroom.addCar("Toyota", "Camry", 25000);
    showroom.addCar("Honda", "Civic", 22000);
    
    cout << "Available Cars:\n";
    showroom.displayCars();
    
    cout << "\nDeleting Car Model: Civic\n";
    showroom.deleteCar("Civic");
    
    cout << "\nUpdated Car List:\n";
    showroom.displayCars();
    
    return 0;
}