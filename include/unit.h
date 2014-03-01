//***************************************************************************//
// Linker definition file for the unit class.                                //
//                                                                           //
// Filename: unit.h                                                          //
// Team Krostin Kobra                                                        //
//***************************************************************************//

#ifndef L_UNIT_H
#define L_UNIT_H

class Unit
{
 private:
 	int faces[6];
 	
 public:
	Unit();
 	Unit( int, int, int, int, int, int );
 	~Unit();
};

#endif

//***************************************************************************//
// END OF FILE / unit.h                                                      //
//***************************************************************************//
