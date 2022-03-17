#include <iostream>
using namespace std;

class Image0 {
    private:
        unsigned int width;
        unsigned int height;
    public:
        Image0(unsigned int w, unsigned int h) {
            width = w;
            height = h;
        }

        unsigned int getWidth() {
            return width;
        }

        unsigned int getHeight() {
            return height;
        }
};

int main() {
    Image0 image1(50, 50);
    Image0 image2(100, 100);
    cout << "image1 width is " << image1.getWidth() << " and height is " << image1.getHeight() << endl;
    cout << "image2 width is " << image2.getWidth() << " and height is " << image2.getHeight() << endl;
}