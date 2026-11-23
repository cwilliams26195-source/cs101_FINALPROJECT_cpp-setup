#include <string>

class Student {
private:
    std::string name;
    std::string id;
    int age;
    std::string sport;

public:
    Student();
    Student(std::string name, std::string id, int age, std::string sport);

    std::string getId() const;
    std::string getSport() const;
    void print() const;
};