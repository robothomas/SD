#include <iostream>
using namespace std;

class Class1 {
    private:
        int count = 0;
        bool working = false;

    public:
        void init(int theCount, bool operable) {
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
    Class1 test1, test2;
    test1.init(10, true);
    test2.init(20, false);

    test1.print();
    test2.print();
}