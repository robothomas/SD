#include <iostream>
#include <string>
using namespace std;

class WritingUtencil {
    protected:
        string writtenWord;
    public:
        virtual void write() {
            writtenWord = "Where art thou Romeo?";
        }

        virtual void display() {
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

    cout << "write + display (both virtual) from base class" << endl;
    pen.write();
    pen.display();
    
    cout << "write + display from pointer expecting base class with derived class pointed to" << endl;
    pencil->write();
    pencil->display();

    //pencil.erase();
    //pencil.display();

}