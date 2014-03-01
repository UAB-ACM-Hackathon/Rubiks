//***************************************************************************//
// Definition of the sector class which handles sector rotations             //
//                                                                           //
// Filename: sector.cpp                                                      //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#include "sector.h"
#include <iostream>

using namespace std;

/*
 * Sector constructor initializes with a set of faces and an orientation
 */
Sector::Sector( int *cube_indices, int orientation, int position)
{
	this->cube_indices = new int[9];
	this->cube_indices = cube_indices;
	this->orientation = orientation;
	this->position = position;
}

/*
 * Rotate function called to rotate a sector in a given direction.
 * argument: 0 = CW, 1 = CCW
 */
void Sector::rotate(Unit *units, int direction)
{
  if (direction == 0)
  {
    cw_rotate(units);
  } 
  else
  {
    ccw_rotate(units);
  }
}

/*
 * Simulate a sector rotation in a CW direction.
 */
void Sector::cw_rotate(Unit *units)
{
  Unit t0 = units[0]; 
  Unit t1 = units[1];
  
  for (int i=2; i<8; i++)
  {
    Unit t2 = units[i];
    units[i] = t0;
    t0 = t1;
    t1 = t2;
  }
  
  units[0] = t0; units[1] = t1;
}

/*
 * Simulate a sector rotation in a CCW direction.
 */
void Sector::ccw_rotate(Unit *units)
{
  Unit t0 = units[7]; 
  Unit t1 = units[6];
  
  for (int i=5; i>=0; i--)
  {
    Unit t2 = units[i];
    units[i] = t0;
    t0 = t1;
    t1 = t2;
  }
  
  units[7] = t0; units[6] = t1;
}

// displays the current configuration of the faces array
void Sector::print_indices()
{
  for (int i=0; i<8; i++)
  {
    cout << this->cube_indices[i] << " ";
  }
  
  cout << endl;
}

/*
int main() 
{
  int x [9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  Sector sector(x, 1, -1);
  sector.print_indices();
}
*/

//***************************************************************************//
// END OF FILE / sector.cpp                                                  //
//***************************************************************************//
