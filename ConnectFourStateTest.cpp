// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#include <gtest/gtest.h>
#include "./ConnectFourState.h"
#include "./ConnectFourMove.h"
/*
// __________________________________________________________________
TEST(ConnectFourStateTest, getCellInfo) {
  ConnectFourState state;
  ConnectFourMove move;
  move.row = 2;
  move.col = 2;
  move.type = move.REVEAL;
  state.initialize(3, 3, 0);
  ASSERT_EQ(-1, state.getCellInfo(2, 2));
  // no more tests because this is a getter, be happy and smile!
}

// __________________________________________________________________
TEST(ConnectFourStateTest, initialize) {
  ConnectFourState state;
  state.initialize(13, 9, 7);  // initialize a field
  ASSERT_EQ(13, state.numRows());
  ASSERT_EQ(9, state.numCols());
  ASSERT_EQ(7, state.numDragons());
  state.initialize(3, 20, 21);  // initialize a field
  ASSERT_EQ(3, state.numRows());
  ASSERT_EQ(20, state.numCols());
  ASSERT_EQ(21, state.numDragons());
}

// __________________________________________________________________
TEST(ConnectFourStateTest, applyMove) {
  ConnectFourState state;
  ConnectFourMove move;
  move.row = 2;
  move.col = 5;
  move.type = move.REVEAL;  // reveal a field
  state.initialize(5, 12, 0);  // example without dragons
  ASSERT_EQ(-1, state.getCellInfo(2, 5));
  state.applyMove(move);  // reveal
  ASSERT_EQ(0, state.getCellInfo(2, 5));  // revealed a zero
  ASSERT_EQ(0, state.getCellInfo(2, 5));  // and because there are only zeros
  ASSERT_EQ(state.WON, state.status());  // status turned to WON

  state.initialize(10, 10, 100);  // example with dragons only
  ASSERT_EQ(-1, state.getCellInfo(2, 5));
  state.applyMove(move);  // reveal
  ASSERT_EQ(-3, state.getCellInfo(2, 5));  // field is a dragon
  ASSERT_EQ(-1, state.getCellInfo(2, 2));  // other field are unrevealed
  ASSERT_EQ(state.LOST, state.status());  // status turn to LOST
  state.applyMove(move);  // try to reveal again
  ASSERT_EQ(-1, state.getCellInfo(2, 2));  // no more moves allowed

  move.row = 7;
  move.col = 11;
  move.type = move.TOGGLE_MARK;  // mark a field
  state.initialize(12, 15, 20);
  ASSERT_EQ(-1, state.getCellInfo(7, 11));  // unrevealed field
  state.applyMove(move);
  ASSERT_EQ(-2, state.getCellInfo(7, 11));  // marked a field
  ASSERT_EQ(-1, state.getCellInfo(2, 2));  // unrevealed field
  state.applyMove(move);
  ASSERT_EQ(-1, state.getCellInfo(7, 11));  // dismark the field again
  ASSERT_EQ(state.ONGOING, state.status());

  move.row = 4;
  move.col = 4;
  move.type = move.REVEAL;
  state.initialize(10, 10, 0);  // no dragons set
  state._dragons[5][5] = true;  // one dragon set
  state._numDragons = 1;
  state._dragonCounts[4][4] = 1;
  state._dragonCounts[4][5] = 1;
  state._dragonCounts[4][6] = 1;
  state._dragonCounts[5][4] = 1;
  state._dragonCounts[5][6] = 1;
  state._dragonCounts[6][4] = 1;
  state._dragonCounts[6][5] = 1;
  state._dragonCounts[6][6] = 1;
  ASSERT_EQ(-1, state.getCellInfo(4, 4));
  state.applyMove(move);
  ASSERT_EQ(1, state.getCellInfo(4, 4));
  ASSERT_EQ(state.ONGOING, state.status());
  move.row = 9;
  move.col = 9;
  state.applyMove(move);
  ASSERT_EQ(0, state.getCellInfo(9, 9));  // reveals adjacent fiels around 0
  ASSERT_EQ(1, state.getCellInfo(4, 5));
  ASSERT_EQ(1, state.getCellInfo(4, 6));
  ASSERT_EQ(1, state.getCellInfo(5, 4));
  ASSERT_EQ(1, state.getCellInfo(6, 4));
  ASSERT_EQ(1, state.getCellInfo(6, 5));
  ASSERT_EQ(1, state.getCellInfo(6, 6));
  ASSERT_EQ(1, state.getCellInfo(5, 6));
  ASSERT_EQ(state.ONGOING, state.status());
  move.row = 5;
  move.col = 5;
  move.type = move.TOGGLE_MARK;
  state.applyMove(move);
  ASSERT_EQ(-2, state.getCellInfo(5, 5));  // marks the dragon
  ASSERT_EQ(state.WON, state.status());
}
*/
