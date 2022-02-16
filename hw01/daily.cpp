#include <iostream>
#include <string>
using namespace std;

bool checkEven(int num) {
    bool isEven = false;
    int remainder = num % 2;

    if (remainder == 0) {
        isEven =  true;
    } else {
        isEven = false;
    }
    
    return isEven;
};

 void result(int testNum) {
    if (checkEven(testNum)) {
        cout << testNum << " is even\n";
    } else {
        cout << testNum << " is odd\n";
    }
}

int main() {
    result(5);
    result(1000);
    result(-134);
    result(-21);

    return 0;
}