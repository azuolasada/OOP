#include <gtest/gtest.h>
#include "Person.h"
#include "student.h"
#include <vector>
#include <string>

// Test for Person class
TEST(PersonTest, ConstructorAndGetterCheck) {
    Person person("Vardas", "Pavarde");
    EXPECT_EQ(person.getName(), "Vardas");
    EXPECT_EQ(person.getSurname(), "Pavarde");
}

// Test for Student class
TEST(StudentTest, ConstructorAndGetterCheck) {
    std::vector<int> homeworkResults = {5, 7, 8};
    Student student("Vardas", "Pavarde", homeworkResults, 7);

    EXPECT_EQ(student.getName(), "Vardas");
    EXPECT_EQ(student.getSurname(), "Pavarde");
    EXPECT_EQ(student.getExamResult(), 7);
    EXPECT_EQ(student.getHomeworkResults(), homeworkResults);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
