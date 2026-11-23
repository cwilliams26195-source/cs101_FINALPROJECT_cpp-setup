#include "Student.h"

Student::Student() {
    name = "";
    id = "";
    age = 0;
    sport = "";
}

Student::Student(string n, string i, int a, string s) {
    name = n;
    id = i;
    age = a;
    sport = s;
}

string Student::getName() {
    return name;
}

string Student::getId() {
    return id;
}

int Student::getAge() {
    return age;
}

string Student::getSport() {
    return sport;
}