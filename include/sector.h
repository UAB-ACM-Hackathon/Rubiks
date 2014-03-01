//***************************************************************************//
// Linker definition file for the sector class.                              //
//                                                                           //
// Filename: sector.h                                                        //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#ifndef L_SECTOR_H
#define L_SECTOR_H

class Sector
{
  private:
    int *faces;                           // list of faces
    int orientation;                      // orientation of the sector
    
  public:
    Sector( int *faces, int orientation); // constructor
    void rotate(int direction);                // simulate a rotation CW||CCW
};

#endif

//***************************************************************************//
// END OF FILE / sector.h                                                    //
//***************************************************************************//
