#include"/usr/local/cs/cs251/show_mem.h"

int main() {
  _read_image("big.ppm");

  int width, height;
  _get_image_dimensions(width, height);

  _put_unsigned_char(3*width*height - 3, 0xff);
  _put_unsigned_char(3*width*height - 2, 0x00);
  _put_unsigned_char(3*width*height - 1, 0xff);

  //_print_image();
  _write_image("output.ppm");
}
