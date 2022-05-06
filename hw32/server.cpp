#include<iostream>
#include<fstream>
using namespace std;
#include"/usr/local/cs/cs251/react.h"

class State {
  int num;

public:
  State() { num = 0; }
  int get_num() const { return num; }
  void read_from(const char *s) { num = _get_int(s, 3); }
  void write_to(char *s) { _put_int(num, s, 3); }
  int size_in_bytes() const { return 3; }
  void update() { if (_received_event() && 'a' == _global_mem[100]) ++num; }
};

void display(const State &state) {
  string s = "num is " + to_string(state.get_num());
  int i = 1 + state.size_in_bytes();
  _put_tilde_terminated_string(s, _global_mem + i);
  _add_yaml("count.yaml", {{"top_index", i}, {"input_index", 100}});
}

int main() {
  _read_global_mem_from_file("begin_mem");
  _read_event_info_file("event_info");

  State state;
  if (! _just_starting()) state.read_from(_global_mem + 1);

  state.update(); // event handling
  display(state); // display logic

  state.write_to(_global_mem + 1);
  _write_global_mem_to_file("end_mem");
  _write_global_yaml_to_file("react.yaml");
  delete _global_mem;
}
