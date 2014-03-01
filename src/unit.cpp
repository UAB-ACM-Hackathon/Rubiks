//***************************************************************************//
// Definition of the unit class which translates faces and tracks them.      //
//                                                                           //
// Filename: unit.cpp                                                        //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#include "unit.h"

Unit::Unit() { }

Unit::Unit( int R, int L, int U, int D, int F, int B )
{
	Mesh t( "meshes/block.off" );
	mesh = t;

	faces[0] = R; // right
	faces[1] = L; // left
	faces[2] = U; // up
	faces[3] = D; // down
	faces[4] = F; // front
	faces[5] = B; // back
}

Unit::~Unit() { /* unused */ }

void Unit::draw()
{
	for ( int i = 0; i < 6; i++ )
	{
		glPushMatrix();

		glColor3fv( colors[faces[i]] );
		mesh.draw( i );

		glPopMatrix();
	}
}

//***************************************************************************//
// END OF FILE / unit.cpp                                                    //
//***************************************************************************//
