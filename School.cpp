// Programmer: Cullin Wright	Date: 04/18/20
// File: School.cpp		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the implementation file for the
//          School class.

#include <iostream>
#include "School.h"
using namespace std;


// Public member functions ----------------------------------------------------
School::School(const short schoolSize, const short windowFreq)
{
  m_size = schoolSize;
  clear();
  build(windowFreq);
}


ostream& operator << (ostream & o, const School & s)
{
  // Loops over each row in the matrix
  for(short i = 0; i < s.m_size; i++)
  {
    // Loops over each col in the matrix
    for(short j = 0; j < s.m_size; j++)
    {
      o << s.m_map[i][j];
    }
    o << endl;
  }
  
  return o;
}


short School::getSize() const
{
  return m_size;
}


char School::getGridItem(const short row, const short col) const
{
  return m_map[row][col];
}


void School::setGridToToken(const char token, const short row, const short col)
{
  m_map[row][col] = token;
  return;
}



// Private member functions ----------------------------------------------------
void School::clear()
{
  // Loops over each row in the matrix
  for(short i = 0; i < m_size; i++)
  {
    // Loops over each col in the matrix
    for(short j = 0; j < m_size; j++)
    {
      m_map[i][j] = EMPTY;
    }
  }
  return;
}


void School::build(const short windowPlacement)
{
  // Loops over each row in the matrix
  for(short i = 0; i < m_size; i++)
  {
    // Loops over each col in the matrix
    for(short j = 0; j < m_size; j++)
    {
      // Checks if you are on the edge of the school
      if(i == 0 || i == (m_size - 1) || j == 0 || j == (m_size - 1))
      {
        
        // Checks if you need a wall or a window
        if(((i % windowPlacement == 0) && (j == 0 || j == m_size - 1)) || 
          ((j % windowPlacement == 0) && (i == 0 || i == m_size - 1)))
        {
          
          // Checks if it is a corner
          if((i == 0 || i == (m_size - 1)) && (j == 0 || j == (m_size - 1)))
          {
            m_map[i][j] = WALL;
          }
          
          else
          {
            m_map[i][j] = WINDOW;
          }
        }
        
        else
        {
          m_map[i][j] = WALL;
        }
        
      }
      else
      {
        m_map[i][j] = EMPTY;
      }
    }
  }
  return;
}
