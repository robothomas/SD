#include <iostream>
#include <chrono>
using namespace std;

int count = 0;
string args[1000];

void addItem() {
    cout << "Add an item\n";
    cin >> args[count];
    count++;  
}

void addAnotherItem() {
    char continuity = 'N';

    cout << "Type N if you are finished, Y if you wish to continue\n";
    cin >> continuity;

    if (continuity == 'Y') {
        cout << "Item " << count + 1 << endl;
        addItem();
    } else if (continuity == 'N') {
        cout << "List is finished\n";
    } else {
        cout << "ERROR: response is not Y or N. Repeating prompt\n";
        addAnotherItem();
    }
}

void findRandom() {
    int random = chrono::system_clock::now().time_since_epoch().count() % count;
    cout << "Random response: "<< args[random] << endl;
}

void randomizeAgain() {
    char continuity = 'N';

    cout << "Want to randomly choose another item?\n";
    cout << "Type Y for another randomization, and type N to stop\n";

    if (continuity == 'Y') {
        findRandom();
    } else if (continuity == 'N') {
        cout << "Thank you for your time. Program finished.\n";
    } else {
        cout << "ERROR: response is not Y or N. Repeating prompt\n";
        randomizeAgain();
    }
}

int main() {
    cout << "This program will randomly choose the items you add to a list\n";

    addItem();
    // turns addItem() into a recursive function, allowing the user to add as many items as they like (up to 1000)
    addAnotherItem();

    findRandom();
    // turns randomizeAgain() into a recursive function, allowing the user to randomize the list as much as they want
    randomizeAgain();

    return 0;
}