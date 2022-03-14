#include "/usr/local/cs/cs251/show_mem.h"
#include <iostream>
using namespace std;

int main() {
    int width, height;

    float top = 0.25;
    float left = 0.25;

    // tiny
    _read_image("tiny.ppm");
    _get_image_dimensions(width, height);
    
    // left*width moves square to the specified percentage to the side on the screen, + 1 allows it to start on the correct part of the pixel
    for (int i = left*3*width + 1; i < left*(3*width) + (3*width) / 4; i += 3) { 
        // top*height moves square to the specified percentage down the screen
        for (int j = top*height; j < top*height + (height / 4) + 1; j++) { // added 1 to make it actually go to the quarter of height that is computed
            _put_uchar(i + 3*width*j, 0xff);  
            _put_uchar(i + 3*width*j + 1, 0x00);
            _put_uchar(i + 3*width*j + 2, 0xff);
        }
    }

    _print_image();
    _write_image("output1.ppm");

    // small
    _read_image("small.ppm");
    _get_image_dimensions(width, height);
    
    // left*width moves square to the specified percentage to the side on the screen, + 1 allows it to start on the correct part of the pixel
    for (int i = left*3*width + 1; i < left*(3*width) + (3*width) / 4; i += 3) { 
        for (int j = top*height; j < top*height + (height / 4) + 1; j++) { // added 1 to make it actually go to the quarter of height that is computed
            _put_uchar(i + 3*width*j + 0, 0xff);  
            _put_uchar(i + 3*width*j + 1, 0x00);
            _put_uchar(i + 3*width*j + 2, 0xff);
        }
    }

    _print_image();
    _write_image("output2.ppm");
}