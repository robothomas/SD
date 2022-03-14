#include "/usr/local/cs/cs251/show_mem.h"
#include <iostream>
using namespace std;

void quarterRect(string image, float top, float left) {
    int width, height;

    _read_image(image);
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
}

int main() {
    
    // tiny

    float rectPattern = 0;
    for (float i = 0; i < 1; i += 0.25) {
        for (j = rectPattern; j <= 1; j += .50) {
            quarterRect("tiny.ppm", i, j)
        }

        if (rectPattern == 0) {
            rectPattern = .25;
        } else {
            rectPattern = 0;
        }
    }
    /*
    quarterRect("tiny.ppm", 0, 0);
    quarterRect("tiny.ppm", 0, 0.75);
    quarterRect("tiny.ppm", 0.25, 0);
    quarterRect("tiny.ppm", 0.75, 0);
    */

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