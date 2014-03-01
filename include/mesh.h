#ifndef L_MESH_H
#define L_MESH_H

#include <GL/glut.h>
#include <GL/glu.h>

#include <string>

using namespace std;

class Mesh
{
    public:
        Mesh();
    
        /**
         * Parse the OFF mesh
        **/
        Mesh( string filename );
        
        /**
         * Draw mesh
        **/
        void draw();
        void draw( int );

    private:
        int nPt, nFace, *degFace, **face;
        GLfloat **pt, **normal;
};

#endif
