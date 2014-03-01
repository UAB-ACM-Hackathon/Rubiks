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
  units[0][0][0] = new Unit( 0, 0, 0, 0, 0, 0 );
}

Cube::~Cube() { /* unused */ }

void Cube::draw()
{
	
}

//***************************************************************************//
// END OF FILE / cube.cpp                                                    //
//***************************************************************************//
