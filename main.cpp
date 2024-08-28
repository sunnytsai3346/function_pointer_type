#include <iostream>
#include <set>
#include <string>

struct Person {
    std::string name;
    int age;
};

// Comparison function by age
bool compareByAge(const Person lperson, const Person rperson) {
    return lperson.age < rperson.age;
}

// Comparison function by name
bool compareByName(const Person lperson, const Person rperson) {
    return lperson.name < rperson.name;
}

// Alias for function pointer type that compares two Persons
using fp = bool(*)(const Person lperson, const Person rperson);

int main() {
    // Comparator function pointer (initially compare by age)
    fp comparator = compareByAge;

    // Create a set of Person objects, ordered by the comparator function
    std::set<Person, fp> persons(comparator);

    // Add some persons to the set
    persons.insert({"Alice", 30});
    persons.insert({"Bob", 25});
    persons.insert({"Charlie", 35});

    // Iterate and print the set (ordered by age)
    std::cout << "Set ordered by age:" << std::endl;
    for (const auto& person : persons) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }

    // Change the comparator to compare by name and create a new set
    comparator = compareByName;
    std::set<Person, fp> personsByName(comparator);

    // Add the same persons to the new set, ordered by name
    personsByName.insert({"Alice", 30});
    personsByName.insert({"Bob", 25});
    personsByName.insert({"Charlie", 35});

    // Iterate and print the set (ordered by name)
    std::cout << "\nSet ordered by name:" << std::endl;
    for (const auto& person : personsByName) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }

    return 0;
