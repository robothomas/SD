#include <iostream>
using namespace std;

short day, month, year, format;

void formatOne() {
    if (day < 10 && month >= 10) {
        cout << year << '/' << month << '/' << '0' << day << endl;
    }
    else if (day >= 10 && month < 10) {
        cout << year << '/' << '0' << month << '/' << day << endl;
    }
    else if (day < 10 && month < 10) {
        cout << year << '/' << '0' << month << '/' << '0' << day << endl;
    } else {
        cout << year << '/' << month << '/' << day << endl;
    }
}

void formatTwo() {
    if (day < 10 && month >= 10) {
        cout << '0' << day << '/' << month << '/' << year << endl;

    } else if (day >= 10 && month < 10) {
        cout << day << '/' << '0' << month << '/' << year << endl;

    } else if (day < 10 && month < 10) {
        cout << '0' << day << '/' << '0' << month << '/' << year << endl;

    } else {
        cout << day << '/' << month << '/' << year << endl;
    }
}

void formatThree() {
    if (day < 10 && month >= 10) {
        cout << month << '/' << '0' << day << '/' << year << endl;

    } else if (day >= 10 && month < 10) {
        cout << '0' << month << '/' << day << '/' << year << endl;

    } else if (day < 10 && month < 10) {
        cout << '0' << month << '/' << '0' << day << '/' << year << endl;
        
    } else {
        cout << month << '/' << day << '/' << year << endl;
    }
}

// Checks format and nested ifs add zeros in appropriate places to keep format intact
void formatting() {
    if (format == 1) { // YY/MM/DD 
        formatOne();

    } else if (format == 2) { // DD/MM/YYYY
        formatTwo();

    } else if (format == 3) { // MM/DD/YYYY
        formatThree();
        
    } else {
        cout << "ERROR: Invalid format input" << endl;

        cout << "Formats are (1) YYYY/MM/DD, (2) DD/MM/YYYY, and (3) MM/DD/YYYY" << endl;
        cout << "Enter the number for the format you want (1, 2, or 3): ";

        cin >> format;
        formatting();
    }
}

int main() {

    // Request day of the month (as a number) 
    cout << "Enter a day of the month (1, 12 30, etc): ";
    cin >> day;

    // Request a month number 
    cout << "Enter a month (1, 5, 11, etc.): ";
    cin >> month;

    // Request a year
    cout << "Enter a year (1977, 2014, 2050, etc.): ";
    cin >> year;

    // Ask format the user would like
    cout << "Formats are (1) YYYY/MM/DD, (2) DD/MM/YYYY, and (3) MM/DD/YYYY" << endl;
    cout << "Enter the number for the format you want (1, 2, or 3): ";
    cin >> format;

    formatting();
}