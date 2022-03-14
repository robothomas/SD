#include "/usr/local/cs/cs251/show_mem.h"
#include <iostream>
using namespace std;

int main() {
    int width, height;

    // tiny
    _read_image("tiny.ppm");
    _get_image_dimensions(width, height);

    cout << "i = " << (3 * width) / 4 << " and j = " << height / 4 + 1 << endl;
    
    for (int i = 0; i < (3 * width) / 4; i += 3) { 
        for (int j = 0; j < (height / 4) + 1; j++) { // added 1 to make it actually go to the quarter of height that is computed
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

    cout << "i = " << (3 * width) / 4 << " and j = " << height / 4 + 1 << endl;
    
    for (int i = 0; i < (3 * width) / 4; i += 3) { 
        for (int j = 0; j < (height / 4) + 1; j++) { // added 1 to make it actually go to the quarter of height that is computed
            _put_uchar(i + 3*width*j, 0xff);  
            _put_uchar(i + 3*width*j + 1, 0x00);
            _put_uchar(i + 3*width*j + 2, 0xff);
        }
    }

    _print_image();
    _write_image("output2.ppm");
}