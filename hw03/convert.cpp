#include <iostream>
using namespace std;

float convert_to_celsius(float fahrenheit) {
    return (5./9.)*(fahrenheit - 32.);
}

int main() {
    if (convert_to_celsius(32.) == 0) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    if (convert_to_celsius(-40.) == -40) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}