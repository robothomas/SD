#include<fstream>
#include<iostream>

int main() {
  std::ifstream g("in.txt");
  int i, j;

  g >> i >> j;
  g.close();
  std::cerr << "i is " << i << " and j is " << j << std::endl;
}
