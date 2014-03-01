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
	Unit a( 0, 0, 0, 0, 0, 0 ); units[0][0][0] = a;
	Unit b( 0, 0, 0, 0, 0, 1 ); units[0][0][1] = b;
}

Cube::~Cube() { /* unused */ }

void Cube::draw()
{
	
}

//***************************************************************************//
// END OF FILE / cube.cpp                                                    //
//***************************************************************************//
