// Programmer: Cullin Wright	Date: 04/18/20
// File: Janitor.cpp		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the implementation file for the
//          Janitor class.

#include <iostream>
#include <cstdlib>
#include "Janitor.h"
#include "Lunch.h"
#include "Drink.h"
using namespace std;


Janitor::Janitor(const char token, const string name, float bloodAlc, 
  short numBruises, bool isDead, bool isSober, bool lunchIsCaught, 
  bool outWindow, short xCoord, short yCoord)
{
  m_token = token;
  m_name = name;
  m_bloodAlcohol = bloodAlc;
  m_numBruises = numBruises;
  m_isDead = isDead;
  m_isSober = isSober;
  m_lunchCaught = lunchIsCaught;
  m_outWindow = outWindow;
  m_Xcoord = xCoord;
  m_Ycoord = yCoord;
}


void Janitor::place_me(School & s)
{
  const short SCHOOL_SZ = s.getSize();
  // Places janitor in "the middle of things"
  m_Xcoord = SCHOOL_SZ / 2;
  m_Ycoord = SCHOOL_SZ / 2;
  s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
  return;
}


void Janitor::rand_walk(School & s, Drink drinkArr[], short numDrinks)
{
  const short MIN_RAND = 0;
  const short MAX_RAND = 3;
  const short TRAP_BRUISE_NUM = 5;
  const short DIRECTIONALITY = MIN_RAND + (rand() % (MAX_RAND - MIN_RAND + 1));
  
  // Doesnt loop, since if it hits a wall or something, He can't move that round
  char fieldOfView;
  
  
  if(DIRECTIONALITY == 0)  // North --------------------------------------------
  {
    fieldOfView = s.getGridItem(m_Xcoord, m_Ycoord - 1);
    if(fieldOfView == TRAP_TOKEN)     // disarms a trap
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord--;
      m_numBruises += TRAP_BRUISE_NUM;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == WINDOW)    // falls out window
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord--;
      m_outWindow = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == WALL)    // hits a wall, doesnt move
    {
      m_numBruises++;
    }
    else if(fieldOfView == LUNCH_TOKEN)    // lunch is caught!
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord--;
      m_lunchCaught = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == DRINK_TOKEN)    // take a drink!
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord--;
      m_bloodAlcohol += (drinkArr[numDrinks - 1]).getEffect();  // neg = coffee
      numDrinks--;    // decrement the number of drinks         // pos = whiskey
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == EMPTY)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord--;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
  }
    

  
  else if(DIRECTIONALITY == 1)  // South ---------------------------------------
  {
    fieldOfView = s.getGridItem(m_Xcoord, m_Ycoord + 1);
    if(fieldOfView == TRAP_TOKEN)     // disarms a trap
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord++;
      m_numBruises += TRAP_BRUISE_NUM;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == WINDOW)    // falls out window
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord++;
      m_outWindow = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == WALL)    // hits a wall, doesnt move
    {
      m_numBruises++;
    }
    else if(fieldOfView == LUNCH_TOKEN)    // lunch is caught!
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord++;
      m_lunchCaught = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == DRINK_TOKEN)    // take a drink!
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord++;
      m_bloodAlcohol += (drinkArr[numDrinks - 1]).getEffect();  // neg = coffee
      numDrinks--;    // decrement the number of drinks         // pos = whiskey
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == EMPTY)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord++;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
  }
  
  
  
  else if(DIRECTIONALITY == 2)  // West ----------------------------------------
  {
    fieldOfView = s.getGridItem(m_Xcoord - 1, m_Ycoord);
    if(fieldOfView == TRAP_TOKEN)     // disarms a trap
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord--;
      m_numBruises += TRAP_BRUISE_NUM;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == WINDOW)    // falls out window
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord--;
      m_outWindow = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == WALL)    // hits a wall, doesnt move
    {
      m_numBruises++;
    }
    else if(fieldOfView == LUNCH_TOKEN)    // lunch is caught!
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord--;
      m_lunchCaught = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == DRINK_TOKEN)    // take a drink!
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord--;
      m_bloodAlcohol += (drinkArr[numDrinks - 1]).getEffect();  // neg = coffee
      numDrinks--;    // decrement the number of drinks         // pos = whiskey
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == EMPTY)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord--;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
  }
    

  
  else if(DIRECTIONALITY == 3)  // East ----------------------------------------
  {
    fieldOfView = s.getGridItem(m_Xcoord + 1, m_Ycoord);
    if(fieldOfView == TRAP_TOKEN)     // disarms a trap
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord--;
      m_numBruises += TRAP_BRUISE_NUM;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == WINDOW)    // falls out window
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord++;
      m_outWindow = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == WALL)    // hits a wall, doesnt move
    {
      m_numBruises++;
    }
    else if(fieldOfView == LUNCH_TOKEN)    // lunch is caught!
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord++;
      m_lunchCaught = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == DRINK_TOKEN)    // take a drink!
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord++;
      m_bloodAlcohol += (drinkArr[numDrinks - 1]).getEffect();  // neg = coffee
      numDrinks--;    // decrement the number of drinks         // pos = whiskey
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == EMPTY)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord++;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
  }
    
  // Checks at end if dead from alcohol poisoning or drunk or sober
  if(m_bloodAlcohol >= DEAD_LVL)
  {
    m_isDead = true;
  }
  else if(m_bloodAlcohol >= DRUNK_LVL)
  {
    m_isSober = false;
  }
  else if(m_bloodAlcohol < DRUNK_LVL)
  {
    m_isSober = true;
  }
  return;
}



