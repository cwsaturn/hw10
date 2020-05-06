// Programmer: Cullin Wright	Date: 04/18/20
// File: Drink.h		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the header file for the
//          Drink class.

#ifndef DRINK_H
#define DRINK_H


#include <iostream>
#include <cstdlib>
#include "Drink.h"
using namespace std;


// max drinks in drink array
const short MAX_DRINKS = 20;
const char DRINK_TOKEN = 'D';



// Desc: The Drink() constructor assigns a random effect and description of the
//       drink that gives said effect. The drink will either be coffee and have
//       a negative effect or whiskey and give a positive effect. The magnitude
//       of the effect will be randomized.
// Pre: None.
// Post: A random drink object is created to either be coffee or whiskey.

// Desc: The getEffect() function returns the member variable for effect of a 
//       given drink.
// Pre: None.
// Post: m_effect is returned.

// Desc: The randInt() function takes a minimum and maximum value and returns
//       a random integer within that range.
// Pre: The min parameter must be smaller than the max parameter.
// Post: A random integer within the range given is returned.

// Desc: The randFloat() function takes a minimum and maximum value and returns
//       a random float within that range.
// Pre: The min parameter must be smaller than the max parameter.
// Post: A random float within the range given is returned.
class Drink
{
  public:
    Drink();
    
    float getEffect() {return m_effect;}
    
  private:
    // Member variables
    string m_desc;
    float m_effect;
    
    // Helper functions
    short randInt(const short min, const short max);
    float randFloat(const float min, const float max);
};



#endif