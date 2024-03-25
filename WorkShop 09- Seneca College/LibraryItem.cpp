#include "LibraryItem.h"
#include <cstring>

// Default constructor
LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

// Parameterized constructor
LibraryItem::LibraryItem(const char* title, int year) : m_year(year) {
    m_title = new char[strlen(title) + 1];
    strcpy(m_title, title);
}

// Copy constructor
LibraryItem::LibraryItem(const LibraryItem& other) : m_year(other.m_year) {
    m_title = new char[strlen(other.m_title) + 1];
    strcpy(m_title, other.m_title);
}

// Copy assignment operator
LibraryItem& LibraryItem::operator=(const LibraryItem& other) {
    if (this != &other) { 
        delete[] m_title;
        m_title = new char[strlen(other.m_title) + 1];
        strcpy(m_title, other.m_title);
        m_year = other.m_year;
    }
    return *this;
}

// Destructor
LibraryItem::~LibraryItem() {
    delete[] m_title;
}

// Method to display the title and year of the library item
ostream& LibraryItem::display(ostream& ostr) const {
    ostr << "Title: " << m_title << " (" << m_year << ")";
    return ostr;
}

// Overloading << operator to display LibraryItem objects
ostream& operator<<(ostream& ostr, const LibraryItem& item) {
    return item.display(ostr);
}
