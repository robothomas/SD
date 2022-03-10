#include"/usr/local/cs/cs251/show_mem.h"

int main() {
  int width, height;
  // tiny
  _read_image("tiny.ppm");
  _get_image_dimensions(width, height);
  
  for (int i = 0; i < 3 * width * height; i += 3) {
    unsigned char r = _get_uchar(i);
    unsigned char g = _get_uchar(i + 1);
    unsigned char b = _get_uchar(i + 2);
    unsigned char average = (r + g + b) / 3;

    _put_uchar(i, average);  
    _put_uchar(i + 1, average);
    _put_uchar(i + 2, average);
  }

  _print_image();
  _write_image("output1.ppm");
  
  // small
  _read_image("small.ppm");
  _get_image_dimensions(width, height);
  
  for (int i = 0; i < 3 * width * height; i += 3) {
    unsigned char r = _get_uchar(i);
    unsigned char g = _get_uchar(i + 1);
    unsigned char b = _get_uchar(i + 2);
    unsigned char average = (r + g + b) / 3;

    _put_uchar(i, average);  
    _put_uchar(i + 1, average);
    _put_uchar(i + 2, average);
  }

  _print_image();
  _write_image("output2.ppm");
}