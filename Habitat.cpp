//
//  Habitat.cpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#include "Habitat.hpp"
using namespace std;

Habitat::Habitat(const string& cellId, const string& area, const string& location, const string& birthDate, bool isEndangered)
    : cellId(cellId), area(area), location(location), birthDate(birthDate), endangered(isEndangered) {}

string Habitat::getCellId() const {
    return cellId;
}

string Habitat::getArea() const {
    return area;
}

string Habitat::getLocation() const {
    return location;
}

string Habitat::getBirthDate() const {
    return birthDate;
}

bool Habitat::isEndangered() const {
    return endangered;
}
