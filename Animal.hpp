//
//  Animal.hpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#ifndef Animal_hpp
#define Animal_hpp
#include <string>
using namespace std;

enum AnimalCategory {
    Amphibians,
    Birds,
    Fish,
    Invertebrates,
    Mammals,
    Reptiles
};

class Animal {
private:
    string id;
    string name;
    string offspring;
    string cellId;
    string gender;
    int age;
    double weight;
    AnimalCategory category;
    string birthDate;

public:
    Animal(const string& id, const string& name, const string& offspring,
           const string& cellId, const string& gender, int age, double weight, AnimalCategory category, const string& birthDate);

    string getId() const;
    string getName() const;
    string getOffspring() const;
    string getCellId() const;
    string getGender() const;
    int getAge() const;
    double getWeight() const;
    AnimalCategory getCategory() const;
    string getBirthDate() const;
};

#endif /* Animal_hpp */
