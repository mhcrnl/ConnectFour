// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#ifndef _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURDISPLAY_H_
#define _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURDISPLAY_H_

#include <vector>
#include "./ConnectFourDisplayBase.h"
#include "./ConnectFourStateBase.h"

class ConnectFourDisplayBase;

// Class for showing a state of the game on the screen.
class ConnectFourDisplay : public ConnectFourDisplayBase {
 public:
  // Constructor
  ConnectFourDisplay();

  // Destructor
  ~ConnectFourDisplay();

  // StartScreen for the users to play the game
  void StartScreen();

  // Shows the screen while the game is running
  void show(const ConnectFourStateBase* state) const;

  // End of the game
  // void gameOver();
};

#endif  // _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURDISPLAY_H_
