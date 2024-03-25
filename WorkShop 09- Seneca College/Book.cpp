#include "Book.h"

// Default constructor
Book::Book() : LibraryItem(), m_author(nullptr) {}

// Parameterized constructor
Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year) {
    m_author = new char[strlen(author) + 1];
    strcpy(m_author, author);
}

// Copy constructor
Book::Book(const Book& other) : LibraryItem(other), m_author(nullptr) {
    m_author = new char[strlen(other.m_author) + 1];
    strcpy(m_author, other.m_author);
}

// Copy assignment operator
Book& Book::operator=(const Book& other) {
    if (this != &other) { 
        LibraryItem::operator=(other);
        delete[] m_author;
        m_author = new char[strlen(other.m_author) + 1];
        strcpy(m_author, other.m_author);
    }
    return *this;
}

// Destructor
Book::~Book() {
    delete[] m_author;
}

// Method to display the title, year, and author of the book
ostream& Book::display(ostream& ostr) const {
    LibraryItem::display(ostr);
    ostr << endl << "Author: " << m_author;
    return ostr;
}

// Operator > to compare authors
bool Book::operator >(const Book& other) const {
    return (m_author != nullptr && other.m_author != nullptr) && (strcmp(m_author, other.m_author) > 0);
}
