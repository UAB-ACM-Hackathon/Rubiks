//***************************************************************************//
// Linker definition file for the unit class.                                //
//                                                                           //
// Filename: unit.h                                                          //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#ifndef L_UNIT_H
#define L_UNIT_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#endif

#include "mesh.h"
#include "globals.h"
#include <iostream>

class Unit
{
 private:
 	int faces[6];
	Mesh mesh;
 	
 public:
	Unit();
 	Unit( int, int, int, int, int, int );
 	~Unit();
	void draw();
	void rotate( int, int );
	void print_faces();
	int* get_faces();
};

#endif

//***************************************************************************//
// END OF FILE / unit.h                                                      //
//***************************************************************************//
