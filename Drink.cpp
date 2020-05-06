// Programmer: Cullin Wright	Date: 04/18/20
// File: Drink.cpp		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the implementation file for the
//          Drink class.

#include <iostream>
#include "Drink.h"
using namespace std;


Drink::Drink()
{
  // These determine the effect that the drink has on Janitor
  const float COFFEE_MIN = -0.010;
  const float COFFEE_MAX = -0.001; 
  const float WHISKEY_MIN = 0.05;
  const float WHISKEY_MAX = 0.10;
  
  // Is it coffee or whiskey? this gives that
  const short COFFEE_OR_WHISKEY = randInt(0, 1);
  
  if(COFFEE_OR_WHISKEY == 0)
  {
    m_desc = "Coffee";
    m_effect = randFloat(COFFEE_MIN, COFFEE_MAX);
  }
  else
  {
    m_desc = "Whiskey";
    m_effect = randFloat(WHISKEY_MIN, WHISKEY_MAX);
  }
}


short Drink::randInt(const short min, const short max)
{
  short result;
  // Generates random result from min to max
  result = min + (rand() % (max - min + 1));
  return result;
}


float Drink::randFloat(const float min, const float max)
{
  float result;
  // Generates random result from min to max
  result = min + (rand() / (RAND_MAX / (max - min)));
  return result;
}