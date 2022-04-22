#include <iostream>
#include <cassert>
#include <random>
#include <functional>
#include "/usr/local/cs/cs251/show_mem.h"
#include "Grid.h"
using namespace std;

//const int Grid::num_colors = 6;

// write implementations for the Grid methods here

void Grid::set_color(GridLocation gl, char col) {
      color[gl.i + gl.j * width] = col;
    }

char Grid::get_color(GridLocation gl) const {
  if (gl.in_rectangle(width, height)) {
    //cerr << color[gl.i + gl.j * width] << endl;
    return color[gl.i + gl.j * width];

  } else {
    cerr << "WARNING: Not in the rectangle! Returning default value (0)" << endl;
    return 0;
  }
  
}

bool Grid::is_one_color() const {
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

void Grid::print() const {
  for (int j = 0; j < height; j++) {
      for (int i = 0; i < width; i++) {
        cerr << int(color[i + j*width]) << " ";
      }
      cerr << endl;
  }
  cerr << endl; // adds space after each grid is printed, makes it easier to tell apart individual grids
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

void Grid::read_from(const char *c) {
  width = _get_int(c, 2);
  //cerr << "width is " << width << endl;

  height = _get_int(c + 2, 2);
  //cerr << "height is " << height << endl;

  delete [] color;
  color = new char[width * height];
  //cerr << "deleted and recreated color with " << width * height << " chars" << endl;

  int skips = 0; // this is a way to make it so no part of color is left empty

  for (int i = 0; i < width * height; i++) {
    color[i] = _get_char(c + 4 + skips, 2);
    skips += 2;
    //cerr << "color[" << i << "] =" << color[i] << endl;
    /*if (c[4 + i] != char(' ')) {
      //cerr << i - skips << " " << 4 + i << endl;
      
      //cerr << "color[" << i - skips << "] = c[" << 4 + i << "]" << endl;
    } else {
      skips++;
      //cerr << "skips = " << skips << endl;
    }*/
  }
}

void Grid::write_to(char *c) const {
  _put_char(width, c, 2); 
  _put_char(height, c + 2, 2);

  for (int i = 0; color[i]; i += 2) {
    _put_char(color[i], c + 4 + i, 2);
  }

}

int Grid::size_in_bytes() {
  return 4 + 2*width*height;
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
