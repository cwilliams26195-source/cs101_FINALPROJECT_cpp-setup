
#include "Student.h"
#include <array>
#include <string>
#include <vector>

using namespace std;

class Registration {
private:
    array<string, 5> sports = {
        "Basketball",
        "Football",
        "Volleyball",
        "Softball",
        "Track and Field"
    };
    vector<Student> list;

    int emptyInput(string s);
    int dupeId(string id);

public:
    Registration();

    void printSports();
    void addStudent(string name, string id, int age, int pick);
    void showList();
    void findStudent(string id);
    void summary();
};

