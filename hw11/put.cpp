#include<iostream>
#include"/usr/local/cs/cs251/show_mem.h"
using namespace std;

int main() { 
    char a = 'K';
    int b = 2;
    float c = 3.1, d = 3.14159;
    double e = 1.2345;

    char buffer[] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    buffer[1] = a;
    cout << buffer << endl;

    *(buffer + 3) = a;  // same as buffer[3] = a;
    cout << buffer << endl;

    _put_int(b, buffer + 7, 5);
    cout << buffer << endl;

    _put_float(c, buffer + 13, 3);
    cout << buffer << endl;

    _put_float(d, buffer + 18, 5);
    cout << buffer << endl;

    // testing requesting more space than needed
    _put_double(e, buffer + 24, 8);
    cout << buffer << endl;
}
