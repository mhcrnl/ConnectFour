// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures, Chair of Despair
// Author: Larissa Bulka <larissa.bulka@gmx.net>,
//         Joshua Marben <yoshimarben@gmx.de>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include "./ConnectFourDisplay.h"
#include "./ConnectFourState.h"
#include "./ConnectFourMove.h"
#include "./ConnectFourSolver.h"

extern ConnectFourDisplayBase* DISPLAY;
extern ConnectFourStateBase* DRAGON;
extern ConnectFourSolverBase* SOLVER;

// Main function.
int main(int argc, char** argv) {
  // initialize ncurses
  // *----
  initscr();
  nodelay(stdscr, true);
  noecho();
  cbreak();
  curs_set(false);
  keypad(stdscr, true);
  // ----*
  bool playAgain = false;  // to enable replay option
  while (playAgain == false) {
    DRAGON->initialize(6, 7);
    bool leri = true;    // false = Player2, true = Player1
    ConnectFourMove move;
    MEVENT me;
    mousemask(ALL_MOUSE_EVENTS, NULL);
    playAgain = true;
    while (playAgain) {
      DISPLAY->show(DRAGON);
      int ch = getch();
      if (ch == -1) continue;
      // Play game with number keys
      if ((ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' ||
        ch == '6' || ch == '7') &&
        DRAGON->status() == ConnectFourStateBase::ONGOING && leri) {
        move.row = 1;
        switch (ch) {
          case '1':
            move.col = 0;
            break;
          case '2':
            move.col = 1;
            break;
          case '3':
            move.col = 2;
            break;
          case '4':
            move.col = 3;
            break;
          case '5':
            move.col = 4;
            break;
          case '6':
            move.col = 5;
            break;
          case '7':
            move.col = 6;
            break;
        }
        if (leri) {
          move.type = move.ONE;
        } else {
          move.type = move.TWO;
        }
        if (DRAGON->applyMove(move)) {
          leri = !leri;
          if (leri) {
            printf("\x1b[%d;%luHPlayer 1", 5, 30);
          } else {
            printf("\x1b[31m");
            printf("\x1b[%d;%luHPlayer 2", 5, 30);
            printf("\x1b[0m");
          }
        }
        fflush(stdout);
      }
      DISPLAY->show(DRAGON);
      if (DRAGON->status() == ConnectFourStateBase::ONGOING && !leri) {
        move.row = 1;
        sleep(1);
        if (DRAGON->applyMove(SOLVER->generateMove(DRAGON))) {
          leri = !leri;
        }
      }
      // Mouse Control:
      /*
      if (getmouse(&me) == OK &&
          DRAGON->status() == ConnectFourStateBase::ONGOING) {
        // Catch mouse action
        if (me.bstate & BUTTON1_CLICKED) {  // reveal
          move.row = me.y;
          move.col = me.x;
          if (leri) {
            move.type = move.ONE;
          } else {
            move.type = move.TWO;
          }
          if (DRAGON->applyMove(move)) {
            leri = !leri;
            if (leri) {
              printf("\x1b[%d;%luHPlayer 1", 5, 9);
            } else {
              printf("\x1b[31m");
              printf("\x1b[%d;%luHPlayer 2", 5, 9);
              printf("\x1b[0m");
            }
          }
          fflush(stdout);
        }
      }*/
      // ends the game with 'q' or restart the game with 'r'
      if (ch  == 'q') break;
      if (ch  == 'r') {
        // Empty screen:
        printf("\x1b[%d;%dH", 1, 1);
        std::cout << std::string(100, '\n');
        playAgain = false;  // leaving the while loop
      }
    }
    DISPLAY->~ConnectFourDisplayBase();
  }
}
