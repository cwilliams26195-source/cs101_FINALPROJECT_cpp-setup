#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() {
    name = "";
    id = "";
    age = 0;
    sport = "";
}

Student::Student(string name, string id, int age, string sport) {
    this->name = name;
    this->id = id;
    this->age = age;
    this->sport = sport;
}

string Student::getId() const {
    return id;
}

string Student::getSport() const {
    return sport;
}

void Student::print() const {
    cout << "ID: " << id
         << " | Name: " << name
         << " | Age: " << age
         << " | Sport: " << sport << endl;
}