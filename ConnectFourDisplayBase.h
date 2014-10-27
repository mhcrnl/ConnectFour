// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#ifndef _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURDISPLAYBASE_H_
#define _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURDISPLAYBASE_H_

#include "./ConnectFourStateBase.h"

class ConnectFourDisplayBase;
extern ConnectFourDisplayBase* DISPLAY;

// Class for showing a state of the game on the screen.
class ConnectFourDisplayBase {
 public:
  virtual void show(const ConnectFourStateBase* state) const = 0;
};

#endif  // _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURDISPLAYBASE_H_
