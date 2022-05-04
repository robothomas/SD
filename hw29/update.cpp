#include "State.h"
#include <iostream>
using namespace std;

void State::update() {
    if (_received_event()) {
        ++num_moves;
    }

    for (int i = 0; i < 6; ++i) {
      if (_event_id_is("button_", i)) {
        handle_button_event(i);
      } 
    } 

    status_text = to_string(num_moves) + "/25 moves.";

}

void State::handle_button_event(int i) {
    cout << "Handling event for button " << i << endl;
    cout << "The grid before handling: " << endl;
    grid.print();
    grid.fill(GridLocation{0, 0}, i);
    cout << "After fill, {0,2} is " << grid.get_color(GridLocation{0, 2}) << endl;
}
