// Programmer: Cullin Wright	Date: 04/18/20
// File: hw10functions.cpp		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the functions file for a program 
//          that reads from a file and simulates many different walks a janitor 
//          takes to track and catch a lunch.


#include <iostream>
#include <unistd.h>
#include "Janitor.h"
#include "School.h"
#include "Lunch.h"
#include "Drink.h"
#include "hw10.h"
using namespace std;


void simulation(const short schoolSz, short numDrinks, short numTraps,
  const short windowFreq, short & totalBruises, float & totalBloodAlc,
  short & totalWindowExits, short & totalLunchCaught, const short simulNum)
{
  const short PRNT_OUT_ON_SIM_NUM = 0;
  
  School board(schoolSz, windowFreq);
  Janitor price('J', "Mr.Price");
  Lunch floorMeal;
  Drink drinkArr[MAX_DRINKS];
  
  // Places lunch and janitor in school array
  price.place_me(board);
  floorMeal.place_me(board);
  
  // Places drinks and traps in the school array
  placeDrinks(board, numDrinks);
  placeTraps(board, numTraps);
  
  // Main loop for movement of Janitor and Lunch
  do
  {
    // --------------- lunch and janitor move ---------------------------------
    // Checks if lunch is trapped (can't move if it's trapped)
    if(!floorMeal.getIsTrapped())
    {
      floorMeal.rand_walk(board);
    }
    
    // oh no price has been drinking too much! (checks if janitor is drunk)
    if(!price.getIsSober())
    {
      price.rand_walk(board, drinkArr, numDrinks);
    }
    else
    {
      price.intelligent_walk(board, drinkArr, numDrinks, floorMeal);
    }
    
    // Only prints out if the simulation is number PRNT_OUT_ON_SIM_NUM(set to 0)
    if(simulNum == PRNT_OUT_ON_SIM_NUM)
    {
      cout << board << endl;
      usleep(200000);
    }
    
  }  while((!price.getisDead()) && (!price.getLunchCaught()) && 
      (!price.getOutWindow()));
  
  // change some referenced vars from end of simulation data
  totalBruises += price.getBruises();
  totalBloodAlc += price.getBloodAlc();
  if(price.getLunchCaught())
  {
    totalLunchCaught++;
  }
  else if(price.getOutWindow())
  {
    totalWindowExits++;
  }
  
  return;
}


void placeTraps(School & s, const short numTraps)
{
  // makes sure it isn't on the left or top wall
  const short MIN_RAND = 1;
  // makes sure it isn't on the right or bottom wall
  const short MAX_RAND = s.getSize() - 2;
  
  short randX;
  short randY;
  bool trapPlaced = false;
  
  
  // places numTraps number of traps
  for(short i = 0; i < numTraps; i++)
  {
    trapPlaced = false;   // reinitializes as false for each trap
    // Keeps going until it finds an empty space to put it in
    while(!trapPlaced)
    {
      randX = MIN_RAND + (rand() % ((MAX_RAND - MIN_RAND) + 1));
      randY = MIN_RAND + (rand() % ((MAX_RAND - MIN_RAND) + 1));
    
      if(s.getGridItem(randX, randY) == EMPTY)
      {
        s.setGridToToken(TRAP_TOKEN, randX, randY);
        trapPlaced = true;
      }
    }
  }
  return;
}


void placeDrinks(School & s, const short numDrinks)
{
  // makes sure it isn't on the left or top wall
  const short MIN_RAND = 1;
  // makes sure it isn't on the right or bottom wall
  const short MAX_RAND = s.getSize() - 2;
  
  short randX;
  short randY;
  bool drinkPlaced = false;
  
  
  // places numDrinks number of drinks
  for(short i = 0; i < numDrinks; i++)
  {
    drinkPlaced = false;   // reinitializes as false for each drink
    // Keeps going until it finds an empty space to put it in
    while(!drinkPlaced)
    {
      randX = MIN_RAND + (rand() % ((MAX_RAND - MIN_RAND) + 1));
      randY = MIN_RAND + (rand() % ((MAX_RAND - MIN_RAND) + 1));
    
      if(s.getGridItem(randX, randY) == EMPTY)
      {
        s.setGridToToken(DRINK_TOKEN, randX, randY);
        drinkPlaced = true;
      }
    }
  }
  return;
}






