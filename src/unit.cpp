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

void Unit::rotate( int orientation, int direction )
{
	int c[6];
	for ( int i = 0; i < 6; i++ ) c[i] = faces[i];

	switch( orientation )
	{
	case 0:		// x-axis
		if ( direction == 0 )
		{
			faces[2] = c[4]; faces[3] = c[5]; faces[4] = c[3]; faces[5] = c[2];
		}
		else
		{
			faces[2] = c[5]; faces[3] = c[4]; faces[4] = c[2]; faces[5] = c[3];
		}
		break;
	case 1:		// y-axis
		if ( direction == 0 )
		{
			faces[0] = c[2]; faces[1] = c[3]; faces[2] = c[1]; faces[3] = c[0];
		}
		else
		{
			faces[0] = c[3]; faces[1] = c[2]; faces[2] = c[0]; faces[3] = c[1];
		}
		break;
	case 2:		// z-axis
		if ( direction == 0 )
		{
			faces[0] = c[5]; faces[1] = c[4]; faces[4] = c[0]; faces[5] = c[1];
		}
		else
		{
			faces[0] = c[4]; faces[1] = c[5]; faces[4] = c[1]; faces[5] = c[0];
		}
		break;
	}
}

void Unit::print_faces()
{
	for ( int i = 0; i < 6; i++ )
	{
		cout << faces[i] << " ";
	}
	cout << endl;
}

//***************************************************************************//
// END OF FILE / unit.cpp                                                    //
//***************************************************************************//
