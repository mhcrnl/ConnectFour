// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#ifndef _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSTATEBASE_H_
#define _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSTATEBASE_H_

#include <vector>
#include "./ConnectFourMove.h"

class ConnectFourStateBase;
extern ConnectFourStateBase* DRAGON;

// Class representing a state of the Minesweeper game.
//
// NOTE: This class *must* be used both by the people programming the game (to
// be played by a human via the keyboard), as well as by the people programming
// a solver (which automatically generates a move given a state).
class ConnectFourStateBase {
 public:
  // Virtual destructor.
  virtual ~ConnectFourStateBase() { }

  // Get cell information (for playing):
  enum CellInfo {
    UNREVEALED = 0, REVEALED_ONE = 1, REVEALED_TWO =2
  };
  virtual CellInfo getCellInfo(size_t rowIndex, size_t colIndex)
  const = 0;

  // Initialize (randomly).
  virtual void initialize(size_t numRows, size_t numCols)
  = 0;

  // Apply move.
  virtual bool applyMove(const ConnectFourMove& move) = 0;

  // Status of the game:
  enum GameStatus { ONGOING, ONE_WON, TWO_WON, TIE};
  virtual GameStatus status() const = 0;

  // Getters.
  virtual size_t numRows() const = 0;
  virtual size_t numCols() const = 0;
  virtual size_t numRevealed() const = 0;
};

#endif  // _HOME_SHUKI_PROGRAMS_CONNECTFOUR_CONNECTFOURSTATEBASE_H_
