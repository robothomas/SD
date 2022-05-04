#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;
#include"/usr/local/cs/cs251/react.h"
#include"State.h"

State state;

void test_update_1() {
  _read_event_info_file("frame1.event");
  state.update();
  cout << "after first button press:" << endl;
  state.get_grid().print();
  cout << "show_buttons is " << state.get_show_buttons() << endl;
  assert(5 == state.get_grid().get_color(GridLocation{2, 0}));
  assert(5 == state.get_grid().get_color(GridLocation{0, 2}));
}

void test_update_2() {
  _read_event_info_file("frame2.event");
  state.update();
  cout << endl << "after second button press:" << endl;
  state.get_grid().print();
  cout << "show_buttons is " << state.get_show_buttons() << endl;
  assert(0 == state.get_grid().get_color(GridLocation{2, 0}));
  assert(0 == state.get_grid().get_color(GridLocation{0, 2}));
  assert(false == state.get_show_buttons());
}

int main() {
  _read_global_mem_from_file("frame1.txt");
  state.read_from(_global_mem + state.offset);
  test_update_1();
  // test_update_2();
  delete _global_mem;
}
