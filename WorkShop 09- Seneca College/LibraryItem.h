#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
using namespace std;

class LibraryItem {
protected:
    char* m_title; 
    int m_year;    
    

public:
    // Default constructor
    LibraryItem();

    // Parameterized constructor
    LibraryItem(const char* title, int year);

    // Copy constructor
    LibraryItem(const LibraryItem& other);

    // Copy assignment operator
    LibraryItem& operator=(const LibraryItem& other);

    // Destructor
    virtual ~LibraryItem();

    // Method to display the title and year of the library item
    virtual ostream& display(ostream& ostr = cout) const;
};

// Overloading << operator to display LibraryItem objects
ostream& operator<<(ostream& ostr, const LibraryItem& item);

#endif // LIBRARYITEM_H
