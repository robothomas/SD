#include<iostream>
using namespace std;

class Animal {
  char *name;
  float weight;

  void init(const char *n, float w) {
    int len = 0;
    while( n[len] ) { 
      ++len; 
    }
    name = new char[len+1];
    for ( int i = 0; i < len+1; ++i ) {
      name[i] = n[i];
    }
    weight = w;
  }

public:
  Animal(const char *n, float w) { 
    init(n, w); 
  }

  Animal(const Animal &a) { 
    init(a.name, a.weight); 
  }

  ~Animal() { 
    delete [] name;
    name = 0; 
  }

  Animal operator=(const Animal &secondAnimal) {
    delete [] name;
    init(secondAnimal.name, secondAnimal.weight);

    return *this;
  }

  float current() const { 
    return weight; 
  }

  float growFast(float s) { 
    weight *= s; 
    return weight; 
  }

  virtual void display() {
    cerr << "name is " << name << " and weight is " << weight << endl;
  }
};

class HouseCat : public Animal {
  double whisker_len;

public:
  HouseCat(double wl) : Animal("cat", 8) { 
    whisker_len = wl; 
  }

  HouseCat(const HouseCat &hc) : Animal(hc) { 
    whisker_len = hc.whisker_len; 
  }

  ~HouseCat() {}  // this is really not necessary!

  int getLen() { 
    return whisker_len; 
  }

  void trim() { 
    whisker_len /= 2; 
  }

  void display() {
    cerr << "whisker length is " << whisker_len << endl;
  }
};

int main(){
  HouseCat socks(12), waldo(socks);
  socks.display();
  waldo.display();
  waldo.trim();
  waldo.display();
  waldo.trim();
  waldo.display();
  waldo.trim();
  waldo.display();
  std::cerr << waldo.getLen() << std::endl;  // note return type!
}
