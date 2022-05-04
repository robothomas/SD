#include"/usr/local/cs/cs251/react.h"
#include"State.h"

const int num_colors = 6;
const int colors[6][3] = { {140,81,10}, {216,179,101}, {246,232,195}, {199,234,229}, {90,180,172}, {1,102,94} };
const int magnification = 20;

void make_button(int i)
{
    int r, g, b, r2, g2, b2;
    r = colors[i][0];
    g = colors[i][1];
    b = colors[i][2]; 
    r2 = r + 50;
    g2 = g + 50;
    b2 = b + 50;

    _add_yaml("button.yaml", {{"id", i}, {"r", r}, {"g", g}, {"b", b}}, {"r2", r2}, {"g2", g2}, {"b2", b2}});
}

void display(/*const*/ State &state) { 
  _add_yaml("flood_fill.yaml", {{"top_index", state.offset_for_status_text()}, {"grid_width", state.get_grid().get_width()}, {"grid_height", state.get_grid().get_height()}, {"magnification", magnification}, {"total_width", state.get_grid().get_width() * magnification}, {"total_height", state.get_grid().get_height() * magnification}, {"grid_offset", state.offset_for_raw_colors()}});
  if (state.get_show_buttons()) {
    for (int i = 0; i < num_colors; ++i) make_button(i);
  } else {
    _add_yaml("new_game_button.yaml", {{"new_game_index", _get_label_index("restart", state.label_offset)}});
  }
}

void render_grid_colors(const State &state) {
  const Grid &grid = state.get_grid();
  int index = state.offset_for_raw_colors();
  char *mem = _global_mem + index;
  GridLocation gl;
  for (gl.j = 0; gl.j < grid.get_height(); ++gl.j)
  for (gl.i = 0; gl.i < grid.get_width(); ++gl.i) {
    *mem++ = colors[ static_cast<int>(grid.get_color(gl)) ][0];
    *mem++ = colors[ static_cast<int>(grid.get_color(gl)) ][1];
    *mem++ = colors[ static_cast<int>(grid.get_color(gl)) ][2];
  }
}
