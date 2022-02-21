#include <iostream>
using namespace std;

class Class2 {
    private:
        int count = 0;
        bool working = false;

    public:
        Class2(int theCount, bool operable) {
            count = theCount;
            working = operable;
        }

        void print() {
            cout << "the count is " << count << " ";
            if (working) {
                cout << "and it is specified to work" << endl;
            } else {
                cout << "and it is specified to NOT work" << endl;
            }
        }
};

int main() {
    Class2 test1(10, true), test2(20, false);

    test1.print();
    test2.print();
}