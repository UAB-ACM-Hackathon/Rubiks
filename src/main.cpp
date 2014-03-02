#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#endif
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
using std::string;
#include <time.h>
#include <assert.h>
#define _USE_MATH_DEFINES

#include "globals.h"
#include "cube.h"
#include "sector.h"

GLfloat zoom, rotx, roty, rotz, transx, transy, transz;
bool* keys;
bool won;
Cube cube;

int last_slice, last_dir;
int slice, direction;
int initialize;

// viewport matrix
GLint view[4]  = { 0, 0, 750, 750 };

void gfxinit()
{
	init_colors();

  glEnable( GL_DEPTH_TEST );
  glClearColor( 0.0, 0.0, 0.0, 1.0 );
  glEnable( GL_LINE_SMOOTH );
  glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
  glEnable( GL_POINT_SMOOTH );
  glHint( GL_POINT_SMOOTH_HINT, GL_NICEST );
  glPointSize( 3.0 );
  glLineWidth( 1.5 );

  glShadeModel( GL_SMOOTH );

  zoom = 0.25;
  rotx = 10.0; roty = -10.0; rotz = 0.0;
  transx = 0.0; transy = 0.0; transz = 0.0;

	initialize = -1;
  won = false;

  keys = new bool[256];
	for ( int i = 0; i < 256; i++ ) keys[i] = false;
}

void reshape( int w, int h )
{
  glViewport( 0, 0, w, h );

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  if (w <= h)
    glOrtho(-2.0, 2.0, -2.0*(GLfloat) h / (GLfloat) w,
      2.0*(GLfloat) h / (GLfloat) w, -10, 10);
  else
    glOrtho(-2.0*(GLfloat) w / (GLfloat) h,
      2.0*(GLfloat) w / (GLfloat) h, -2.0, 2.0, -10, 10);

  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
}

void keyboardDown( unsigned char key, int x, int y )
{
	if ( (int) key > 255 ) return;

	// 1-9 select sector ( 49-57 as ints)

  switch ( key )
  {
  case 27: exit( 0 ); 			 			 	break;
  default: keys[(int) key] = true; 	break;
  }

  glutPostRedisplay();
}

void keyboardUp ( unsigned char key, int x, int y )
{
	if ( (int) key > 255 ) return;

  keys[(int) key] = false;
  glutPostRedisplay();
}

void specialDown( int key, int x, int y )
{
	if ( key > 255 ) return;

	keys[key] = true;
  glutPostRedisplay();
}

void specialUp( int key, int x, int y )
{
	if ( key > 255 ) return;

	keys[key] = false;
  glutPostRedisplay();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

	glScalef( zoom, zoom, zoom );
	glTranslatef( transx, transy, transz );
	glRotatef( rotx, 1.0, 0.0, 0.0 );
	glRotatef( roty, 0.0, 1.0, 0.0 );
	glRotatef( rotz, 0.0, 0.0, 1.0 );

  // draw objects
	cube.draw();

  glEnd();

  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void timer( int value )
{
	

	if ( cube.is_animating() )
	{
		glutTimerFunc( 25, timer, 0 );
	  glutPostRedisplay();
		return;
	}
	else if ( initialize > 0 )
	{
		do {
			direction = (double)(rand() / (double)RAND_MAX) > 0.5f ? 1 : 0;
			slice = (int)(9*((double)rand() / (double)RAND_MAX)) + 1;
			// cannot reverse last move
		} while ( slice == last_slice && direction == last_dir );
		cube.rotate_sector( slice, direction, true );

		last_slice = slice;
		last_dir   = ( direction % 2 ) + 1;

		initialize--;
	}

  if ( keys[115] )
	{
		if ( initialize <= 0 )
		{
			initialize = 1;
		}
	}
  else if ( keys[49] )
  {
    if       ( keys[GLUT_KEY_UP] ) cube.rotate_sector( 1, 0 );
    else if ( keys[GLUT_KEY_DOWN] ) cube.rotate_sector( 1, 1 );
  }
  else if ( keys[50] )
  {
    if       ( keys[GLUT_KEY_UP] ) cube.rotate_sector( 2, 0 );
    else if ( keys[GLUT_KEY_DOWN] ) cube.rotate_sector( 2, 1 );
  }
  else if ( keys[51] )
  {
    if       ( keys[GLUT_KEY_UP] ) cube.rotate_sector( 3, 0 );
    else if ( keys[GLUT_KEY_DOWN] ) cube.rotate_sector( 3, 1 );
  }
  else if ( keys[52] )
  {
    if       ( keys[GLUT_KEY_LEFT] ) cube.rotate_sector( 4, 0 );
    else if ( keys[GLUT_KEY_RIGHT] ) cube.rotate_sector( 4, 1 );
  }
  else if ( keys[53] )
  {
    if       ( keys[GLUT_KEY_LEFT] ) cube.rotate_sector( 5, 0 );
    else if ( keys[GLUT_KEY_RIGHT] ) cube.rotate_sector( 5, 1 );
  }
  else if ( keys[54] )
  {
    if       ( keys[GLUT_KEY_LEFT] ) cube.rotate_sector( 6, 0 );
    else if ( keys[GLUT_KEY_RIGHT] ) cube.rotate_sector( 6, 1 );
  }
  else if ( keys[55] )
  {
    if       ( keys[GLUT_KEY_LEFT] ) cube.rotate_sector( 7, 0 );
    else if ( keys[GLUT_KEY_RIGHT] ) cube.rotate_sector( 7, 1 );
  }
  else if ( keys[56] )
  {
    if       ( keys[GLUT_KEY_LEFT] ) cube.rotate_sector( 8, 0 );
    else if ( keys[GLUT_KEY_RIGHT] ) cube.rotate_sector( 8, 1 );
  }
  else if ( keys[57] )
  {
    if       ( keys[GLUT_KEY_LEFT] ) cube.rotate_sector( 9, 0 );
    else if ( keys[GLUT_KEY_RIGHT] ) cube.rotate_sector( 9, 1 );
  }
  else if ( keys[GLUT_KEY_UP] ) { rotx -= 5; if ( rotx > 360 ) rotx -= 360; }
  else if ( keys[GLUT_KEY_DOWN] ) { rotx += 5; if ( rotx < 360 ) rotx += 360; }
  else if ( keys[GLUT_KEY_LEFT] ) { roty -= 5; if ( roty < 360 ) roty += 360; }
  else if ( keys[GLUT_KEY_RIGHT] ) { roty += 5; if ( roty > 360 ) roty -= 360; }

	keys[GLUT_KEY_UP] 	 = false;
	keys[GLUT_KEY_DOWN]  = false;
	keys[GLUT_KEY_LEFT]  = false;
	keys[GLUT_KEY_RIGHT] = false;
	
	if ( won || ( initialize == false && cube.win_check() ) ) 
	{
		cout << "Winner!!" << endl;
		won = true;
		cube.explode();
	}

  glutTimerFunc( 25, timer, 0 );
  glutPostRedisplay();
}

int main( int argc, char **argv )
{
  srand( time( 0 ) ); // init pseudo-RNG
  
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
  glutInitWindowSize( 750, 750 );
  glutInitWindowPosition( 0, 0 );
  glutCreateWindow( "Rubik's Cube" );

  gfxinit();
  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyboardDown );
	glutKeyboardUpFunc( keyboardUp );
  glutSpecialFunc( specialDown );
  glutSpecialUpFunc( specialUp );
  glutTimerFunc( 25, timer, 0 );

  glutMainLoop();
  return 0;
}
