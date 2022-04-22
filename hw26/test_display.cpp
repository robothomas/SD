#include<iostream>
#include<fstream>
using namespace std;
#include"/usr/local/cs/cs251/react.h"
#include"State.h"

State state;

void test_display() {
  display(state);
  assert(_global_yaml.size() > 2000);
  // assert(_global_mem[state.offset_for_raw_colors()] == 216);
}

int main() {
  _read_global_mem_from_file("state1.txt");
  state.read_from(_global_mem + state.offset);
  ifstream f_label("labels.txt");
  f_label.read(_global_mem + state.label_offset, 4000);
  test_display();
  _write_global_yaml_to_file("react.yaml");
  delete _global_mem;
}
