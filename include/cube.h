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
#include "sector.h"

class Cube
{
 private:
 	Unit units[3][3][3];
	Sector sectors[9];
	int* index( int );
	bool anim_lock;
	int anim_axis, anim_dir;
	int* anim_seq;
	Sector sector;
	GLfloat rot;
 	
 public:
 	Cube();
 	~Cube();
 	void draw();
	void rotate_sector( int, int );
	bool win_check();
	bool is_animating();
	bool in_sequence( int, int, int, int* );
	void end_animation();
};

#endif

//***************************************************************************//
// END OF FILE / cube.h                                                      //
//***************************************************************************//
