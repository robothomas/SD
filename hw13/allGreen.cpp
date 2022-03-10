#include"/usr/local/cs/cs251/show_mem.h"

int main() {
  int width, height;
  // tiny
  _read_image("tiny.ppm");
  _get_image_dimensions(width, height);
  
  for (int i = 0; i < 3 * width * height; i += 3) {
    _put_uchar(i, 0x00);  
    _put_uchar(i + 1, 0xff);
    _put_uchar(i + 2, 0x00);
  }

  _print_image();
  _write_image("output1.ppm");
  
  // small
  _read_image("small.ppm");
  _get_image_dimensions(width, height);
  
  for (int i = 0; i < 3 * width * height; i += 3) {
    _put_uchar(i, 0x00);  
    _put_uchar(i + 1, 0xff);
    _put_uchar(i + 2, 0x00);
  }

  _print_image();
  _write_image("output2.ppm");
}