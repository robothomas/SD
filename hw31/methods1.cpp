#include <iostream>
#include <string>
using namespace std;

class WritingUtencil {
    protected:
        string writtenWord;
    public:
        void write() {
            writtenWord = "Where art thou Romeo?";
        }

        void display() {
            cout << writtenWord << endl;
        }

};

class Pencil : public WritingUtencil {
    public:
        void erase() {
            writtenWord = "Johnny, you get a 0/10.";
        }

        void write() {
            writtenWord = "Johnny, you get a 0/10. Sorry about that.";
        }

        void write(int) {
            WritingUtencil::write();
        }
};

int main() {
    WritingUtencil pen;
    Pencil mechPencil;
    
    pen.write();
    pen.display();

    mechPencil.write();
    mechPencil.display();

    mechPencil.erase();
    mechPencil.display();

    mechPencil.write(2);
    mechPencil.display();
}