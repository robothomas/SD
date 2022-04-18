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

  public:
    void read_from(const char *mem);
    void write_to(char *mem) const;

    bool get_show_buttons() {
        return show_buttons;
    }

    int get_num_moves() {
        return num_moves;
    }

    string get_status_text() {
        return status_text;
    } 

    string get_new_game_text() {
        return new_game_text;
    } 

    Grid get_grid() {
        return grid;
    }
};

#endif
