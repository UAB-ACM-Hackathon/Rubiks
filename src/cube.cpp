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

	// create sequences
	int seq1[9] = { 26, 25, 24, 21, 18, 19, 20, 23, 22 };
	int seq2[9] = { 17, 16, 15, 12,  9, 10, 11, 14, 13 };
	int seq3[9] = {  8,  7,  6,  3,  0,  1,  2,  5,  4 };
	int seq4[9] = {  8, 17, 26, 23, 20, 11,  2,  5, 14 };
	int seq5[9] = {  7, 16, 25, 22, 19, 10,  1,  4, 13 };
	int seq6[9] = {  6, 15, 24, 21, 18,  9,  0,  3, 12 };
	int seq7[9] = {  6, 15, 24, 25, 26, 17,  8,  7, 16 };
	int seq8[9] = {  3, 12, 21, 22, 23, 14,  5,  4, 13 };
	int seq9[9] = {  0,  9, 18, 19, 20, 11,  2,  1, 10 };

	Sector s1( seq1, 0,  0 ); sectors[0] = s1;
	Sector s2( seq2, 0, -1 ); sectors[1] = s2;
	Sector s3( seq3, 0,  1 ); sectors[2] = s3;
	Sector s4( seq4, 1,  4 ); sectors[3] = s4;
	Sector s5( seq5, 1, -1 ); sectors[4] = s5;
	Sector s6( seq6, 1,  5 ); sectors[5] = s6;
	Sector s7( seq7, 2,  2 ); sectors[6] = s7;
	Sector s8( seq8, 2, -1 ); sectors[7] = s8;
	Sector s9( seq9, 2,  3 ); sectors[8] = s9;

	anim_lock = false;
	spread = 1.0;
}

Cube::~Cube() { /* unused */ }

void Cube::draw()
{
	if ( boom )
	{
		explode_draw();
		return;
	}

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

				if ( anim_lock && in_sequence( i, j, k, anim_seq ) )
				{
					if ( anim_axis == 0 ) glRotatef( rot, 1.0, 0.0, 0.0 );
					if ( anim_axis == 1 ) glRotatef( rot, 0.0, 0.0, 1.0 );
					if ( anim_axis == 2 ) glRotatef( rot, 0.0, 1.0, 0.0 );
				}

				glTranslatef( x, y, z );

				units[i][j][k].draw();

  			glPopMatrix();
			}
		}
	}
	
	if ( anim_lock )
	{
		int inc = ( anim_fast ? 15 : 5 );
		if ( anim_dir == 0 ) rot -= inc; else rot += inc;
		if ( rot >= 90 || rot <= -90 ) end_animation();
	}
}

bool Cube::in_sequence( int i, int j, int k, int* seq )
{
	for ( int n = 0; n < 9; n++ )
	{
		int* u = index( seq[n] );
		if ( u[0] == i && u[1] == j && u[2] == k ) return true;
	}

	return false;
}

int* Cube::index( int ptr )
{
	int level, row;

	level = ptr / 9;  ptr = ptr % 9;
	row   = ptr / 3;  ptr = ptr % 3;

	int* index = new int[3];
	index[0] = level; index[1] = row, index[2] = ptr;

	return index;
}

void Cube::rotate_sector( int i, int direction )
{
	rotate_sector( i, direction, false );
}

void Cube::rotate_sector( int i, int direction, bool fast )
{
	anim_lock = true;
	sector = sectors[i-1];
	anim_axis = sector.get_axis();
	anim_dir = direction;
	anim_fast = fast;
	
	int* copy = sector.get_sequence();
	anim_seq = new int[9];

	for ( int n = 0; n < 9; n++ )
	{
		anim_seq[n] = copy[n];
	}

	rot = 0.0;
}

void Cube::end_animation()
{
	Unit to_rotate[9];
	for ( int i = 0; i < 9; i++ )
	{
		int* u = index( anim_seq[i] );
		to_rotate[i] = units[u[0]][u[1]][u[2]];
	}	

	Unit* new_units = sector.rotate( to_rotate, anim_dir );

	for ( int i = 0; i < 9; i++ )
	{
		int* u = index( anim_seq[i] );
		units[u[0]][u[1]][u[2]] = new_units[i];
	}

	anim_lock = false;
}

bool Cube::is_animating()
{
	return anim_lock;
}

bool Cube::win_check()
{
	for ( int i=0; i<9; i++)
	{
	  int* sequence = sectors[i].get_sequence();
	  int position = sectors[i].get_position();
	  int color;
	  
	  if (position != -1)
	  {
	    for (int j=0; j<9; j++)
	    {
		    int* u = index( sequence[j] );
		    int* faces = units[u[0]][u[1]][u[2]].get_faces();
		    if (j == 0)
		      color = faces[position];
		    
		    if (faces[position] != color)
		      return false;
	    }
	  }
	}
	
	return true;
}

void Cube::explode()
{
	boom = true;
}

void Cube::explode_draw()
{
	float x, y, z;

	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
		{
			for ( int k = 0; k < 3; k++ )
			{
				if ( i == 1 && j == 1 && k == 1 ) continue;

				glPushMatrix();

				x = 2.2 * ( (float)i-1 );
				y = 2.2 * ( (float)j-1 );
				z = 2.2 * ( (float)k-1 );

				glTranslatef( x * spread, y * spread, z * spread );

				units[i][j][k].draw();

  			glPopMatrix();
			}
		}
	}

	if ( spread < 20 ) spread *= 1.15;
}

//***************************************************************************//
// END OF FILE / cube.cpp                                                    //
//***************************************************************************//
