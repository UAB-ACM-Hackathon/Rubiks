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

// Cube cube;

void gfxinit()
{
	// cube = Cube();
}

void reshape(int w, int h)
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

void display()
{

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
  glutKeyboardFunc( keyboard );
  glutSpecialFunc( specialDown );
  glutSpecialUpFunc( specialUp );
  glutTimerFunc( 25, timer, 0 );

  glutMainLoop();
  return 0;
}
