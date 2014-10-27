// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#ifndef _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSTATE_H_
#define _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSTATE_H_

#include <gtest/gtest.h>
#include <vector>
#include "./ConnectFourMove.h"
#include "./ConnectFourStateBase.h"

// class ConnectFourStateBase;

class ConnectFourState : public ConnectFourStateBase {
 public:
  // Get cell information (for playing):
  //
 /* CellInfo {
    UNREVEALED = 0, REVEALED_ONE = 1, REVEALED_TWO =2
  }; */
  CellInfo getCellInfo(size_t rowIndex, size_t colIndex) const;

  // Initialize (randomly).
  void initialize(size_t numRows, size_t numCols);

  // Apply move.
  bool applyMove(const ConnectFourMove& move);
  FRIEND_TEST(ConnectFourStateTest, applyMove);

  // Status of the game:
  // GameStatus { ONGOING, LOST, WON };
  GameStatus status() const;

  // Getters.
  size_t numRows() const;
  size_t numCols() const;
  size_t numRevealed() const;
  size_t numMarked() const;

 private:
  // The dimensions of the game (number of rows and columns).
  size_t _numRows;
  size_t _numCols;
  size_t _numRevealed;
  size_t _numMarked;

  // Whether a cell has been revealed yet or not.
  std::vector<std::vector<bool>> _revealed;

  // Whether a cell has been marked by player one or player two.
  // true = one, false = two
  std::vector<std::vector<bool>> _marked;

  // Status (-1, 0, 1 .. see above).
  GameStatus _status;
};

#endif  // _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSTATE_H_
