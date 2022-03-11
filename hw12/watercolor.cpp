#include<iostream>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"

class Watercolor {
  double width, height;
  char *subject;
public:
  Watercolor(float w=3, float h=4);
  ~Watercolor() { delete [] subject; }
  double getWidth() { return width; }
  void print() {
    cout << width << "x" << height << " " << subject << endl;
  }
  void read_from(const char *mem) {
    int len;

    width = _get_double(mem, 5);
    height = _get_double(mem + 5, 5);

    for (len = 0; mem[len + 10] != '~'; len++) {} // accumulates length until ~ is found

    delete [] subject;
    subject = new char[len]; // allocates memory based on length

    for (int i = 0; mem[i + 10] != '~'; i++) {
        subject[i] = mem[i + 10]; // gets characters put into the new subject string, one at a time
    }
  }
  void write_to(char *mem) const {
    _put_double(width, mem, 5);
    _put_double(height, mem + 5, 5);

    int memorySlot;

    for (int i = 0; subject[i] != '\0'; i++) {
        memorySlot = i + 10;

        mem[memorySlot] = subject[i]; // adds each char from the subject into memory

        if (subject[i + 1] == '\0') {
            // cout << "added tilli" << endl;
            mem[memorySlot + 1] = '~'; // if the next i is the null byte, put '~' in that spot
        }
    }

    //mem[memorySlot] = '~'; // puts '~' in for null byte - segmentation fault
  }

  int size() const {
    int len;
    for (len = 0; subject[len] == '\0'; len++) {} // accumulates to figure out length of subject array

    return len + 10; // returns that length as the total size
  }
};

Watercolor::Watercolor(float w, float h)
{
  width=w;
  height=h;
  subject=new char[4];
  subject[0]='s'; subject[1]='k'; subject[2]='y'; subject[3]='\0';
}

int main()
{
  Watercolor norman(18, 19), rockwell(20);
  rockwell.print();

  char buffer[] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  norman.write_to(buffer + 1);
  rockwell.write_to(buffer + 1 + norman.size());
  cout << buffer << endl;

  rockwell.read_from(buffer + 1);
  norman.read_from(buffer + 1 + rockwell.size());
  norman.print();
}
