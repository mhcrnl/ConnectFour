// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSOLVERBASE_H_
#define _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSOLVERBASE_H_

#include "./ConnectFourMove.h"
#include "./ConnectFourStateBase.h"

class ConnectFourSolverBase;
extern ConnectFourSolverBase* SOLVER;

// Abstract interface class for a ConnectFour solver.
class ConnectFourSolverBase {
 public:
  // Virtual destructor.
  virtual ~ConnectFourSolverBase() { }

  // Generate a move given the current state. A move is simply the position of a
  // particular cell to be uncovered next.
  virtual ConnectFourMove generateMove(const ConnectFourStateBase* state) = 0;

  // Resets internal state, will be called befor each game.
  virtual void reset() = 0;
};

#endif  // _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSOLVERBASE_H_
