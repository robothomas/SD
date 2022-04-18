#include<iostream>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"

int main() {
  string s = "hello";
  char mem1[] = "0123456789";
  _put_tilde_terminated_string(s, mem1 + 2);
  cout << mem1 << endl;  // prints 01hello~89
  string s2 = _get_tilde_terminated_string(mem1 + 3);
  cout << s2 << endl;  // prints ello
}
