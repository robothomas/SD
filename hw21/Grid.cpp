#include<iostream>
#include<cassert>
#include<random>
#include<functional>
using namespace std;

struct GridLocation {
    int i, j;

    bool in_rectangle(int width, int height) const {
        return i >= 0 && i < width && j >= 0 && j < height; 
    }
};

// Our main class stores the information in the grid.
class Grid {
  int width;
  int height;
  char *color;

  // the following function is only called from fill()
  void explore(GridLocation gl, char target, char replacement);

  public:
    static const int num_colors = 6; // class variable - added the = 6 so that it works properly (and since it is const, so it cannot be changed)

    Grid() : width(2), height(3) { // default constructor
      color = new char[6]{1, 2, 3, 4, 5, 0}; 
    }

    Grid(int) : width(3), height(3) {  // another constructor
      color = new char[9]{1, 1, 2, 1, 2, 1, 1, 1, 1}; 
    }

    ~Grid() { delete [] color; }

    int get_width() const;  // {...} fill in the function here
    int get_height() const;  // {...} fill in the function here
    char get_color(GridLocation gl) const;
    void set_color(GridLocation gl, char col) {
      color[gl.i + gl.j * width] = col;
    }

    bool is_one_color() const {
      char firstColor = color[0];

      for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
          if (color[i + j*width] != firstColor) {
            return false;
          }
        }
      }
      
      return true;
    }
    void randomize();
    void fill(GridLocation start, char new_col);
    void print() const {
      for (int j = 0; j < height; j++) {
          for (int i = 0; i < width; i++) {
            cerr << int(color[i + j*width]) << " ";
          }
          cerr << endl;
      }
      cerr << endl; // adds space after each grid is printed, makes it easier to tell apart individual grids
    }
};

// create the class variable (Grid::num_colors) here
  // How? For one, it is a constant. Also, the compliler complains that it is already defined (which appears to be true - line 25). So, why then? 
// here's one way to create a random number between zero and one
double random_number() {
  static random_device rd;  
  static mt19937 rng(rd());
  static uniform_real_distribution<double> distribution(0, 1);
  double res = distribution(rng);
  return res;
}

// write implementations for the Grid methods here

char Grid::get_color(GridLocation gl) const {
  if (gl.in_rectangle(width, height)) {
    return color[gl.i + gl.j * width];

  } else {
    cerr << "WARNING: Not in the rectangle! Returning default value (0)" << endl;
    return 0;
  }
  
}

void Grid::randomize() {
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      GridLocation gl{i, j};
      set_color(gl, num_colors * random_number());
    }
  }
}

void Grid::fill(GridLocation start, char new_col) {
  char current_col = get_color(start);
  Grid::explore(start, current_col, new_col);
}

void Grid::explore(GridLocation gl, char target, char replacement) {
  
  if (get_color(gl) == replacement) {
    //cerr << "Did not change " << gl.i << " " << gl.j << endl;
    return;

  } 
  
  if (get_color(gl) == target) {
    set_color(gl, replacement);
    //cerr << "Set color " << gl.i << " " << gl.j << endl;
  }

  GridLocation left{gl.i - 1, gl.j}, right{gl.i + 1, gl.j}, up{gl.i, gl.j - 1}, down{gl.i, gl.j + 1};

  if (left.in_rectangle(width, height)) {
    //cerr << gl.i << " " << gl.j << " calling left" << endl;
    explore(left, target, replacement);
  }

  if (right.in_rectangle(width, height)) {
    //cerr << gl.i << " " << gl.j << " calling right" << endl;
    explore(right, target, replacement);
  }

  if (up.in_rectangle(width, height)) {
    //cerr << gl.i << " " << gl.j << " calling up" << endl;
    explore(up, target, replacement);
  }

  if (down.in_rectangle(width, height)) {
    //cerr << gl.i << " " << gl.j << " calling down" << endl;
    explore(down, target, replacement);
  }

}

void test_in_rectangle() {
  GridLocation gl{3, 5};
  assert(gl.in_rectangle(100, 100));
  assert(!gl.in_rectangle(3, 6));
  assert(!gl.in_rectangle(4, 5));
}

void test_set() {
  Grid g;
  GridLocation gl{1, 2};
  g.set_color(gl, 9);
  assert(g.get_color(gl) == 9);
  g.print();
};

void test_is_one_color() {
  Grid g;
  assert(g.is_one_color() == false);
}

void test_randomize() {
  Grid g;
  g.randomize();
  g.print();
}

void test_fill() {
  Grid g(3);
  g.print();
  g.fill(GridLocation{0, 0}, 3);
  assert(g.get_color(GridLocation{2, 1}) == 3);
  g.print();
}

int main() {  // uncomment these lines one at a time
  test_in_rectangle();
  test_set();
  test_is_one_color();
  test_randomize();
  test_fill();
}
