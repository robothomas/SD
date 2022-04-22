#ifndef __STATE_H__
#define __STATE_H__

#include <string>
using namespace std;
#include "Grid.h"

class State {
  int num_moves;
  bool show_buttons;
  string status_text;
  Grid grid;

  public:
    static const int offset, label_offset;
    void read_from(const char *mem);
    void write_to(char *mem) const;

    int offset_for_status_text() const;
    int offset_for_grid() const;
    int offset_for_raw_colors() const;

    bool get_show_buttons() {
        return show_buttons;
    }

    int get_num_moves() {
        return num_moves;
    }

    string get_status_text() {
        return status_text;
    } 

    Grid get_grid() {
        return grid;
    }
};

void display(const State &); // &state ??? or is just & allowed?

#endif
