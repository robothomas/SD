#include<iostream>
#include<cassert>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"
#include"Grid.h"

void test_in_rectangle() {
  GridLocation gl{3, 5};
  assert(gl.in_rectangle(100, 100));
  assert(!gl.in_rectangle(3, 6));
  assert(!gl.in_rectangle(4, 5));
}

void test_set() {
  Grid g;
  GridLocation gl{1, 2};
  g.set_color(gl, 9);
  assert(g.get_color(gl) == 9);
  g.print();
};

void test_is_one_color() {
  Grid g;
  assert(g.is_one_color() == false);
}

void test_randomize() {
  Grid g;
  g.randomize();
  g.print();
}

void test_fill() {
  Grid g(3);
  g.print();
  g.fill(GridLocation{0, 0}, 3);
  assert(g.get_color(GridLocation{2, 1}) == 3);
  g.print();
}

// I changed the numbers to have single quotes, not sure if this ruins the test.
void test_read_from() {
  Grid g;
  const char *mem = " 2 3 1 2 3 4 5 0";
  g.read_from(mem);
  assert('1' == g.get_color(GridLocation{0, 0}));
  assert('3' == g.get_color(GridLocation{0, 1}));
  assert('0' == g.get_color(GridLocation{1, 2}));
}

void test_write_to() {
  Grid g;
  char mem[] = "0123456789012345";
  g.write_to(mem + 3);
  cerr << "mem is " << mem << endl;
  assert(mem[3] == ' ');
  assert(mem[4] == '2');
  assert(mem[7] == ' ');
  assert(mem[8] == '1');
}

void test_size_in_bytes() {
  Grid g;
  assert(g.size_in_bytes() == 16);
}

int main() {
  test_in_rectangle();
  test_set();
  test_is_one_color();
  test_randomize();
  test_fill();
  test_read_from();
  test_write_to();
  test_size_in_bytes();
}
