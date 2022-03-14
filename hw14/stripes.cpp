#include "/usr/local/cs/cs251/show_mem.h"
#include <iostream>
using namespace std;

int main() {
    int width, height;
    _read_image("small.ppm");
    _get_image_dimensions(width, height);
     
    for (int i = 0; i < 3 * width; i += 3) {
        unsigned char r = _get_uchar(i);
        unsigned char g = _get_uchar(i + 1);
        unsigned char b = _get_uchar(i + 2);

        // loop starts at 1 because 0 would imply the row from which we are copying from, which does not make sense
        for (int j = 1; j < height; j++) {
            /* 3*width*j represents which row the number is put in. 3*width is the length between rows, and j is the specified row that the rgb is copied
             * to, and meanwhile, the + 0, + 1, and + 2 specifies whether a red, green, or blue value is being changed. 
            */
            _put_uchar(i + 3*width*j, r);  
            _put_uchar(i + 3*width*j + 1, g);
            _put_uchar(i + 3*width*j + 2, b);
        }
    }

    _print_image();
    _write_image("output.ppm");
}