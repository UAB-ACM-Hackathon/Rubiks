#include <fstream>
#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using std::string;

#include "mesh.h"

Mesh::Mesh() { }

Mesh::Mesh( string filename )
{
  ifstream in( filename );  // infile: OFF mesh
  string type;              // mesh type
  float nEdge;              // number of edges

  in >> type;
  in >> nPt;
  in >> nFace;
  in >> nEdge;

  pt = new GLfloat*[nPt];     // points
  face = new int*[nFace];     // faces
  degFace = new int[nFace];   // face degrees

  float x = 0, y = 0, z = 0, mx = -1; // mean values and max outlier
  for ( int i = 0; i < nPt; i++ )     // populate pts and calc. mean values
  {
    pt[i] = new float[3];
    in >> pt[i][0];
    in >> pt[i][1];
    in >> pt[i][2];
    x += pt[i][0];
    y += pt[i][1];
    z += pt[i][2];
  }

  x /= nPt;
  y /= nPt;
  z /= nPt;

  for (int i = 0; i < nPt; i++)       // translate by mean and calc. max value
  {
    pt[i][0] -= x; pt[i][1] -= y;
    if ( filename != "meshes/hemisphere.off" ) pt[i][0] -= z;
    mx = fmax(mx, fmax(fabs(pt[i][0]), fmax(fabs(pt[i][1]), fabs(pt[i][2]))));
  }

  for (int i = 0; i < nPt; i++)       // scale to unit cube wrt. max
  {
    pt[i][0] /= mx;
    pt[i][1] /= mx;
    pt[i][2] /= mx;
  }

  int *ptFreq = new int[nPt];
  for (int i = 0; i < nFace; i++)
  {
    // read degree -- init ith face and color vector
    in >> degFace[i];
    face[i] = new int[degFace[i]];

    for (int j = 0; j < degFace[i]; j++)
    {
      in >> face[i][j]; // store each vertex
      ptFreq[face[i][j]]++;
    }
  }

  // init vertex normals
  normal = new GLfloat*[nPt];
  for ( int i = 0; i < nPt; i++ )
    normal[i] = new GLfloat[3];

  // 2 vectors (a,b) for normal vector (n)
  float *a = new float[3];
  float *b = new float[3];
  float *n = new float[3];
  for (int i = 0; i < nFace; i++)
  {
    a[0] = (pt[face[i][0]][0] - pt[face[i][1]][0]); // a = v1 - v2
    a[1] = (pt[face[i][0]][1] - pt[face[i][1]][1]);
    a[2] = (pt[face[i][0]][2] - pt[face[i][1]][2]);
    b[0] = (pt[face[i][0]][0] - pt[face[i][2]][0]); // b = v1 - v3
    b[1] = (pt[face[i][0]][1] - pt[face[i][2]][1]);
    b[2] = (pt[face[i][0]][2] - pt[face[i][2]][2]);

    n[0] = (a[1] * b[2]) - (a[2] * b[1]);           // n = a x b
    n[1] = (a[2] * b[0]) - (a[0] * b[2]);
    n[2] = (a[0] * b[1]) - (a[1] * b[0]);

    float m = sqrt( n[0]*n[0] + n[1]*n[1] + n[2]*n[2] );

    n[0] /= m;
    n[1] /= m;
    n[2] /= m;

    int p;
    for ( int j = 0; j < degFace[i]; j++ )
    {
      p = face[i][j];
      normal[p][0] = n[0] / ptFreq[p];
      normal[p][1] = n[1] / ptFreq[p];
      normal[p][2] = n[2] / ptFreq[p];
    }
  }
}

void Mesh::draw()
{
  for (int i = 0; i < nFace; i++)
  {
    glBegin( GL_POLYGON );
    for (int j = 0; j < degFace[i]; j++)
    {
      glNormal3fv( normal[face[i][j]] );
      glVertex3fv( pt[face[i][j]] );
    }
    glEnd();
  }
}
