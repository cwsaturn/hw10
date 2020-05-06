// Programmer: Cullin Wright	Date: 04/18/20
// File: hw10.h		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the header file for a program that
//          reads from a file and simulates many different walks a janitor takes
//          to track and catch a lunch.



// Desc: the simulation() function takes a given takes a school size, number of
//       drinks, traps, window frequency on the school, along with several 
//       varaibles by reference to report back stats and a simulation number. 
//       This function simulates a given day of a janitor attempting to chase
//       a lunch with several obstacles in the way. Prints out first day to user
// Pre: schoolSz, numDrinks, numTraps, windowFreq all must be positive. 
// Post: A day of the janitor chasing the lunch is simulated and the stats are 
//       changed accordingly. If it is tge first simulation, it every step is 
//       also printed out. 
void simulation(const short schoolSz, short numDrinks, short numTraps, 
  const short windowFreq, short & totalBruises, float & totalBloodAlc,
  short & totalWindowExits, short & totalLunchCaught, const short simulNum);


// Desc: The placeTraps() function takes a given School object and number of
//       traps to set up and spreads numTraps number of the TRAP_TOKEN 
//       characters across the school board
// Pre: numTraps must be a positive number.
// Post: numTraps number of trap characters are laid across the School object's
//       board
void placeTraps(School & s, const short numTraps);


// Desc: The placeDrinks() function takes a given School object and number of
//       drinks to set up and spreads numDrinks number of the DRINK_TOKEN 
//       characters across the school board
// Pre: numDrinks must be a positive number.
// Post: numDrinks number of drink characters are laid across the School 
//       object's board
void placeDrinks(School & s, const short numDrinks);