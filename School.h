// Programmer: Cullin Wright	Date: 04/18/20
// File: School.h		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the header file for the
//          School class.

#ifndef SCHOOL_H
#define SCHOOL_H


#include <iostream>
using namespace std;


// Global Vars -----------------------------------------------------------------
const short MAX_SIZE = 25;
const short WINDOW_PLACEMENT = 4;
const char WALL = '@';
const char WINDOW = '+';
const char EMPTY = ' ';



// Class definition ------------------------------------------------------------


// Desc: The School() constructor takes the desired size of the school object
//       and creates a school object with a "map size" at that size.
// Pre: The schoolSize must be greater than 0 and at or less than MAX_SIZE.
// Post: The school object of size schoolSize is created.

// Desc: The overloaded operator << () function takes an ostream object and 
//       a School object, and outputs the school object to the ostream object.
// Pre: None.
// Post: The school object is outputted to the ostream object and the user.

// Desc: The getSize() function returns the size of the calling School object.
// Pre: None.
// Post: The size of the school calling object is returned.

// Desc: The getGridItem() function takes the row and col parameters and returns
//       the character which is in those coordinates on the School's m_map.
// Pre: The parameters row and col must be between 0 and (m_size - 1).
// Post: The character at the spot of the given parameters is returned.

// Desc: The setGridToToken() function takes a token along with a row and col
//       parameter and sets the value of m_map at the position row, col to that
//       token character.
// Pre: The parameters row and col must be between 0 and (m_size - 1).
// Post: The character at position row, col on m_map is set to the token param.
class School
{
  public:
    School(
      const short schoolSize = MAX_SIZE, 
      const short windowFreq = WINDOW_PLACEMENT
    );
    friend ostream& operator << (ostream & o, const School & s);
    
    short getSize() const;
    char getGridItem(const short row, const short col) const;
    void setGridToToken(const char token, const short row, const short col);

  private:
    // Private member functions (helpers):
    void clear();
    void build(const short windowPlacement);
    
    // Private member variables:
    char m_map[MAX_SIZE][MAX_SIZE];
    short m_size;
};



#endif
