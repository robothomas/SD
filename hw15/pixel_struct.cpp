#include <iostream>
#include "/usr/local/cs/cs251/show_mem.h"

struct Pixel {
    public:
        // start them off at zero to avoid confusing errors
        unsigned char red = 0;
        unsigned char green = 0;
        unsigned char blue = 0;
};

int main() {
  Pixel p1;
  p1.red = p1.green = p1.blue = 17;
  int n = p1.red;  // convert to int, prior to printing
  std::cerr << n << "\n";
}
