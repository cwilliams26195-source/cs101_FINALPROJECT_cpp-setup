#include "Registration.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void resetInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getInt(const string & prompt) {
    int num;
    while (true) {
        cout << prompt;
        if (cin >> num) {
            resetInput();
            return num;
        }
        cout << "Please enter a valid number.\n";
        resetInput();
    }
}

string getLineText(const string& prompt) {
    string text;
    cout << prompt;
    getline(cin, text);
    return text;
}

int main() {
    Registration reg;
    int choice;

    do {
        cout << "\n1. Register student\n";
        cout << "2. View all students\n";
        cout << "3. Search student by ID\n";
        cout << "4. Registration summary\n";
        cout << "5. Exit\n";
        choice = getInt("Choice (1-5): ");

        switch (choice) {
            case 1: {
                string name = getLineText("Name: ");
                string id = getLineText("Student ID: ");
                int age = getInt("Age (5-25): ");
                reg.showSports();
                int sportNum = getInt("Sport (1-5): ");
                reg.addStudent(name, id, age, sportNum);
                break;
            }
            case 2:
                reg.showAll();
                break;
            case 3: {
                string searchId = getLineText("Search ID: ");
                reg.findStudent(searchId);
                break;
            }
            case 4:
                reg.showSummary();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}