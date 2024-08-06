#include <iostream>
#include <cstdlib> // for system("cls")
using namespace std;

const int MAX_BOOK = 5; // Maximum number of books that can be borrowed

// function line
void line() {
    cout << "---------------------------------------------------------\n";
}

// function presence
void presence() {
    string id;

    cout << "Student ID Number : ";
    cin.ignore(); //to clear the input buffer
    getline(cin, id);
    cout << "\nAttendance Successful!\n";
}

// function borrow a book
void borrowBook(string bookList[]) {
    string name, id, date;
    int bookIndex;

    cout << "Enter the borrower's name : ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter student ID number : ";
    getline(cin, id);

    // book list
    cout << "\nList of Available Books : \n";
    for (int i = 0; i < MAX_BOOK; i++) {
        cout << i + 1 << ". " << bookList[i] << endl;
    }

    cout << "\nEnter the number of the book you want to borrow [1-" << MAX_BOOK << "] : ";
    cin >> bookIndex;

    if (bookIndex < 1 || bookIndex > MAX_BOOK) {
        cout << "\nInvalid book selection. Please try again.\n";
        return;
    }

    cout << "Enter borrow date : ";
    cin.ignore();
    getline(cin, date);
    cout << "\nBook Borrowed Successfully!\n";
}

// function return a book
void returnBook() {
    string name, id, date;
    int bookIndex;

    cout << "Enter the borrower's name : ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter student ID number : ";
    getline(cin, id);
    cout << "Enter the number of the book you want to return [1-" << MAX_BOOK << "] : ";
    cin >> bookIndex;

    if (bookIndex < 1 || bookIndex > MAX_BOOK) {
        cout << "\nInvalid book selection. Please try again.\n";
        return;
    }

    cout << "Enter return date : ";
    cin.ignore();
    getline(cin, date);
    cout << "\nBook Successfully Returned!\n";
}

int main() {
    int menu;
    string bookList[MAX_BOOK] = {"Bumi", "Harry Potter", "Laut Bercerita", "Dikta dan Hukum", "13 Reason Why"};
    char opt = 'Y';
    
    cout << string(10, '-') << " Welcome to DreamCloud Center " << string(10, '-') << endl;
    cout << "Please Register First!\n" << endl;
    presence();
    line();

    do {
        cout << "\nMENU LIST : " << endl;
        cout << "1. Borrow a Book" << endl;
        cout << "2. Return a Book" << endl;
        cout << "Select Menu (1/2) : ";
        cin >> menu;
        line();
        cout << endl;

        if (menu == 1) {
            borrowBook(bookList);
        } else if (menu == 2) {
            returnBook();
        } else {
            cout << "Invalid menu selection. Please try again.\n";
        }

        cout << "\nSelect another menu? (Y/N) : ";
        cin >> opt;
        line();

    } while ((opt == 'Y') || (opt == 'y'));

    system("cls"); // Clears the screen on Windows
    cout << "\nThank You For Coming To DreamCloud Center!";
}

