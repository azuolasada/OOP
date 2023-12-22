#pragma once
#include <string>

/**
 * @brief Represents a person with a name and surname.
 */
class Person {
protected:
    std::string name; ///< Name of the person
    std::string surname; ///< Surname of the person

public:
    /**
     * @brief Construct a new Person object
     * 
     * @param name The name of the person
     * @param surname The surname of the person
     */
    Person(const std::string& name, const std::string& surname)
        : name(name), surname(surname) {}

    /**
     * @brief Virtual destructor for the Person class
     */
    virtual ~Person() {}

    /**
     * @brief Get the Name of the person
     * 
     * @return const std::string& Name of the person
     */
    const std::string& getName() const { return name; }

    /**
     * @brief Get the Surname of the person
     * 
     * @return const std::string& Surname of the person
     */
    const std::string& getSurname() const { return surname; }

    /**
     * @brief Set the Name of the person
     * 
     * @param newName New name for the person
     */
    void setName(const std::string& newName) { name = newName; }

    /**
     * @brief Set the Surname of the person
     * 
     * @param newSurname New surname for the person
     */
    void setSurname(const std::string& newSurname) { surname = newSurname; }

};
