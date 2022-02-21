#include <iostream>
#include <string>
using namespace std;

class User {
    private:
        string name;
        float cash;

    public:
        void init(string username = "NA", float money = 0.) {
            name = username;
            cash = money;
        }

        string name() {
            return name;
        }
};

class Bank {
    private:
        User *users;
        int numUsers = 0;
    public:
        Bank(int estimatedNumUsers) {
            users = new User[estimatedNumUsers];
            numUsers = estimatedNumUsers;
        }

        void list() {
            for (int i = 0; i < numUsers; i++) {
                cout << users[i].name << endl;
            }
        }

        void addUser(string newUser, float money) {
            users[numUsers++].init(newUser, money); // assigns last slot to user, then ups the overall number of users
        }

        void addTransaction() {

        }

        void askForInput() {
            char typeOfInput = 'N';
            cout << "Type U for a list of users, A to add a user, T to add a transaction, or X to terminate the program" << endl;
            cin >> typeOfInput;
            switch (typeOfInput) {
                case 'U':
                    list();
                    askForInput();
                    break;
                case 'A':
                    addUser();
                    askForInput();
                    break;
                case 'T':
                    addTransaction();
                    askForInput();
                    break;
                case 'X':
                    // does nothing, but does not recurse, so the loop ends.
                    break;
                default:
                    cout << "Invalid input.\n";
                    askForInput();
                    break;
            }
        }
};



int main() {
    cout << "Welcome to an example bank registry." << endl; 
    return 0;
}