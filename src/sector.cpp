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
Sector::Sector( int *faces, int orientation)
{
	this->faces = new int[8];
	this->faces = faces;
	this->orientation = orientation;
}

/*
 * Rotate function called to rotate a sector in a given direction.
 * argument: 0 = CW, 1 = CCW
 */
void Sector::rotate( int direction ) 
{
  if (direction == 0)
  {
    cw_rotate();
  } 
  else
  {
    ccw_rotate();
  }
}

/*
 * Simulate a sector rotation in a CW direction.
 */
void Sector::cw_rotate()
{
  int t0,t1,t2;
  t0 = faces[0]; t1 = faces[1];
  
  for (int i=2; i<8; i++)
  {
    t2 = faces[i];
    faces[i] = t0;
    t0 = t1;
    t1 = t2;
  }
  
  faces[0] = t0; faces[1] = t1;
}

/*
 * Simulate a sector rotation in a CCW direction.
 */
void Sector::ccw_rotate()
{
  int t0,t1,t2;
  t0 = faces[7]; t1 = faces[6];
  
  for (int i=5; i>=0; i--)
  {
    t2 = faces[i];
    faces[i] = t0;
    t0 = t1;
    t1 = t2;
  }
  
  faces[7] = t0; faces[6] = t1;
}

// displays the current configuration of the faces array
void Sector::display_faces()
{
  for (int i=0; i<8; i++)
  {
    cout << this->faces[i] << " ";
  }
  
  cout << endl;
}

//***************************************************************************//
// END OF FILE / sector.cpp                                                  //
//***************************************************************************//
