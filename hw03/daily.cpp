#include <iostream>
using namespace std;

/**
 * All square functions below change the original variable value as well as returning that value. Did this mostly for fun, not needed though
*/

int square(int &num) {
    num *= num;
    return num;
}

float square(float &num) {
    num *= num;
    return num;
}

double square(double &num) {
    num *= num;
    return num;
}


/**
 * This is considerablly more useful, allowing us to square, cube, or take something to the power of 20 if it can fit within the range of the double
*/
double exponential(double num, int exponent) {
    double multiplicationAccumulated = num;

    for (int i = 1; i < exponent; i++) {
        multiplicationAccumulated *= num;
    }

    return multiplicationAccumulated;
}



int main() {
    int i = 2;
    float j = -1.1;
    double k = 3.1415;

    cout << "i is " << square(i) << endl;
    cout << "j is " << square(j) << endl;
    cout << "k is " << square(k) << endl;

    cout << "2 to the power of four is " << exponential(2., 4) << endl;

    return 0;
}