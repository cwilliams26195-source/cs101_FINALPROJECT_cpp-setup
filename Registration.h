#include "Student.h"
#include <array>
#include <string>
#include <vector>

class Registration {
private:
    std::array<std::string, 5> sports;
    std::vector<Student> list;
    bool onlySpaces(const std::string& text) const;

public:
    Registration();
    void showSports() const;
    void addStudent(const std::string& name, const std::string& id, int age, int sportNum);
    void showAll() const;
    void findStudent(const std::string& id) const;
    void showSummary() const;
};
