#include<fstream>

int main() {
  std::ofstream f("output.txt");
  f << "Hello world!" << std::endl;
  f.close();
}
