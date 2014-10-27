// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include "./ConnectFourDisplay.h"

ConnectFourDisplay display;
ConnectFourDisplayBase* DISPLAY = &display;

// __________________________________________________________________
ConnectFourDisplay::ConnectFourDisplay() {
}

// __________________________________________________________________
ConnectFourDisplay::~ConnectFourDisplay() {
  endwin();
}

// __________________________________________________________________
void ConnectFourDisplay::show(const ConnectFourStateBase* state) const {
  size_t rows = state->numRows();  // gets the number of rows from the state
  size_t cols = state->numCols();  // gets the number of columns "
  for (int i = 0; i < rows; i++) {  // prints the whole field again
    for (int j = 0; j < cols; j++) {
      switch (state->getCellInfo(i, j)) {  // gets info of every single field
        case ConnectFourStateBase::UNREVEALED:
          printf("\x1b[7m");
          printf("\x1b[%d;%dH   ", 3*i+1, 3*j+1);  // prints an inverted '?'
          printf("\x1b[%d;%dH   ", 3*i+2, 3*j+1);  // prints an inverted '?'
          printf("\x1b[%d;%dH   ", 3*i+3, 3*j+1);  // prints an inverted '?'
          printf("\x1b[0m");
          break;
        case ConnectFourStateBase::REVEALED_ONE:
          printf("\x1b[41m");
          printf("\x1b[%d;%dH   ", 3*i+1, 3*j+1);  // prints an inverted '?'
          printf("\x1b[%d;%dH   ", 3*i+2, 3*j+1);  // prints an inverted '?'
          printf("\x1b[%d;%dH   ", 3*i+3, 3*j+1);  // prints an inverted '?'
          printf("\x1b[0m");
          break;
        case ConnectFourStateBase::REVEALED_TWO:
          printf("\x1b[46m");
          printf("\x1b[%d;%dH   ", 3*i+1, 3*j+1);  // prints an inverted '?'
          printf("\x1b[%d;%dH   ", 3*i+2, 3*j+1);  // prints an inverted '?'
          printf("\x1b[%d;%dH   ", 3*i+3, 3*j+1);  // prints an inverted '?'
          printf("\x1b[0m");
          break;
      }
      fflush(stdout);
    }
  }
  switch (state->status()) {
    case ConnectFourStateBase::ONGOING:
      printf("\x1b[%d;%dHPress (r) to reset, (q) to quit.", 11, 30);
      // Print general layout:
      // *----
      printf("\x1b[%d;%luH 1  2  3  4  5  6  7", 19, 1);
      // ----*
      break;
    case ConnectFourStateBase::ONE_WON:
      printf("\x1b[%d;%dHPlayer one won!", 9, 30);
      printf("\x1b[%d;%dHPress (r) to reset, (q) to quit.", 11, 30);
      break;
    case ConnectFourStateBase::TWO_WON:
      printf("\x1b[%d;%dHPlayer two won", 9, 30);
      printf("\x1b[%d;%dHPress (r) to reset, (q) to quit.", 11, 30);
      break;
    case ConnectFourStateBase::TIE:
      printf("\x1b[%d;%dHTie! Try again.", 9, 30);
      printf("\x1b[%d;%dHPress (r) to reset, (q) to quit.", 11, 30);
      break;
  }
}
