//
//  AnimalHealth.hpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#ifndef AnimalHealth_hpp
#define AnimalHealth_hpp
#include <string>
using namespace std;

enum DietaryCondition {
    CANNIBALS,
    CARNIVORE,
    HERBIVORE,
    OMNIVORE,
    SCAVENGERS
};

class HealthRecord {
public:
    HealthRecord(bool fitStatus, const string& keeperDetails, DietaryCondition dietaryCondition, const string& foodSupplyDetails);

    bool isFit() const;
    string getKeeperDetails() const;
    DietaryCondition getDietaryCondition() const;
    string getFoodSupplyDetails() const;
    string getCellId() const;

private:
    bool fitStatus;
    string keeperDetails;
    DietaryCondition dietaryCondition;
    string foodSupplyDetails;
    string cellId;
};

#endif /* AnimalHealth_hpp */
