#include "Registration.h"
#include <iostream>

using namespace std;

Registration::Registration() {
    sports = {"Basketball", "Football", "Volleyball", "Softball", "Track and Field"};
}

bool Registration::onlySpaces(const string& text) const {
    for (int i = 0; i < (int)text.size(); i++) {
        if (text[i] != ' ') {
            return false;
        }
    }
    return true;
}

void Registration::showSports() const {
    cout << "\nSports:\n";
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << ". " << sports[i] << endl;
    }
}

void Registration::addStudent(const string& name, const string& id, int age, int sportNum) {
    if (name.empty() || onlySpaces(name)) {
        cout << "Error: Name cannot be blank.\n";
        return;
    }

    if (id.empty() || onlySpaces(id)) {
        cout << "Error: Student ID cannot be blank.\n";
        return;
    }

    for (int i = 0; i < (int)list.size(); i++) {
        if (list[i].getId() == id) {
            cout << "Error: Student ID already exists.\n";
            return;
        }
    }

    if (age < 5 || age > 25) {
        cout << "Error: Age must be between 5 and 25.\n";
        return;
    }

    if (sportNum < 1 || sportNum > 5) {
        cout << "Error: Pick a sport from 1 to 5.\n";
        return;
    }

    string chosenSport = sports[sportNum - 1];
    Student s(name, id, age, chosenSport);
    list.push_back(s);
    cout << "Registered " << name << " in " << chosenSport << ".\n";
}

void Registration::showAll() const {
    if (list.empty()) {
        cout << "\nNo students registered yet.\n";
        return;
    }

    cout << "\n--- All Registered Students ---\n";
    for (int i = 0; i < (int)list.size(); i++) {
        cout << (i + 1) << ". ";
        list[i].print();
    }
}

void Registration::findStudent(const string& id) const {
    if (id.empty() || onlySpaces(id)) {
        cout << "Error: Enter an ID to search.\n";
        return;
    }

    for (int i = 0; i < (int)list.size(); i++) {
        if (list[i].getId() == id) {
            cout << "\nFound:\n";
            list[i].print();
            return;
        }
    }

    cout << "No student found with ID: " << id << endl;
}

void Registration::showSummary() const {
    array<int, 5> counts = {0, 0, 0, 0, 0};

    for (int i = 0; i < (int)list.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (list[i].getSport() == sports[j]) {
                counts[j]++;
                break;
            }
        }
    }

    cout << "\n--- Summary ---\n";
    cout << "Total students: " << list.size() << endl;
    for (int i = 0; i < 5; i++) {
        cout << sports[i] << ": " << counts[i] << endl;
    }
}