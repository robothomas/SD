#include<iostream>
#include"/usr/local/cs/cs251/show_mem.h"
using namespace std;

int main() { 
  char buffer[] = "56789.43";
  int b;
  float c; 
  double d1;
  double d2;
  b = _get_int(buffer + 1, 2);
  c = _get_float(buffer + 4, 3);
  // reading double
  d1 = _get_double(buffer, 7);
  // changing data
  buffer[2] = '1';
  buffer[4] = '3';
  // reading a different double with changed data
  d2 = _get_double(buffer + 1, 7);
  cout << "b " << b << endl;
  cout << "c " << c << endl;
  cout << "d1 " << d1 << endl;
  cout << "d2 " << d2 << endl;
}
