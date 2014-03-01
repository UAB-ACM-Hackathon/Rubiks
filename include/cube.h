//***************************************************************************//
// Linker definition file for the cube class.                                //
//                                                                           //
// Filename: cube.h                                                          //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#ifndef L_CUBE_H
#define L_CUBE_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#endif

#include "unit.h"

class Cube
{
 private:
 	Unit units[3][3][3];
 	
 public:
 	Cube();
 	~Cube();
 	void draw();
};

#endif

//***************************************************************************//
// END OF FILE / cube.h                                                      //
//***************************************************************************//
