// Programmer: Cullin Wright	Date: 04/18/20
// File: hw10.cpp		        Class: CS1570 Section 102
// Purpose: The purpose of this file is to be the main file for a program 
//          that reads from a file and simulates many different walks a janitor 
//          takes to track and catch a lunch.


#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Janitor.h"
#include "School.h"
#include "Lunch.h"
#include "Drink.h"
#include "hw10.h"
using namespace std;

int main()
{
  // Seed Random number generator
  srand(time(NULL));
  
  // Constant and var declarations
  const string INPUT_FILE = "config.dat";
  
  ifstream fin(INPUT_FILE);
  
  // All the variables to get from said file
  short totalDays;
  short schoolSize;
  short totalDrinks;
  short totalTraps;
  short windowFreq;
  
  // referenced variables to report results over the total num days
  short totalBruises = 0;
  float totalBloodAlc = 0;
  short totalLunchesCaught = 0;
  short totalWindowExits = 0;
  
  float avgBloodAlc;
  float avgNumBruises;
  float percentLunchesCaught;
  float percentWindowsFallen;
  
  // Grab values from file and close
  
  fin >> totalDays;
  fin >> schoolSize;
  fin >> totalDrinks;
  fin >> totalTraps;
  fin >> windowFreq;
  fin.close();
  
  // main simulation loop
  
  for(short i = 0; i < totalDays; i++)
  {
    simulation(schoolSize, totalDrinks, totalTraps, windowFreq, 
      totalBruises, totalBloodAlc, totalWindowExits, totalLunchesCaught, i);
  }
  
  // Set outputting variables appropriately
  avgBloodAlc = totalBloodAlc / totalDays;
  avgNumBruises = static_cast<float>(totalBruises) / totalDays;
  percentLunchesCaught = 
    (static_cast<float>(totalLunchesCaught) / totalDays) * 100;
  percentWindowsFallen = 
    (static_cast<float>(totalWindowExits) / totalDays) * 100;
  
  cout << endl << endl << endl;
  cout << "Here are your Statistics for your " << totalDays;
  cout << " simulated days on the job, Mr. Price:";
  cout << endl;
  cout << "-------------------------------------------------------------------";
  cout << "---------" << endl;
  cout << "Percent of the time Catching Lunch: " << percentLunchesCaught << "%";
  cout << endl;
  cout << "Percent of the time Falling out Window: " << percentWindowsFallen;
  cout << "%" << endl;
  cout << "Average number of Bruises gotten during the Lunch Schenanigans: ";
  cout << avgNumBruises << " bruises" << endl;
  cout << "Average Blood Alcohol level at the end of the day: " << avgBloodAlc;
  cout << " BAC" << endl;
    
  return 0;
}



