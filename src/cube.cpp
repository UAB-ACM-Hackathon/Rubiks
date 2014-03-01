//***************************************************************************//
// Definition of the cube class which defines the full cube and directs all  //
// operations through it.                                                    //
//                                                                           //
// Filename: cube.cpp                                                        //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#include "cube.h"

Cube::Cube() 
{
  // add each unit
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][0][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][0][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][0][2] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][1][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][1][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][1][2] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][2][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][2][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[0][2][2] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][0][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][0][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][0][2] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][1][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][1][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][1][2] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][2][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][2][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[1][2][2] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][0][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][0][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][0][2] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][1][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][1][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][1][2] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][2][0] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][2][1] = unit;
  Unit unit( 0, 0, 0, 0, 0, 0 ); units[2][2][2] = unit;
}

Cube::~Cube() { /* unused */ }

void Cube::draw()
{
	
}

//***************************************************************************//
// END OF FILE / cube.cpp                                                    //
//***************************************************************************//
