//***************************************************************************//
// Linker definition file for the sector class.                              //
//                                                                           //
// Filename: sector.h                                                        //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#ifndef L_SECTOR_H
#define L_SECTOR_H

#include "unit.h"
#include <iostream>

class Sector
{
  private:
    int *cube_indices;                     // list of indices
    int orientation;                       // orientation of the sector
    int position;                          // holds inner/outer property
		Unit* cw_rotate(Unit *units);          // perform rotation CW
    Unit* ccw_rotate(Unit *units);         // perform rotation CCW
		Unit* rotate_units(Unit *units, int direction); // rotate every unit object
    
  public:
    Sector();                              // default constructor
    Sector(int *cube_indices, int orientation, int position); // constructor
    Unit* rotate(Unit *units, int direction); // simulate a rotation CW||CCW
		int* get_sequence();
		int get_position();
		void print_sequence();
};

#endif

//***************************************************************************//
// END OF FILE / sector.h                                                    //
//***************************************************************************//
