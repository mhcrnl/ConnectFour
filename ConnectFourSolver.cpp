// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#include<stdlib.h>

#include "./ConnectFourMove.h"
#include "./ConnectFourStateBase.h"
#include "./ConnectFourSolver.h"

// unnecessary since solver is not global anymore
// ConnectFourSolver solver;  // objekt  
// ConnectFourSolverBase* SOLVER = &solver;  // zeiger

// _____________________________________________________________________________
ConnectFourMove ConnectFourSolver::generateMove(
    const ConnectFourStateBase* state) {
  ConnectFourMove move;
  // So far only random move as in the example of Prof. Bast
  move.row = random() % state->numRows();
  move.col = random() % state->numCols();
  move.type = ConnectFourMove::TWO;
  return move;
}
