#include <string>
using namespace std;

class Student {
private:
    string name;
    string id;
    int age;
    string sport;

public:
    Student();
    Student(string n, string i, int a, string s);

    string getName();
    string getId();
    int getAge();
    string getSport();
};

