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

GLfloat zoom, rotx, roty, rotz, transx, transy, transz;
bool* keys;
// Cube cube;

// viewport matrix
GLint view[4]  = { 0, 0, 750, 750 };

void gfxinit()
{
  glEnable( GL_DEPTH_TEST );
  glClearColor( 0.0, 0.0, 0.0, 1.0 );
  glEnable( GL_LINE_SMOOTH );
  glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
  glEnable( GL_POINT_SMOOTH );
  glHint( GL_POINT_SMOOTH_HINT, GL_NICEST );
  glPointSize( 3.0 );
  glLineWidth( 1.5 );

  glShadeModel( GL_SMOOTH );

  zoom = 1.0;
  rotx = 0.0; roty = 0.0; rotz = 0.0;
  transx = 0.0; transy = 0.0; transz = 0.0;

  keys = new bool[256];
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

void keyboard( unsigned char key, int x, int y )
{
  switch ( key )
  {
  case 27: exit( 1 ); break;
  default:            break;
  }

	cout << "normal: " << key << endl;

  glutPostRedisplay();
}

void specialDown( int key, int x, int y )
{
	cout << "special: " << key << endl;

  glutPostRedisplay();
}

void specialUp( int key, int x, int y )
{
  glutPostRedisplay();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
/*
  glScalef( zoom, zoom, zoom );
  glRotatef( rotx, 1.0, 0.0, 0.0 );
  glRotatef( roty, 0.0, 1.0, 0.0 );
  glRotatef( rotz, 0.0, 0.0, 1.0 );
*/

  // draw objects

  glBegin( GL_TRIANGLES );

  glColor3f( 1, 0, 0 );
  glVertex3f( 0., 0., 0. ); glVertex3f( .5, 0., 1. ); glVertex3f( 1., 0., 0. );
  glColor3f( 0, 1, 0 );
  glVertex3f( 0., 0., 0. ); glVertex3f( 1., 0., 0. ); glVertex3f( .5, .5, 0. );
  glColor3f( 0, 0, 1 );
  glVertex3f( 0., 0., 0. ); glVertex3f( .5, .5, 0. ); glVertex3f( .5, 0., 1. );
  glColor3f( 1, 1, 0 );
  glVertex3f( 1., 0., 0. ); glVertex3f( .5, 0., 1. ); glVertex3f( .5, .5, 0. );

  glEnd();

  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void timer( int value )
{
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
  glutKeyboardFunc( keyboard );
  glutSpecialFunc( specialDown );
  glutSpecialUpFunc( specialUp );
  glutTimerFunc( 25, timer, 0 );

  glutMainLoop();
  return 0;
}
