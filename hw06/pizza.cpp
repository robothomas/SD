#include <iostream>
using namespace std;

struct Town {
    double total_pizza;
    int num_inhabitants;
    int num_students;

    double per_capita() {
        double res = total_pizza/num_inhabitants;
        return res;
    }

    double pizza_for_students() {
        double res = total_pizza/num_students;
        return res;
    }

    void eat_more() {
        total_pizza *= 1.1;
    }

    void show_change() {
        cerr << "Before: " << pizza_for_students();
        eat_more();
        cerr << "After: " << pizza_for_students();
    }

};

int main() {
    Town northfield {500000.1, 20007, 5000};
    Town faribault {400000, 23750, 1000};
    cerr << northfield.per_capita() << endl;  // prints 24.9913
    cerr << faribault.per_capita() << endl;  // prints 16.8421

}