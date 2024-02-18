//
//  Animal.cpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#include "Animal.hpp"
#include <iostream>
using namespace std;

Animal::Animal(const string& id, const string& name, const string& offspring,
               const string& cellId, const string& gender, int age, double weight, AnimalCategory category, const string& birthDate)
    : id(id), name(name), offspring(offspring), cellId(cellId), gender(gender), age(age), weight(weight), category(category), birthDate(birthDate) {}

string Animal::getId() const {
    return id;
}

string Animal::getName() const {
    return name;
}

string Animal::getOffspring() const {
    return offspring;
}

string Animal::getCellId() const {
    return cellId;
}

string Animal::getGender() const {
    return gender;
}

int Animal::getAge() const {
    return age;
}

double Animal::getWeight() const {
    return weight;
}

AnimalCategory Animal::getCategory() const {

    return category;
}

string Animal::getBirthDate() const {
    return birthDate;
}
