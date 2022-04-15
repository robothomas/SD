#ifndef __GRID_H__
#define __GRID_H__

struct GridLocation {
  int i, j;

  bool in_rectangle(int width, int height) const {
    return i >= 0 && i < width && j >= 0 && j < height; }
};

// Our main class stores the information in the grid.
class Grid {
  int width;
  int height;
  char *color;

  // the following function is only called from fill()
  void explore(GridLocation gl, char target, char replacement);

public:
  static const int num_colors = 6; // class variable
  Grid() : width(2), height(3) { // default constructor
    color = new char[6]{1, 2, 3, 4, 5, 0}; }
  Grid(int) : width(3), height(3) {  // another constructor
    color = new char[9]{1, 1, 2, 1, 2, 1, 1, 1, 1}; }
  ~Grid() { delete [] color; }

  int get_width() const {
    return width;
  }

  int get_height() const {
    return height;
  }

  char get_color(GridLocation gl) const;
  void set_color(GridLocation gl, char col);
  bool is_one_color() const;
  void randomize();
  void fill(GridLocation start, char new_col);
  void print() const;
  void read_from(const char *c);
  void write_to(char *c);
  int size_in_bytes();
};

#endif
