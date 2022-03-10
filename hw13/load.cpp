#include"/usr/local/cs/cs251/show_mem.h"

int main() {
  _read_image("small.ppm");

  _put_uchar(0, 0xff);  
  _put_uchar(1, 0x00);
  _put_uchar(2, 0xff);

  _print_image();
  _write_image("output.ppm");
}
