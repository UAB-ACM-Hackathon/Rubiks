//***************************************************************************//
// Definition of the unit class which translates faces and tracks them.      //
//                                                                           //
// Filename: unit.cpp                                                        //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#include "unit.h"

Unit::Unit() { }

Unit::Unit( int a, int b, int c, int d, int e, int f )
{
	Mesh t( "meshes/block.off" );
	mesh = t;

	faces[0] = a;
	faces[1] = b;
	faces[2] = c;
	faces[3] = d;
	faces[4] = e;
	faces[5] = f;
}

Unit::~Unit() { /* unused */ }

void Unit::draw()
{
	mesh.draw();
}

//***************************************************************************//
// END OF FILE / unit.cpp                                                    //
//***************************************************************************//
