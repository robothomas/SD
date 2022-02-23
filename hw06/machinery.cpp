#include <iostream>
using namespace std;

struct Machinery {
    int num_blinking_lights;
    double price;

    void increase_price_by(double extra) {
        price += extra;
    }
};

int main() {
    Machinery GNE472 { 1024, 555444.33 };
    GNE472.increase_price_by(100000);
    cerr << GNE472.price << endl;

    return 0;
}