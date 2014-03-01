//***************************************************************************//
// Definition of the cube class which defines the full cube and directs all  //
// operations through it.                                                    //
//                                                                           //
// Filename: cube.cpp                                                        //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#include "cube.h"
#include <iostream>

Cube::Cube() 
{
  // add each unit
  Unit a( 0, 2, 0, 5, 0, 6 ); units[0][0][0] = a;
  Unit b( 0, 2, 0, 5, 0, 0 ); units[0][0][1] = b;
  Unit c( 0, 2, 0, 5, 1, 0 ); units[0][0][2] = c;
  Unit d( 0, 2, 0, 0, 0, 6 ); units[0][1][0] = d;
  Unit e( 0, 2, 0, 0, 0, 0 ); units[0][1][1] = e;
  Unit f( 0, 2, 0, 0, 1, 0 ); units[0][1][2] = f;
  Unit g( 0, 2, 3, 0, 0, 6 ); units[0][2][0] = g;
  Unit h( 0, 2, 3, 0, 0, 0 ); units[0][2][1] = h;
  Unit i( 0, 2, 3, 0, 1, 0 ); units[0][2][2] = i;
  Unit j( 0, 0, 0, 5, 0, 6 ); units[1][0][0] = j;
  Unit k( 0, 0, 0, 5, 0, 0 ); units[1][0][1] = k;
  Unit l( 0, 0, 0, 5, 1, 0 ); units[1][0][2] = l;
  Unit m( 0, 0, 0, 0, 0, 6 ); units[1][1][0] = m;
  Unit n( 0, 0, 0, 0, 0, 0 ); units[1][1][1] = n;
  Unit o( 0, 0, 0, 0, 1, 0 ); units[1][1][2] = o;
  Unit p( 0, 0, 3, 0, 0, 6 ); units[1][2][0] = p;
  Unit q( 0, 0, 3, 0, 0, 0 ); units[1][2][1] = q;
  Unit r( 0, 0, 3, 0, 1, 0 ); units[1][2][2] = r;
  Unit s( 4, 0, 0, 5, 0, 6 ); units[2][0][0] = s;
  Unit t( 4, 0, 0, 5, 0, 0 ); units[2][0][1] = t;
  Unit u( 4, 0, 0, 5, 1, 0 ); units[2][0][2] = u;
  Unit v( 4, 0, 0, 0, 0, 6 ); units[2][1][0] = v;
  Unit w( 4, 0, 0, 0, 0, 0 ); units[2][1][1] = w;
  Unit x( 4, 0, 0, 0, 1, 0 ); units[2][1][2] = x;
  Unit y( 4, 0, 3, 0, 0, 6 ); units[2][2][0] = y;
  Unit z( 4, 0, 3, 0, 0, 0 ); units[2][2][1] = z;
  Unit _( 4, 0, 3, 0, 1, 0 ); units[2][2][2] = _;
}

Cube::~Cube() { /* unused */ }

void Cube::draw()
{
	float x, y, z;

	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
		{
			for ( int k = 0; k < 3; k++ )
			{
				glPushMatrix();

				x = 2.2 * ( (float)i-1 );
				y = 2.2 * ( (float)j-1 );
				z = 2.2 * ( (float)k-1 );

				glTranslatef( x, y, z );
				units[i][j][k].draw();

  			glPopMatrix();
			}
		}
	}
}

//***************************************************************************//
// END OF FILE / cube.cpp                                                    //
//***************************************************************************//
