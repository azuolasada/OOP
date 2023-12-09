#pragma once
#include <string>

class Person {
protected:
    std::string name;
    std::string surname;

public:
    // Constructor
    Person(const std::string& name, const std::string& surname)
        : name(name), surname(surname) {}

    // Virtual destructor
    virtual ~Person() {}

    // Getters
    const std::string& getName() const { return name; }
    const std::string& getSurname() const { return surname; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setSurname(const std::string& newSurname) { surname = newSurname; }

};