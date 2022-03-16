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
  _get_image_dimensions("big.ppm", width, height);


  Pixel **image;  // declare a variable 'image' of the correct type

  // dynamically allocate memory for the pointers to scanlines
  image = new Pixel*[height];

  // dynamically allocate memory for each of the scanlines, using a loop
  for (int i = 0; i < height; i++) {
    image[i] = new Pixel[width];
  }

  _read_image("big.ppm", reinterpret_cast<char **>(image), width, height);

  // doubling all green values
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        int average = (image[i][j].red + image[i][j].green + image[i][j].blue) / 3;

        image[i][j].red = average;
        image[i][j].green = average;
        image[i][j].blue = average;
    }
  }

  _write_image("output.ppm", reinterpret_cast<char **>(image), width, height);

  // de-allocate the memory for each of the scanlines, using a loop
  for (int i = 0; i < height; i++) {
    delete image[i];
  }

  delete [] image; //  de-allocate the memory for the pointers to the scanlines
}