#include <iostream>
#include <string>

using namespace std;

class Book {
    private:
        string title, author;
        int year, quantity, borrowed;
    public:
        Book(string title, string author, int year, int quantity);
        void display();
        bool borrow();
        bool returnBook();
};

Book::Book(string title, string author, int year, int quantity) {
    this->title = title;
    this->author = author;
    this->year = year;
    this->quantity = quantity;
    borrowed = 0;
}

void Book::display() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year of publication: " << year << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Borrowed: " << borrowed << endl;
}

bool Book::borrow() {
    if (borrowed == quantity) {
        cout << "This book is not available now." << endl;
        return false;
    }
    borrowed++;
    cout << "Borrow successful." << endl;
    return true;
}

bool Book::returnBook() {
    if (borrowed == 0) {
        cout << "There is no book to return." << endl;
        return false;
    }
    borrowed--;
    cout << "Return successful." << endl;
    return true;
}

int main() {
    Book book("Harry Potter", "J.K Rowling", 1925, 5);

    book.display();

    book.borrow();
    book.borrow();
    book.borrow();

    book.display();

    book.returnBook();
    book.returnBook();

    book.display();

    return 0;
}
