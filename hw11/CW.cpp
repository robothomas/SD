#include<iostream>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"

class ConeWeights {
  int num_cones;
  float *data;
  int sizeAllocated = 0;
public:
  ConeWeights(int n) {  
    num_cones = n;  
    data = new float[num_cones];
  }

  ~ConeWeights() {  
    delete [] data; 
  }

  void assign_cone_weight(int i, float w) { 
    data[i] = w;  
  }
  
  void display() {  
    cout << num_cones << ":";
    for (int i = 0; i < num_cones; ++i)
       cout << " " << data[i];
    cout << endl;
  } 

  void read_from(const char *mem) {
    delete [] data;
    num_cones = 0;

    // finds number of cones in the char*
    for (int i = 0; mem[i]; i++) {
        if (mem[i] == ' ') {
            num_cones++; // adds a new cone each time a space is found
        }
    }

    data = new float[num_cones]; // allocates memory for all of the found cones

    int num_bytes_float = 0; // accumulator to find number of bytes to allocate for this integer
    int currentCone = 0; // used to allocate weight to the correct cone

    // assigns all of the data from read-in array into the float array.
    for (int i = 0; currentCone < num_cones; i++) {
        if (mem[i] == ' ') {
            // goes to current position, subtracts how big the int is, and assigns that to the current cone. The currentCone is then switched to the next one.
            data[currentCone++] = _get_float(mem + i - num_bytes_float, num_bytes_float); 
            num_bytes_float = 0; // resets the bytes to zero
        } else {
            num_bytes_float++; // adds a byte if there isn't a space. No need to include the space when getting the float.
        }
    } 
  }

  void write_to(char *mem) /*const*/ {
    int amountAllocated = 0;

    for (int i = 0; i < num_cones; i++) {
        string cone = to_string(data[i]); // converts to given cone attribute to a string
        
        int num_bytes = cone.size(); // finds size of string (for converted float), uses that as number of bytes that need to be allocated

        _put_float(data[i], mem + amountAllocated, num_bytes); 
        amountAllocated += num_bytes; // adds these bytes to the total number of allocated bytes

        _put_char(' ', mem + amountAllocated++, 1); // adds a space after the float, reflects it in amountAllocated afterwards
    }

    sizeAllocated += amountAllocated; // adds amount allocated to the total sizeAllocated
  }

  int size() const {
    return sizeAllocated;
  }

};

int main() { 
  ConeWeights c1(3), c2(4);
  c1.assign_cone_weight(0, 125.5);
  c1.assign_cone_weight(1, 25.5);
  c1.assign_cone_weight(2, 5.5);
  c1.display();

  char buffer[] = "~~~~~~~~~~~~~~~~~~~~~~~~~";
  c1.write_to(buffer + 1);
  cout << buffer << endl;

  c2.read_from(buffer + 1);
  c2.display();
  cout << c2.size() << endl;
}
