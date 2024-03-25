#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <cstring> 

class Book : public LibraryItem {
private:
    char* m_author;

public:
    Book();

    Book(const char* title, int year, const char* author);
    Book(const Book& other);
    Book& operator=(const Book& other);

    // Destructor
    ~Book();

    // Method to display the title, year, and author of the book
    virtual ostream& display(ostream& ostr = cout) const override;

    // Operator > to compare authors
    bool operator >(const Book& other) const;
};

#endif // BOOK_H
