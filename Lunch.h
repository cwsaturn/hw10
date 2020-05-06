// Programmer: Cullin Wright	Date: 04/18/20
// File: Lunch.h		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the header file for the
//          Lunch class.

#ifndef LUNCH_H
#define LUNCH_H


#include <iostream>
#include "School.h"
using namespace std;


const char LUNCH_TOKEN = 'L';
const char TRAP_TOKEN = 'T';


// Class definition ------------------------------------------------------------


// Desc: The Lunch() constructor takes a token character, position of the
//       Lunch, and if it is trapped or not, and creates a Lunch object
//       with the appropriate member variables.
// Pre: None.
// Post: A Lunch object is created with the appropriate member variables.

// Desc: The place_me() function takes a school by reference and places the 
//       Lunch token into a random empty position of the Shcool object's member
//       array in addition to changing the Lunch's member variables which 
//       describe its location.
// Pre: None.
// Post: The Lunch's member variables m_Xcoord and m_Ycoord are set to a random
//       valid coordinate of the School object's grid, and the said grid has
//       the Lunch's token in that position.

// Desc: The rand_walk() function takes a school by reference and picks a random
//       valid direction to move in whether it is a trap or an empty space,
//       otherwise it won't move.
// Pre: The Lunch object must have a valid position, i.e. its coordinates must
//      be inside the School grid.
// Post: The Lunch's coordinates are changed to the move and the School 
//       object's grid reflects this change, or if it doesn't move, nothing is
//       changed.

// Desc: The getIsTrapped(), getXcoord(), and getYcoord() functions return their
//       respective member variables.
// Pre: None.
// Post: The appropriate member variable is returned.
class Lunch
{
  public:
    Lunch(
      const char token = LUNCH_TOKEN, 
      short Xcoord = -1, 
      short Ycoord = -1, 
      bool trapped = false
    );
      
    void place_me(School & s);
    void rand_walk(School & s);
    
    bool getIsTrapped() const {return m_isTrapped;}
    short getXcoord() const {return m_Xcoord;}
    short getYcoord() const {return m_Ycoord;}
  
  private:
    char m_token;
    short m_Xcoord;
    short m_Ycoord;
    bool m_isTrapped;
};



#endif
