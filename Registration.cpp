#include "Registration.h"
#include <iostream>

using namespace std;

Registration::Registration() {
}

int Registration::emptyInput(string s) {
    if (s.empty()) {
        return 1;
    }
    if (s.find_first_not_of(" ") == string::npos) {
        return 1;
    }
    return 0;
}

int Registration::dupeId(string id) {
    for (int i = 0; i < (int)list.size(); i++) {
        if (list[i].getId() == id) {
            return 1;
        }
    }
    return 0;
}

void Registration::printSports() {
    cout << "\nSports:\n";
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << ". " << sports[i] << "\n";
    }
}

void Registration::addStudent(string name, string id, int age, int pick) {
    if (emptyInput(name) == 1) {
        cout << "Name cannot be empty.\n";
        return;
    }

    if (emptyInput(id) == 1) {
        cout << "ID cannot be empty.\n";
        return;
    }

    if (dupeId(id) == 1) {
        cout << "That ID is already used.\n";
        return;
    }

    if (age < 5 || age > 25) {
        cout << "Age must be from 5 to 25.\n";
        return;
    }

    if (pick < 1 || pick > 5) {
        cout << "Pick a number from 1 to 5.\n";
        return;
    }

    string chosen = sports[pick - 1];
    Student st(name, id, age, chosen);
    list.push_back(st);

    cout << "Added " << name << " to " << chosen << ".\n";
}

void Registration::showList() {
    if (list.empty()) {
        cout << "\nNo students yet.\n";
        return;
    }

    cout << "\n--- Students ---\n";
    for (int i = 0; i < (int)list.size(); i++) {
        cout << (i + 1) << ") " << list[i].getId()
             << " - " << list[i].getName()
             << " (Age " << list[i].getAge() << ") - "
             << list[i].getSport() << "\n";
    }
}

void Registration::findStudent(string id) {
    if (emptyInput(id) == 1) {
        cout << "Enter an ID first.\n";
        return;
    }

    for (int i = 0; i < (int)list.size(); i++) {
        if (list[i].getId() == id) {
            cout << "\nFound:\n";
            cout << "ID: " << list[i].getId() << "\n";
            cout << "Name: " << list[i].getName() << "\n";
            cout << "Age: " << list[i].getAge() << "\n";
            cout << "Sport: " << list[i].getSport() << "\n";
            return;
        }
    }

    cout << "ID not found.\n";
}

void Registration::summary() {
    int totals[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < (int)list.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (list[i].getSport() == sports[j]) {
                totals[j] = totals[j] + 1;
            }
        }
    }

    cout << "\n--- Summary ---\n";
    cout << "Total students: " << list.size() << "\n";
    for (int i = 0; i < 5; i++) {
        cout << sports[i] << ": " << totals[i] << "\n";
    }
}