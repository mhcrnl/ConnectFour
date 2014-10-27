// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#ifndef _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURMOVE_H_
#define _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURMOVE_H_

#include <stdlib.h>

// A move.
class ConnectFourMove {
 public:
  // The position of the cell to be uncovered next.
  size_t row;
  size_t col;

  // Type of move (reveal or toggle mine mark).
  // enum { REVEAL, TOGGLE_MARK } type1;
  enum { ONE = 0, TWO = 1 } type;
};

#endif  // _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURMOVE_H_
