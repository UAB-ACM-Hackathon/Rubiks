//***************************************************************************//
// Linker definition file for the cube class.                                //
//                                                                           //
// Filename: cube.h                                                          //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#ifndef L_CUBE_H
#define L_CUBE_H

#include "unit.h"

class Cube
{
 private:
 	Unit[3][3][3] units;
 	
 public:
 	Cube();
 	~Cube();
 	void draw();
};

#endif

//***************************************************************************//
// END OF FILE / cube.h                                                      //
//***************************************************************************//
