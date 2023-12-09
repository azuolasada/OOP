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

    // Pure virtual destructor to make this class abstract
    virtual ~Person() = 0;

    // Getters
    const std::string& getName() const { return name; }
    const std::string& getSurname() const { return surname; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setSurname(const std::string& newSurname) { surname = newSurname; }

    // Other pure virtual functions can be added here as needed
};

// Define the pure virtual destructor outside the class
inline Person::~Person() {}