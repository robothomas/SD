#include <iostream>
#include <fstream>
using namespace std;

struct Pixel {
    public:
        // start them off at zero to avoid confusing errors
        unsigned char red = 0;
        unsigned char green = 0;
        unsigned char blue = 0;
};

class Image {
    private:
        unsigned int width;
        unsigned int height;
        unsigned short depth = 255; // would have made it an unsigned char, but it appears that messes up how it prints on the file
        Pixel **data;
    public:
        Image(unsigned int w, unsigned int h) {
            width = w;
            height = h;

            // allocates scanline pointers
            data = new Pixel*[height];

            // allocates an array of pixels for each scanline
            for (unsigned int i = 0; i < height; i++) {
                data[i] = new Pixel[width];
            }
        }

        Image(string filename) {
            ifstream f(filename);

            char formatName[3];
            f >> formatName; // gets name for the format

            f >> width >> height; // reads in width and height to the corrosponding variables

            f >> depth; // reads in the depth number puts it into depth
            f.get(); // for the newline char after depth

            // allocates scanline pointers
            data = new Pixel*[height];

            // allocates an array of pixels for each scanline
            for (unsigned int i = 0; i < height; i++) {
                data[i] = new Pixel[width];
            }

            int bytes_per_scanline = width * 3; // width of image * 3 chars in a Pixel (which is 3 bytes)

            // reads in data into the prepared structure
            for (unsigned int i = 0; i < height; i++) {
                f.read(reinterpret_cast<char *>(data[i]), bytes_per_scanline);
            }

        }

        ~Image() {
            // de-allocate the memory for each of the scanlines, using a loop
            for (unsigned int i = 0; i < height; i++) {
                delete data[i];
            }

            delete [] data; //  de-allocate the memory for the pointers to the scanlines
        }

        unsigned int getWidth() {
            return width;
        }

        unsigned int getHeight() {
            return height;
        }

        void print() {
            ofstream f("output.ppm");

            f << "P6" << endl;
            f << width << " " << height << endl;
            f << depth << endl;

            int bytes_per_scanline = width * 3; // width of image * 3 chars in a Pixel

            for (unsigned int i = 0; i < height; i++) {
                f.write(reinterpret_cast<char *>(data[i]), bytes_per_scanline);
            }

            f.close();
            
            cout << "The image was printed to output.ppm" << endl;
        }
};

int main() {
    Image myimg("tiny.ppm");
    myimg.print();
}