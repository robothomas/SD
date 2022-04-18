#include <iostream>
using namespace std;
#include "State.h"
#include "/usr/local/cs/cs251/show_mem.h"

void State::read_from(const char *mem) {
  show_buttons = _get_bool(mem, 1);
  mem += 1;
  num_moves = _get_int(mem, 3);
  mem += 3;
  status_text = _get_tilde_terminated_string(mem);
  mem += status_text.size() + 1;
  new_game_text = _get_tilde_terminated_string(mem);
  mem += new_game_text.size() + 1;
  grid.read_from(mem);
}

void State::write_to(char *mem) const {
  _put_bool(show_buttons, mem, 1);
  mem += 1;
  _put_int(num_moves, mem, 3);
  mem += 3;
  _put_tilde_terminated_string(status_text, mem);
  mem += status_text.size() + 1;
  _put_tilde_terminated_string(new_game_text, mem);
  mem += new_game_text.size() + 1;
  grid.write_to(mem);
}