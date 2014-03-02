//***************************************************************************//
// Definition of the sector class which handles sector rotations             //
//                                                                           //
// Filename: sector.cpp                                                      //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#include "sector.h"

using namespace std;

// default constructor
Sector::Sector() { /* do nothing */ }

/*
 * Sector constructor initializes with a set of indices and an orientation.
 * The position is -1 for inner sectors, 0-5 for outer sectors.
 */
Sector::Sector( int *cube_indices, int orientation, int position)
{
	this->cube_indices = new int[9];

	for ( int i = 0; i < 9; i++ )
	{
		this->cube_indices[i] = cube_indices[i];
	}

	this->orientation = orientation;
	this->position = position;
}

/*
 * Rotate function called to rotate a sector in a given direction.
 * argument: 0 = CW, 1 = CCW
 */
Unit* Sector::rotate(Unit *units, int direction)
{
  if (direction == 0)
  {
    return cw_rotate(units);
  } 
  else
  {
    return ccw_rotate(units);
  }
}

/*
 * Simulate a sector rotation in a CW direction.
 */
Unit* Sector::cw_rotate(Unit *units)
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
  
  rotate_units(units, 0);

	return units;
}

/*
 * Simulate a sector rotation in a CCW direction.
 */
Unit* Sector::ccw_rotate(Unit *units)
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
  
  units = rotate_units(units, 1);

	return units;
}

/*
 * Call the rotate function on every unit to update its status.
 */
Unit* Sector::rotate_units(Unit *units, int direction)
{
	Unit* rotated = new Unit[9];
	
  for (int i=0; i<9; i++)
  {
    units[i].rotate(this->orientation, direction);
		rotated[i] = units[i];

  }

	return units;
}

int* Sector::get_sequence()
{
	return cube_indices;
}

int Sector::get_position()
{
  return position;
}

void Sector::print_sequence()
{
	for ( int i = 0; i < 9; i++ ) { cout << this->cube_indices[i] << endl; }
}

//***************************************************************************//
// END OF FILE / sector.cpp                                                  //
//***************************************************************************//
