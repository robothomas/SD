#include<fstream>
#include<string.h>
#include <iostream>
#include <string>
using namespace std;

class User {
    private:
        string name;
        double cash;

    public:
        int id; // position in array, makes it easier to search for the user

        void init(int id, string username = "NA", double money = 0.) {
            name = username;
            cash = money;
        }

        void deposit(double money) {
            cash += money;
        }

        void withdraw(double money) {
            cash -= money;
        }

        /**
         * Information on the client
        */
        void info() {
            cout << name << ": $" << cash << endl;
        }

        string getName() {
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
            //numUsers = estimatedNumUsers;
        }

        /**
         * Lists all of the current users in the database
        */
        void list() {
            for (int i = 0; i < numUsers; i++) {
                users[i].info();
            }
        }

        void addUser() {
            string newUser = ""; 
            cout << "What is the name of the user?" << endl;
            cin >> newUser;

            users[numUsers].init(numUsers, newUser); // assigns last slot to new user 
            numUsers++;
        }

        void askForTransaction() {
            int payer = numUsers + 1; // added 1 to total users to make it so no user would have this ID

            while (payer >= numUsers + 1) {
                cout << "ID of payer" << endl;
                cin >> payer;

                if (payer >= numUsers + 1) {
                    cout << "Invalid. Try again." << endl;
                }
            }

            int receiver = numUsers + 1; // added 1 to total users to make it so no user would have this ID

            while (receiver >= numUsers + 1) {
                cout << "ID of receiver" << endl;
                cin >> payer;

                if (receiver >= numUsers + 1) {
                    cout << "Invalid. Try again." << endl;
                }
            }

            double moneyCharged = 0;

            while (moneyCharged == 0) {
                cout << "Transaction Amount (nonzero)" << endl;
                cin >> moneyCharged;
            }

            addTransaction(users[payer], users[receiver], moneyCharged);
            
        }

        void addTransaction(User payer, User receiver, double charge) {
            users[payer.id].withdraw(charge);
            users[receiver.id].deposit(charge);
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
                    //addTransaction();
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
    Bank northfieldBank(10);
    cout << "Welcome to an example bank registry." << endl; 
    northfieldBank.askForInput(); 
    return 0;
}