void Janitor::intelligent_walk(School & s, Drink drinkArr[], short numDrinks, 
  const Lunch burgerToGo)
{
  const short TRAP_BRUISE_NUM = 5;
  
  // the variables that determine the Janitor's movement (only 4 directions)
  short deltaX;
  short deltaY;
  
  // current coords of the lunch
  short lunchX = burgerToGo.getXcoord();
  short lunchY = burgerToGo.getYcoord();
  
  char fieldOfView;
  
  // Determines where Janitor goes, based on where lunch is: Sets movement 
  // vars appropriately
  
  // if both lunchX=m_Xcoord and lunchY=m_Ycoord, you caught lunch.
  if(lunchX < m_Xcoord)
  {
    deltaX = -1;
    deltaY = 0;
  }
  else if(lunchX > m_Xcoord)
  {
    deltaX = 1;
    deltaY = 0;
  }
  else if(lunchY < m_Ycoord)
  {
    deltaX = 0;
    deltaY = -1;
  }
  else if(lunchY > m_Ycoord)
  {
    deltaX = 0;
    deltaY = 1;
  }
  
  
  
  // Where (the char) the janitor is walking directly at:
  fieldOfView = s.getGridItem(m_Xcoord + deltaX, m_Ycoord + deltaY);
  
  if(fieldOfView == TRAP_TOKEN)     // disarms a trap
  {
    s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
    m_Xcoord += deltaX;
    m_Ycoord += deltaY;
    m_numBruises += TRAP_BRUISE_NUM;
    s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
  }
  else if(fieldOfView == WINDOW)    // falls out window
  {
    s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
    m_Xcoord += deltaX;
    m_Ycoord += deltaY;
    m_outWindow = true;
    s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
  }
  else if(fieldOfView == WALL)    // hits a wall, doesnt move
  {
    m_numBruises++;
  }
  else if(fieldOfView == LUNCH_TOKEN)    // lunch is caught!
  {
    s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
    m_Xcoord += deltaX;
    m_Ycoord += deltaY;
    m_lunchCaught = true;
    s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
  }
  else if(fieldOfView == DRINK_TOKEN)    // take a drink!
  {
    s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
    m_Xcoord += deltaX;
    m_Ycoord += deltaY;
    m_bloodAlcohol += (drinkArr[numDrinks - 1]).getEffect();  // neg = coffee
    numDrinks--;    // decrement the number of drinks         // pos = whiskey
    s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
  }
  else if(fieldOfView == EMPTY)
  {
    s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
    m_Xcoord += deltaX;
    m_Ycoord += deltaY;
    s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
  }
  
  
  
  // Checks at end if dead from alcohol poisoning or drunk or sober
  if(m_bloodAlcohol >= DEAD_LVL)
  {
    m_isDead = true;
  }
  else if(m_bloodAlcohol >= DRUNK_LVL)
  {
    m_isSober = false;
  }
  else if(m_bloodAlcohol < DRUNK_LVL)
  {
    m_isSober = true;
  }
  
  
  
  return;
}



ostream& operator << (ostream & o, const Janitor & j)
{
  o << "Janitor " << j.m_name << ", otherwise known as " << j.m_token << 
       " has the following conditions:" << endl;
  o << j.m_numBruises << " Bruises" << endl;
  o << j.m_bloodAlcohol << " Blood Alcohol" << endl;
  o << "They are" << (j.m_isDead? " dead.": " alive and kicking!") << endl;
  o << "They are also" << (j.m_isSober? " sober": " drunk as a goose") << endl;
  o << "Location: (" << j.m_Xcoord << ", " << j.m_Ycoord << ")" << endl;
  
  return o;
}


