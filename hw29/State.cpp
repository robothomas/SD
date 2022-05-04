#include <iostream>
#include "State.h"
using namespace std;


const int State::offset = 2, State::label_offset = 5000;

int State::offset_for_status_text() const {
  return offset + 1 + 3;
}

int State::offset_for_grid() const {
  return offset_for_status_text() + status_text.size() + 1;
}

int State::offset_for_raw_colors() /*const*/ {
  return offset_for_grid() + grid.size_in_bytes();
}

void State::read_from(const char *mem) {
  //cerr << "inside state's read_from" << endl;
  show_buttons = _get_bool(mem, 1);
  //cerr << "show buttons is " << show_buttons << endl;
  num_moves = _get_int(mem + 1, 3);
  //cerr << "num moves is " << num_moves << endl;
  status_text = _get_tilde_terminated_string(mem + 4);
  //cerr << "status text: " << status_text << endl;
  //cerr << "entering grid read from" << endl;
  grid.read_from(mem + 5 + status_text.size());
}

void State::write_to(char *mem) const {
  _put_bool(show_buttons, mem, 1);
  mem += 1;
  _put_int(num_moves, mem, 3);
  mem += 3;
  _put_tilde_terminated_string(status_text, mem);
  mem += status_text.size() + 1;
  grid.write_to(mem);
}