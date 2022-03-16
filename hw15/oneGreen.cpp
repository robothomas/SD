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
  _get_image_dimensions("small.ppm", width, height);


  Pixel **image;  // declare a variable 'image' of the correct type

  // dynamically allocate memory for the pointers to scanlines
  image = new Pixel*[height];

  // dynamically allocate memory for each of the scanlines, using a loop
  for (int i = 0; i < height; i++) {
    image[i] = new Pixel[width];
  }

  _read_image("small.ppm", reinterpret_cast<char **>(image), width, height);

  image[0][0].green = 255;  // set some pixel value manually

  _write_image("output.ppm", reinterpret_cast<char **>(image), width, height);

  // de-allocate the memory for each of the scanlines, using a loop
  for (int i = 0; i < height; i++) {
    delete image[i];
  }

  delete [] image; //  de-allocate the memory for the pointers to the scanlines
}