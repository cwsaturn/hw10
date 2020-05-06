// Programmer: Cullin Wright	Date: 04/18/20
// File: Lunch.cpp		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the implementation file for the
//          Lunch class. 

#include <iostream>
#include <cstdlib>
#include "Lunch.h"
using namespace std;


Lunch::Lunch(const char token, short Xcoord, short Ycoord, bool trapped)
{
  m_token = token;
  m_Xcoord = Xcoord;
  m_Ycoord = Ycoord;
  m_isTrapped = trapped;
}


void Lunch::place_me(School & s)
{
  // makes sure it isn't on the left or top wall
  const short MIN_RAND = 1;
  // makes sure it isn't on the right or bottom wall
  const short MAX_RAND = s.getSize() - 2;
  
  short randX;
  short randY;
  bool lunchPlaced = false;
  
  // Keeps going until it finds an empty space to put it in
  while(!lunchPlaced)
  {
    randX = MIN_RAND + (rand() % ((MAX_RAND - MIN_RAND) + 1));
    randY = MIN_RAND + (rand() % ((MAX_RAND - MIN_RAND) + 1));
    
    if(s.getGridItem(randX, randY) == EMPTY)
    {
      m_Xcoord = randX;
      m_Ycoord = randY;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
      lunchPlaced = true;
    }
  } 
  return;
}


void Lunch::rand_walk(School & s)
{
  const short MIN_RAND = 0;
  const short MAX_RAND = 3;
  const short DIRECTIONALITY = MIN_RAND + (rand() % (MAX_RAND - MIN_RAND + 1));
  
  char fieldOfView;
  
  // Doesnt loop, since if it hits a wall or something, It can't move that round
    
  if(DIRECTIONALITY == 0)  // North --------------------------------------------
  {
    fieldOfView = s.getGridItem(m_Xcoord, m_Ycoord - 1);
    if(fieldOfView == TRAP_TOKEN)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord--;
      m_isTrapped = true;
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
    if(fieldOfView == TRAP_TOKEN)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord++;
      m_isTrapped = true;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == EMPTY)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Ycoord++;
      s.setGridToToken(m_token, m_Xcoord, m_Ycoord);
    }
  }
  
    
  
  if(DIRECTIONALITY == 2)  // West ---------------------------------------------
  {
    fieldOfView = s.getGridItem(m_Xcoord - 1, m_Ycoord);
    if(fieldOfView == TRAP_TOKEN)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord--;
      m_isTrapped = true;
      s.setGridToToken(LUNCH_TOKEN, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == EMPTY)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord--;
      s.setGridToToken(LUNCH_TOKEN, m_Xcoord, m_Ycoord);
    }
  }
    
  
  else if(DIRECTIONALITY == 3)  // East ----------------------------------------
  {
    fieldOfView = s.getGridItem(m_Xcoord + 1, m_Ycoord);
    if(fieldOfView == TRAP_TOKEN)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord++;
      m_isTrapped = true;
      s.setGridToToken(LUNCH_TOKEN, m_Xcoord, m_Ycoord);
    }
    else if(fieldOfView == EMPTY)
    {
      s.setGridToToken(EMPTY, m_Xcoord, m_Ycoord);
      m_Xcoord++;
      s.setGridToToken(LUNCH_TOKEN, m_Xcoord, m_Ycoord);
    }
  }
  return;
}

