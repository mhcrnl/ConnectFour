// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSOLVER_H_
#define _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSOLVER_H_

#include "./ConnectFourMove.h"
#include "./ConnectFourStateBase.h"
#include "./ConnectFourSolverBase.h"

// Simplistic (= stupid) solver.
class ConnectFourSolver : public ConnectFourSolverBase {
 public:
  // Generate a move given the current state. A move is simply the position of a
  // particular cell to be uncovered next.
  ConnectFourMove generateMove(const ConnectFourStateBase* state);

  // Resets internal state, will be called befor each game.
  void reset() {}
};

#endif  // _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSOLVER_H_
