//
//  AnimalHealth.cpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#include "AnimalHealth.hpp"
using namespace std;

HealthRecord::HealthRecord(bool fitStatus, const string& keeperDetails, DietaryCondition dietaryCondition, const string& foodSupplyDetails)
    : fitStatus(fitStatus), keeperDetails(keeperDetails), dietaryCondition(dietaryCondition), foodSupplyDetails(foodSupplyDetails) {}

bool HealthRecord::isFit() const {
    return fitStatus;
}

string HealthRecord::getKeeperDetails() const {
    return keeperDetails;
}

DietaryCondition HealthRecord::getDietaryCondition() const {
    return dietaryCondition;
}

string HealthRecord::getFoodSupplyDetails() const {
    return foodSupplyDetails;
}

string HealthRecord::getCellId() const {
    return cellId;
}
