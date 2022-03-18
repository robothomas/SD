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

        void init(int identification, string username = "NA", double money = 0.) {
            id = identification;
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
            cout << name << " (ID " << id << ')' << ": $" << cash << endl;
        }

        string getName() {
            return name;
        }

        double getCurrentBalance() {
            return cash;
        }

};

class Bank {
    private:
        string name;
        User *users;
        int numUsers = 0;

    public:
        Bank(string bankName, int estimatedNumUsers) {
            name = bankName;
            users = new User[estimatedNumUsers];
            //numUsers = estimatedNumUsers;
        }

        Bank(string filename) {
            ifstream f(filename);

            f >> name;
            f >> numUsers;

            users = new User[numUsers + 20]; // the "+ 20" is extra room to add users within a given session.

            for (int i = 0; i < numUsers; i++) {
                int id;
                f >> id;

                string name;
                f >> name;

                double balance;
                f >> balance;

                users[i].init(id, name, balance);
            }

            f.close();

        }

        ~Bank() {
            copyRegistry();

            delete [] users;
        }

        // copies all of the current bank and user data into a permanant file
        void copyRegistry() {
            ofstream f(name + ".txt");

            f << name << endl;
            f << numUsers << endl;

            // prints all of the user information in such a fashion that it is easy to read back in by the constructor
            for (int i = 0; i < numUsers; i++) {
                f << users[i].id << " " << users[i].getName() << " " << users[i].getCurrentBalance() << endl;
            }

            f.close();

        }

        /**
         * Lists all of the current users in the database
        */
        void list() {
            for (int i = 0; i < numUsers; i++) {
                users[i].info();
            }

            if (numUsers == 0) {
                cout << "No current users" << endl;
            }
        }

        void addUser() {
            string newUser = ""; 
            cout << "What is the name of the user?" << endl;
            cin >> newUser;

            int deposit = askForDeposit();

            users[numUsers].init(numUsers, newUser, deposit); // assigns last slot to new user 
            numUsers++;

            cout << newUser << " was added to the list" << endl;
        }

        void addDeposit() {
            cout << "What is the ID of the user?" << endl;

            string userMessage;

            cin >> userMessage;
            int ID = stoi(userMessage); 

            cout << "Depositing into " << users[ID].getName() << "'s account" << endl;
            
            // asks for deposit, adds it into the account
            users[ID].deposit(askForDeposit());
        }

        int askForDeposit() {
            int deposit = 0;
            string userMessage = "";

            while (deposit == 0) {
                cout << "What is the deposit?" << endl;
                cin >> userMessage;
                deposit = stoi(userMessage);
                cout << '$' << deposit << " was added into the account" << endl;

                if (deposit <= 0) {
                    cout << "Invalid deposit amount" << endl;
                }
            }

            return deposit;
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
            cout << "Type L for a list of users, A to add a user, D to deposit money, W to withdraw money, T to add a transaction, or X to terminate the program" << endl;
            cin >> typeOfInput;
            switch (typeOfInput) {
                case 'L':
                    list();
                    askForInput();
                    break;
                case 'A':
                    addUser();
                    askForInput();
                    break;
                case 'D':
                    addDeposit();
                    askForInput();
                    break;
                case 'W':
                    // withdrawal function
                    askForInput();
                    break;
                case 'T':
                    askForTransaction();
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
    //Bank northfieldBank("northfield", 10);
    Bank northfieldBank("northfield.txt");
    cout << "Welcome to an example bank registry." << endl; 
    northfieldBank.askForInput(); 
    return 0;
}