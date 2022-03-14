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

        _put_uchar(i + 3*width, r);  
        _put_uchar(i + 3*width + 1, g);
        _put_uchar(i + 3*width + 2, b);
    }

    _print_image();
    _write_image("output.ppm");
}