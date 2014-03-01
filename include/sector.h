//***************************************************************************//
// Linker definition file for the sector class.                              //
//                                                                           //
// Filename: sector.h                                                        //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#ifndef L_SECTOR_H
#define L_SECTOR_H

#include "unit.h"

class Sector
{
  private:
    int *cube_indices;                    // list of indices
    int orientation;                      // orientation of the sector
    int position;                         // holds inner/outer property
    
  public:
    Sector(int *cube_indices, int orientation, int position); // constructor
    void rotate(Unit *units, int direction); // simulate a rotation CW||CCW
    void cw_rotate(Unit *units);          // perform rotation CW
    void ccw_rotate(Unit *units);         // perform rotation CCW
    void print_indices();                 // print cube_indices array
};

#endif

//***************************************************************************//
// END OF FILE / sector.h                                                    //
//***************************************************************************//
