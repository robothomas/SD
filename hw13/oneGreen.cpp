#include"/usr/local/cs/cs251/show_mem.h"

int main() {
  // tiny
  _read_image("tiny.ppm");

  _put_uchar(0, 0x00);  
  _put_uchar(1, 0xff);
  _put_uchar(2, 0x00);

  _print_image();
  _write_image("output1.ppm");
  
  // small
  _read_image("small.ppm");

  _put_uchar(0, 0x00);  
  _put_uchar(1, 0xff);
  _put_uchar(2, 0x00);

  _print_image();
  _write_image("output2.ppm");
}