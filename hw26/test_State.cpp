#include<iostream>
#include<cassert>
#include<fstream>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"
#include"State.h"

State state;

void test_read_from() {
  //cerr << "inside read from" << endl;
  state.read_from(_global_mem + 2);
  //cerr << "successful read from global mem" << endl;
  assert(state.get_show_buttons() == true);
  //cerr << "get show buttons" << endl;
  assert(state.get_num_moves() == 23);
  //cerr << "get num moves" << endl;
  assert(state.get_status_text() == "ok");
  //cerr << "get status text" << endl;
  assert(state.get_grid().get_color(GridLocation{1, 2}) == 4);
  //cerr << "color at grid location" << endl;
}

void test_write_to() {
  state.write_to(_global_mem + 10);
  //cerr << string(_global_mem).substr(0, 70) << endl;
  assert(_global_mem[14] == 'o');
}

int main() {
  _read_global_mem_from_file("state1.txt");
  //cerr << "_global_mem contains " << _global_mem << endl;
  //cerr << "read mem" << endl;
  test_read_from();
  //cerr << "test read from works" << endl;
  if (1) {
    test_write_to();
    //cerr << "test write to works" << endl;
    _write_global_mem_to_file("state2.txt");
  }

  cerr << "tests cleared!" << endl;

  //cerr << "about to delete global mem" << endl;
  delete _global_mem;
  cerr << "after deletion of global mem" << endl;
}
