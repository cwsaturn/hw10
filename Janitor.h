// Programmer: Cullin Wright	Date: 04/18/20
// File: Janitor.h		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the header file for the
//          Janitor class.

#ifndef JANITOR_H
#define JANITOR_H


#include <iostream>
#include "School.h"
#include "Lunch.h"
#include "Drink.h"
using namespace std;


const float DRUNK_LVL = 0.08;
const float DEAD_LVL = 0.25;


// Class definition ------------------------------------------------------------


// Desc: The Janitor() constructor creates a Janitor object with appropriate
//       member variables set to their respective given parameters or default
//       values of the parameters.
// Pre: If given nondefault values, the parameters bloodAlc and numBruises must
//      be set to positive values.
// Post: The Janitor with given parameters as member variables is created.

// Desc: The place_me() function takes a school by reference and places the 
//       Janitor token into the center of the Shcool object's member array in
//       addition to changing the Janitor's member variables which describe its
//       location.
// Pre: None.
// Post: The Janitor's member variables m_Xcoord and m_Ycoord are set to the 
//       center of the School object's grid, and the said grid has the Janitor's
//       token in the center of it.

// Desc: The rand_walk() function takes a school by reference and picks a random
//       valid direction to move in (AKA not a wall), and changes the janitor'said
//       position member variables to reflect the change, along with changing any
//       effects of tokens that the janitor happens upon.
// Pre: The Janitor object must have a valid position, i.e. its coordinates must
//      be inside the School grid and numDrinks must de an accurate size 
//      description of the drinkArr[] array.
// Post: The Janitor's coordinates are changed to the move and the School 
//       object's grid reflects this change. Any effects on the janitor are done

// Desc: The intelligent_walk() function takes a school by reference and locks 
//       onto a Lunch object's location and changes the janitor's said
//       position member variables to reflect the move, along with changing any
//       effects of tokens that the janitor happens upon.
// Pre: The Janitor object must have a valid position, i.e. its coordinates must
//      be inside the School grid and numDrinks must de an accurate size 
//      description of the drinkArr[] array.
// Post: The Janitor's coordinates are changed to the move and the School 
//       object's grid reflects this change. Any effects on the janitor are done

// Desc: The overloaded operator << () function takes an ostream object and
//       a Janitor object and outputs all states of the member variables in a
//       readable fashion.
// Pre: None.
// Post: The Janitor object is outputted to the ostream object and the user.

// Desc: The getBloodAlc(), getBruises(), getisDead(), getLunchCaught(), 
//       getOutWindow() and getIsSober() functions return the appropritate 
//       member variables.
// Pre: None.
// Post: The appropriate member variables are returned.

// Desc: The addBloodAlc() and addBruises() functions add their parameters to
//       their respective member variables.
// Pre: numObtained must be a positive number greater than 0 for addBruises().
// Post: The respective member variables are added to by the functions' params.
class Janitor
{
  public:
    Janitor(
      const char token = 'J', 
      const string name = "name", 
      float bloodAlc = 0.05,
      short numBruises = 0, 
      bool isDead = false, 
      bool isSober = true,
      bool lunchIsCaught = false,
      bool outWindow = false,
      short xCoord = -1, 
      short yCoord = -1
    );
      
    void place_me(School & s);
    void rand_walk(School & s, Drink drinkArr[], short numDrinks);
    void intelligent_walk(School & s, Drink drinkArr[], short numDrinks, 
      const Lunch burgerToGo);
    
    friend ostream& operator << (ostream & o, const Janitor & j);
    
    float getBloodAlc() const {return m_bloodAlcohol;}
    short getBruises() const {return m_numBruises;}
    bool getisDead() const {return m_isDead;}
    bool getIsSober() const {return m_isSober;}
    bool getLunchCaught() const {return m_lunchCaught;}
    bool getOutWindow() const {return m_outWindow;}
        
    void addBloodAlc(const float drinkEffect) {m_bloodAlcohol += drinkEffect;}
    void addBruises(const short numObtained) {m_numBruises += numObtained;}
    
  private:
    char m_token;
    string m_name;
    float m_bloodAlcohol;
    short m_numBruises;
    bool m_isDead;
    bool m_isSober;   // if false, drunk
    bool m_lunchCaught;
    bool m_outWindow;
    short m_Xcoord;
    short m_Ycoord;
};



#endif
