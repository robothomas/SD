#include <iostream>
using namespace std;

class Worker {
    int ID;
    string name;

    public:
    Worker(int identification_num, string verbalIdentifier) {
        ID = identification_num;
        name = verbalIdentifier;
    }

    string getName() {
        return name;
    }

    int getIdentifcation() {
        return ID;
    }
};

class Company {
    Worker ceo;

    int *IDs;
    string *workerNames;

    public:
    // definition for a start-up with a single employee: the CEO
    Company (int ID, string name) : ceo(ID, name) {
        cout << "created" << endl;
        IDs = new int;
        IDs[0] = ID;

        workerNames = new string;
        workerNames[0] = name; 
    }

    ~Company() {
       cout << "destroyed" << endl;
       delete workerNames;
       delete IDs; 
    }
};

int main() {
    Company oneManStartup(0, "Bob");
}