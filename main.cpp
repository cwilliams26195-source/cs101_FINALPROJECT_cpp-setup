#include "Registration.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void fixCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getNum() {
    int x = 0;
    while (!(cin >> x)) {
        cout << "Enter a number: ";
        fixCin();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

int main() {
    Registration reg;
    int opt = 0;

    do {
        cout << "\n=== Sports Team Registration ===\n";
        cout << "1. Register student\n";
        cout << "2. View all students\n";
        cout << "3. Search student by ID\n";
        cout << "4. Registration summary\n";
        cout << "5. Exit\n";
        cout << "Choice: ";

        opt = getNum();

        if (opt == 1) {
            string name = "";
            string id = "";
            int age = 0;
            int pick = 0;

            cout << "Name: ";
            getline(cin, name);

            cout << "ID: ";
            getline(cin, id);

            cout << "Age: ";
            age = getNum();

            reg.printSports();
            cout << "Sport (1-5): ";
            pick = getNum();

            reg.addStudent(name, id, age, pick);
        } else if (opt == 2) {
            reg.showList();
        } else if (opt == 3) {
            string id = "";
            cout << "Search ID: ";
            getline(cin, id);
            reg.findStudent(id);
        } else if (opt == 4) {
            reg.summary();
        } else if (opt == 5) {
            cout << "Bye!\n";
        } else {
            cout << "Invalid option.\n";
        }
    } while (opt != 5);

    return 0;
}