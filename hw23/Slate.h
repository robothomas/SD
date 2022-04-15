#ifndef __STATE_H__
#define __STATE_H__

#include <string>
using namespace std;
#include "Grid.h"

class State {
  int num_moves;
  bool show_buttons;
  string status_text, new_game_text;
  Grid grid;

  void get_show_buttons() {
      return show_buttons;
  }

  void get_num_moves() {
      return num_moves;
  }

  void get_status_text() {
      return status_text;
  } 

  void get_new_game_text() {
      return new_game_text;
  } 

  void get_grid() {
      return grid;
  }
};

#endif
