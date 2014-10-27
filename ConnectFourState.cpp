// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#include <vector>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include "./ConnectFourMove.h"
#include "./ConnectFourState.h"

ConnectFourState dragon;  // objekt
ConnectFourStateBase* DRAGON = &dragon;  // zeiger

// __________________________________________________________________
ConnectFourStateBase::CellInfo ConnectFourState::getCellInfo(
                                    size_t rowIndex, size_t colIndex) const {
  size_t row = rowIndex;
  size_t col = colIndex;
  // return the info of every single field
  // if field is owned by player one, _marked is true
  // if field is owned by player two, _marked is false
  if (_revealed[row][col] == false) {
    return ConnectFourStateBase::UNREVEALED;  // -1
  }
  if (_revealed[row][col] == true) {
    if (_marked[row][col] == true) {
      return ConnectFourStateBase::REVEALED_ONE;  // 1
    } else {
      return ConnectFourStateBase::REVEALED_TWO;  // 2
    }
  }
}

// __________________________________________________________________
void ConnectFourState::initialize(size_t numRows, size_t numCols) {
  _numRevealed = 0;

  // inizialize the whole field
  _numRows = numRows;
  _numCols = numCols;
  _status = ConnectFourStateBase::ONGOING;

  _revealed.clear();  // clear all vectors
  _marked.clear();

  // revealed ones
  for (int i = 0; i < _numRows; i++) {
    _revealed.push_back(std::vector<bool>());
    for (int j = 0; j < _numCols; j++) {
      _revealed[i].push_back(false);
    }
  }
  // marked ones
  for (int i = 0; i < _numRows; i++) {
    _marked.push_back(std::vector<bool>());
    for (int j = 0; j < _numCols; j++) {
      _marked[i].push_back(false);
    }
  }
}

// __________________________________________________________________
bool ConnectFourState::applyMove(const ConnectFourMove& move) {
  size_t x = move.row;
  size_t y = move.col;
  // size_t x = -1;
  // size_t y = -1;

  bool player;  //  true = 1, false = 2
  if (move.type == 0) { player = true; }
  if (move.type == 1) { player = false; }
  if (x < 0 || x > _numRows-1 || y < 0 || y > _numCols-1 ||
      _revealed[0][y]) {
    return false;  // cancel move if out of bounds or row is full
  }
  _numRevealed++;
  for (int i = 0; i < _numRows; i++) {
    if (_revealed[i][y]) {
      x = i - 1;  // Save coordinates of new piece for check winning situation
      if (player) {
        _marked[i - 1][y] = true;
      } else {
        _marked[i - 1][y] = false;
      }
      _revealed[i - 1][y] = true;
      break;
    }
    if (i == _numRows - 1) {
      x = _numRows - 1;  // Save coordinates for check winning situation
      if (player) {
        _marked[_numRows - 1][y] = true;
      } else {
        _marked[_numRows - 1][y] = false;
      }
      _revealed[_numRows - 1][y] = true;
      break;
    }
  }
  // Check winning condition
  // Method 1 (Checking all fields):
  int win = 0;      // if win counts to 4, some won
  // Check row
  if (win < 4) {
    win = 0;
    for (int j = 0; j < _numCols; j++) {
      if (win == 4) { break; }
      if (_revealed[x][j] && _marked[x][j] == player) {
        win++;
      } else {
        win = 0;
      }
    }
  }
  // Check column
  if (win < 4) {
    win = 0;
    for (int j = 0; j < _numRows; j++) {
      if (win == 4) { break; }
      if (_revealed[j][y] && _marked[j][y] == player) {
        win++;
      } else {
        win = 0;
      }
    }
  }
  // Check diagonal \:
  if (win < 4) {
    int tmpX = x;  //  Saving original coordinates
    int tmpY = y;
    win = 0;
    while (tmpX > 0 && tmpY > 0) {  //  Find start of diagonal
      tmpX--;
      tmpY--;
    }
    while (tmpX < _numRows && tmpY < _numCols) {
      if (win == 4) { break; }
      if (_revealed[tmpX][tmpY] && _marked[tmpX][tmpY] == player) {
        win++;
      } else {
        win = 0;
      }
      tmpX++;
      tmpY++;
    }
  }
  // Check diagonal /:
  if (win < 4) {
    int tmpX = x;  //  Saving original coordinates
    int tmpY = y;
    win = 0;
    while (tmpX > 0 && tmpY < _numCols - 1) {  //  Find start of diagonal
      tmpX--;
      tmpY++;
    }
    while (tmpX < _numRows && tmpY > -1) {
      if (win == 4) { break; }
      if (_revealed[tmpX][tmpY] && _marked[tmpX][tmpY] == player) {
        win++;
      } else {
        win = 0;
      }
      tmpX++;
      tmpY--;
    }
  }


  // If someone wins:
  if (win == 4) {
    if (player) {
      _status = ConnectFourStateBase::ONE_WON;
    } else {
      _status = ConnectFourStateBase::TWO_WON;
    }
    return true;
  }

  // If noone wins:
  for (int i = 0; i < 7; i++) {
    if (!_revealed[0][i] || _status == ConnectFourStateBase::ONE_WON ||
        _status == ConnectFourStateBase::TWO_WON) {
      break;
    }
    if (i == 6) {
      _status = ConnectFourStateBase::TIE;
    }
  }
  return true;
}

// __________________________________________________________________
ConnectFourStateBase::GameStatus ConnectFourState::status() const {
  return _status;
}

// __________________________________________________________________
size_t ConnectFourState::numRows() const {
  return _numRows;
}
size_t ConnectFourState::numCols() const {
  return _numCols;
}
size_t ConnectFourState::numRevealed() const {
  return _numRevealed;
}
size_t ConnectFourState::numMarked() const {
  return _numMarked;
}
