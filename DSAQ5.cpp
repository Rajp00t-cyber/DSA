#include <iostream>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;
    Contact* next;

    Contact(string n, string phone) {
        name = n;
        phoneNumber = phone;
        next = nullptr;
    }
};

class ContactBook {
private:
    Contact* head;

public:
    ContactBook() { head = nullptr; }

    void addContact(string name, string phoneNumber) {
        Contact* newContact = new Contact(name, phoneNumber);
        newContact->next = head;
        head = newContact;
    }
    void deleteContact(string name) {
        if (!head) return; 
        if (head->name == name) {
            Contact* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Contact* current = head;
        while (current->next && current->next->name != name) {
            current = current->next;
        }
        if (current->next) { 
            Contact* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
    void displayContacts() {
        Contact* current = head;
        while (current) {
            cout << "Name: " << current->name << ", Phone: " << current->phoneNumber << endl;
            current = current->next;
        }
    }
    void searchContact(string name) {
        Contact* current = head;
        while (current) {
            if (current->name == name) {
                cout << "Contact Found - Name: " << current->name << ", Phone: " << current->phoneNumber << endl;
                return;
            }
            current = current->next;
        }
        cout << "Contact not found.\n";
    }

    ~ContactBook() {
        while (head) {
            Contact* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ContactBook contactBook;
    
    contactBook.addContact("Rabia", "1234567890");
    contactBook.addContact("Sonia", "9876543210");
    
    cout << "Contact List:\n";
    contactBook.displayContacts();
    
    cout << "\nSearching for Sonia:\n";
    contactBook.searchContact("Sonia");
    
    cout << "\nDeleting Rabia:\n";
    contactBook.deleteContact("Rabia");
    
    cout << "\nUpdated Contact List:\n";
    contactBook.displayContacts();
    
    return 0;
}