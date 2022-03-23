#include<iostream>
#include<chrono>  // used for get_current_time()
#include<sys/stat.h>  // used for get_current_time()

long fake_time = 1;

long get_current_time() {
  long ms;
  if (0) {  // actual time
    using namespace std::chrono;
    ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count();
  } else {
    ms = fake_time++;
  }
  return ms;
}

class Food {
protected:
  bool takeout;
  long order_time;

  public:
    Food(bool t) : takeout(t), order_time() { 
      order_time = get_current_time(); 
    }

    Food(bool t, long time) : takeout(t), order_time(time) {}

    void print_takeout() { 
      std::cerr << " takeout " << takeout << std::endl; 
    }
};

class Nachos : public Food {
  public:
    Nachos(bool t) : Food(t) { }

    void print_order() { 
      std::cerr << "Nachos: "; 
      print_takeout(); 
    }
};

class Quesadilla : public Food {
  bool is_half, just_cheese;

  public:
    Quesadilla(bool t, bool h, bool c, long time) : Food(t, time), is_half(h), just_cheese(c) {}

    void print_order() { 
      std::cerr << "Quesadilla:  is_half " << is_half;
      std::cerr << " just_cheese " << just_cheese; 
      std::cerr << " order time " << order_time; // added in to test the new constructor
      print_takeout(); 
    }
};

class Chicken_Quesadilla : public Quesadilla {
  public:
    Chicken_Quesadilla(bool t, bool h, bool c, long time) : Quesadilla(t, h, c, time) {}
};


class Ice_Cream : public Food {
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist

public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }

  void print_order() { 
    std::cerr << "Ice Cream:  kind " << kind; 
    print_takeout(); 
  }
};

int main() {
  Chicken_Quesadilla q1(false, false, false, 10);
  q1.print_order();
}
