#include<iostream>

void f(char *s) {
  s[0] = '>';
  s[1] = ' ';
  std::cerr << s << std::endl;
  delete [] s;
}

int main() {
  char *t = new char[4];
  t[0] = '_';
  t[1] = '_';
  t[2] = ':';
  t[3] = 0;

  std::cerr << t << std::endl;
  f(t);
  delete [] t;
}
