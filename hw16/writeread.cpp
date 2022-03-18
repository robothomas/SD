#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // writer
    ofstream f("nums.txt");
    f << 1 << " " << 2 << endl;
    f.close();

    // reader
    ifstream g("nums.txt");
    int i, j;

    g >> i >> j;
    g.close();
    cerr << "i is " << i << " and j is " << j << endl;
}
