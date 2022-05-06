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
    Pencil mechPencil;
    WritingUtencil *pencil = &mechPencil;

    WritingUtencil pen;

    pen.write();
    pen.display();
    
    pencil->write();
    pencil->display();

    //pencil.erase();
    //pencil.display();

}