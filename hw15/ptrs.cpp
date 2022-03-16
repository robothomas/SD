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
  int width, height;
  width = 16;
  height = 16;

  Pixel **image;  // declare a variable 'image' of the correct type

  // dynamically allocate memory for the pointers to scanlines
  image = new Pixel*[height];

  // dynamically allocate memory for each of the scanlines, using a loop
  for (int i = 0; i < height; i++) {
    image[i] = new Pixel[width];
  }

  // changing pixel colors (exercise 5)
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j].red = (j % 5) * 50;
      image[i][j].green = (i % 5) * 50;
      image[i][j].blue = (i * j) % 256;
    }
  }

  //image[0][1].red = 255;  // set some pixel value manually

  //std::cerr << image[0][1].green << "\n";  // should print 'a'

  _write_image("pattern.ppm", reinterpret_cast<char **>(image), width, height);

  // de-allocate the memory for each of the scanlines, using a loop
  for (int i = 0; i < height; i++) {
    delete image[i];
  }

  delete [] image; //  de-allocate the memory for the pointers to the scanlines
}
