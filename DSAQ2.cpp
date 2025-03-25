#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title, author, ISBN;
    int availableCopies;
    Book* next; 
    Book(string t, string a, string i, int copies) {
        title = t;
        author = a;
        ISBN = i;
        availableCopies = copies;
        next = NULL;
    }
    void issueBook() {
        if (availableCopies > 0) {
            availableCopies--;
            cout << "Book issued: " << title << endl;
        } else {
            cout << "No copies left for: " << title << endl;
        }
    }

    // Return a book
    void returnBook() {
        availableCopies++;
        cout << "Book returned: " << title << endl;
    }

    // Display book details
    void display() {
        cout << "Title: " << title << ", Author: " << author 
             << ", ISBN: " << ISBN << ", Copies: " << availableCopies << endl;
    }
};

class Library {
public:
    Book* head;
    Library() {
        head = NULL;
    }
    void addBook(string title, string author, string ISBN, int copies) {
        Book* newBook = new Book(title, author, ISBN, copies);
        if (!head) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
    }
    void displayBooks() {
        Book* temp = head;
        while (temp) {
            temp->display();
            temp = temp->next;
        }
    }
    void issueBook(string title) {
        Book* temp = head;
        while (temp) {
            if (temp->title == title) {
                temp->issueBook();
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found!\n";
    }

    void returnBook(string title) {
        Book* temp = head;
        while (temp) {
            if (temp->title == title) {
                temp->returnBook();
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found!\n";
    }

  
    ~Library() {
        Book* temp;
        while (head) {
            temp = head;
            head = head->next;
            cout << "Deleting book: " << temp->title << endl;
            delete temp;
        }
    }
};

int main() {
    Library library;
    int n;
    cout << "Enter number of books: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        string title, author, ISBN;
        int copies;
        cout << "Enter title, author, ISBN, copies: ";
        getline(cin, title);
        getline(cin, author);
        getline(cin, ISBN);
        cin >> copies;
        

        library.addBook(title, author, ISBN, copies);
    }
    cout << "\nBooks in Library:\n";
    library.displayBooks();

    string bookToIssue, bookToReturn;
    cout << "\nEnter book title to issue: ";
    getline(cin, bookToIssue);
    library.issueBook(bookToIssue);

    cout << "\nEnter book title to return: ";
    getline(cin, bookToReturn);
    library.returnBook(bookToReturn);

    return 0;
}