#include <iostream>
#include <string>
using namespace std;

struct Ticket {
    string passengerName;
    int trainNumber;
    int seatNumber;
    Ticket* next;
};

void reserveTicket(Ticket*& head, string name, int trainNumber, int seatNumber) {
    Ticket* newTicket = new Ticket{name, trainNumber, seatNumber, nullptr};
    newTicket->next = head;
    head = newTicket;
}

void cancelTicket(Ticket*& head, int seatNumber) {
    if (!head) return; 
    if (head->seatNumber == seatNumber) { 
        Ticket* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Ticket* current = head;
    while (current->next && current->next->seatNumber != seatNumber) {
        current = current->next;
    }
    if (current->next) {
        Ticket* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

void displayTickets(Ticket* head) {
    Ticket* current = head;
    while (current) {
        cout << "Passenger: " << current->passengerName << ", Train: " << current->trainNumber << ", Seat: " << current->seatNumber << endl;
        current = current->next;
    }
}
void clearTickets(Ticket*& head) {
    while (head) {
        Ticket* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Ticket* system = nullptr; 
    int numberOfTickets;

    cout << "Enter the number of tickets to reserve: ";
    cin >> numberOfTickets;

    
    for (int i = 0; i < numberOfTickets; i++) {
        string name;
        int trainNumber, seatNumber;

        cout << "Enter passenger name for ticket " << (i + 1) << ": ";
        cin >> name;
        cout << "Enter train number for ticket " << (i + 1) << ": ";
        cin >> trainNumber;
        cout << "Enter seat number for ticket " << (i + 1) << ": ";
        cin >> seatNumber;

        reserveTicket(system, name, trainNumber, seatNumber);
    }
    cout << "\nReserved Tickets:\n";
    displayTickets(system);

    int seatToCancel;
    cout << "\nEnter Seat Number to Cancel: ";
    cin >> seatToCancel;
    cancelTicket(system, seatToCancel);

    cout << "\nUpdated Ticket List:\n";
    displayTickets(system);


    return 0;
}