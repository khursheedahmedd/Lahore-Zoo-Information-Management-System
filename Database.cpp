//
//  Database.cpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#include "Database.hpp"
#include "Habitat.hpp"
#include "Animal.hpp"
#include "AnimalHealth.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Database::Database()
    : animals(new Animal*[100]), healthRecords(new HealthRecord*[100]), habitats(new Habitat*[100]),
      animalCount(0), healthRecordCount(0), habitatCount(0), animalCapacity(100), healthRecordCapacity(100), habitatCapacity(100) {}

Database::~Database() {
    for (int i = 0; i < animalCount; ++i) {
        delete animals[i];
    }
    delete[] animals;

    for (int i = 0; i < healthRecordCount; ++i) {
        delete healthRecords[i];
    }
    delete[] healthRecords;

    for (int i = 0; i < habitatCount; ++i) {
        delete habitats[i];
    }
    delete[] habitats;
}

void Database::addAnimal(Animal* animal) {
    if (animalCount >= animalCapacity) {
        Animal** newAnimals = new Animal*[animalCapacity * 2];
        for (int i = 0; i < animalCount; ++i) {
            newAnimals[i] = animals[i];
        }
        delete[] animals;
        animals = newAnimals;
        animalCapacity *= 2;
    }

    animals[animalCount++] = animal;

    ofstream outFile("animal_records.txt", ios::app);
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    outFile << "New Animal Record:" << endl;
    outFile << "ID: " << animal->getId() << endl;
    outFile << "Name: " << animal->getName() << endl;
    outFile << "Offspring: " << animal->getOffspring() << endl;
    outFile << "Cell ID: " << animal->getCellId() << endl;
    outFile << "Gender: " << animal->getGender() << endl;
    outFile << "Age: " << animal->getAge() << endl;
    outFile << "Weight: " << animal->getWeight() << endl;
    outFile << "Category: " << animal->getCategory() << endl;
    outFile << "Birth Date: " << animal->getBirthDate() << endl;
    outFile << endl;

    outFile.close();
    cout << "Animal record added. Details written to 'animal_records.txt'." << endl;
}

Animal* Database::findAnimalById(const string& id) {
    for (int i = 0; i < animalCount; ++i) {
        if (animals[i]->getId() == id) {
            ofstream outFile("search_results.txt");
            if (!outFile) {
                cerr << "Failed to open the output file." << endl;
                return nullptr;
            }

            outFile << "Search Results:" << endl;
            outFile << "Animal ID: " << animals[i]->getId() << endl;
            outFile << "Name: " << animals[i]->getName() << endl;
            outFile << "Offspring: " << animals[i]->getOffspring() << endl;
            outFile << "Cell ID: " << animals[i]->getCellId() << endl;
            outFile << "Gender: " << animals[i]->getGender() << endl;
            outFile << "Age: " << animals[i]->getAge() << endl;
            outFile << "Weight: " << animals[i]->getWeight() << endl;
            outFile << "Category: " << animals[i]->getCategory() << endl;
            outFile << "Birth Date: " << animals[i]->getBirthDate() << endl;
            outFile << endl;

            outFile.close();
            cout << "Animal found. Details written to 'search_results.txt'." << endl;

            return animals[i];
        }
    }
    return nullptr;
}

void Database::deleteAnimalById(const string& id) {
    ofstream outFile("deleted_animals.txt", ios::app);
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    for (int i = 0; i < animalCount; ++i) {
        if (animals[i]->getId() == id) {
            outFile << "Deleted Animal Record ID: " << animals[i]->getId() << endl;
            delete animals[i];
            for (int j = i + 1; j < animalCount; ++j) {
                animals[j - 1] = animals[j];
            }
            animalCount--;
            break;
        }
    }

    outFile.close();
    cout << "Animal record deleted. Details written to 'deleted_animals.txt'." << endl;
}

void Database::addHabitat(Habitat* habitat) {
    if (habitatCount >= habitatCapacity) {
        habitatCapacity += 10;
        Habitat** newHabitats = new Habitat*[habitatCapacity];

        for (int i = 0; i < habitatCount; ++i) {
            newHabitats[i] = habitats[i];
        }

        delete[] habitats;

        habitats = newHabitats;

        habitatCount = habitatCapacity;
    }

    habitats[habitatCount++] = habitat;

    ofstream outFile("habitat_records.txt", ios::app);
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    outFile << "New Habitat Record:" << endl;
    outFile << "Cell ID: " << habitat->getCellId() << endl;
    outFile << "Area: " << habitat->getArea() << endl;
    outFile << "Location: " << habitat->getLocation() << endl;
    outFile << "Birth Date: " << habitat->getBirthDate() << endl;
    outFile << "Endangered: " << (habitat->isEndangered() ? "Yes" : "No") << endl;
    outFile << endl;

    outFile.close();
    cout << "Habitat record added. Details written to 'habitat_records.txt'." << endl;
}


Habitat* Database::findHabitatByLocation(const string& location) {
    ofstream outFile("search_results.txt", ios::app);
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return nullptr;
    }

    for (int i = 0; i < habitatCount; ++i) {
        if (habitats[i]->getLocation() == location) {
            outFile << "Search Results:" << endl;
            outFile << "Habitat Cell ID: " << habitats[i]->getCellId() << endl;
            outFile << "Area: " << habitats[i]->getArea() << endl;
            outFile << "Location: " << habitats[i]->getLocation() << endl;
            outFile << "Birth Date: " << habitats[i]->getBirthDate() << endl;
            outFile << "Endangered: " << (habitats[i]->isEndangered() ? "Yes" : "No") << endl;
            outFile << endl;

            outFile.close();
            cout << "Habitat found. Details written to 'search_results.txt'." << endl;

            return habitats[i];
        }
    }

    outFile.close();
    cout << "Habitat not found." << endl;
    return nullptr;
}


void Database::addHealthRecord(HealthRecord* healthRecord) {
    if (healthRecordCount >= healthRecordCapacity) {
        healthRecordCapacity += 10;

        HealthRecord** newHealthRecords = new HealthRecord*[healthRecordCapacity];

        for (int i = 0; i < healthRecordCount; ++i) {
            newHealthRecords[i] = healthRecords[i];
        }

        delete[] healthRecords;

        healthRecords = newHealthRecords;

        healthRecordCount = healthRecordCapacity;
    }

    healthRecords[healthRecordCount++] = healthRecord;

    ofstream outFile("health_records.txt", ios::app);
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    outFile << "New Health Record:" << endl;
    outFile << "Fit Status: " << (healthRecord->isFit() ? "Fit" : "Sick") << endl;
    outFile << "Keeper Details: " << healthRecord->getKeeperDetails() << endl;
    outFile << "Dietary Condition: " << healthRecord->getDietaryCondition() << endl;
    outFile << "Food Supply Details: " << healthRecord->getFoodSupplyDetails() << endl;
    outFile << endl;

    outFile.close();
    cout << "Health record added. Details written to 'health_records.txt'." << endl;
}

void Database::displaySickAnimalsByCategory(AnimalCategory category) {
    ofstream outFile("sick_animals.txt");
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    for (int i = 0; i < animalCount; ++i) {
        Animal* animal = animals[i];
        if (animal->getCategory() == category) {
            outFile << "Animal ID: " << animal->getId() << endl;
            outFile << "Name: " << animal->getName() << endl;
            outFile << "Category: " << animal->getCategory() << endl;
            outFile << "Health Status: ";

            for (int j = 0; j < healthRecordCount; ++j) {
                HealthRecord* healthRecord = healthRecords[j];
                if (animal->getCellId() == healthRecord->getCellId()) {
                    if (healthRecord->isFit()) {
                        outFile << "Healthy" << endl;
                    } else {
                        outFile << "Sick" << endl;
                    }
                    break;
                }
            }
        }
    }

    outFile.close();
    cout << "Sick animals by category written to 'sick_animals.txt'." << endl;
}

void Database::displaySickAnimalsByAge(int age) {
    ofstream outFile("sick_animals.txt");
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    for (int i = 0; i < animalCount; ++i) {
        Animal* animal = animals[i];
        if (animal->getAge() == age) {
            outFile << "Animal ID: " << animal->getId() << endl;
            outFile << "Name: " << animal->getName() << endl;
            outFile << "Category: " << animal->getCategory() << endl;
            outFile << "Health Status: ";

            for (int j = 0; j < healthRecordCount; ++j) {
                HealthRecord* healthRecord = healthRecords[j];
                if (animal->getCellId() == healthRecord->getCellId()) {
                    if (healthRecord->isFit()) {
                        outFile << "Healthy" << endl;
                    } else {
                        outFile << "Sick" << endl;
                    }
                    break;
                }
            }
        }
    }

    outFile.close();
    cout << "Sick animals by age written to 'sick_animals.txt'." << endl;
}

void Database::displaySickAnimalsByGender(const string& gender) {
    ofstream outFile("sick_animals.txt");
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    for (int i = 0; i < animalCount; ++i) {
        Animal* animal = animals[i];
        if (animal->getGender() == gender) {
            outFile << "Animal ID: " << animal->getId() << endl;
            outFile << "Name: " << animal->getName() << endl;
            outFile << "Category: " << animal->getCategory() << endl;
            outFile << "Health Status: ";

            for (int j = 0; j < healthRecordCount; ++j) {
                HealthRecord* healthRecord = healthRecords[j];
                if (animal->getCellId() == healthRecord->getCellId()) {
                    if (healthRecord->isFit()) {
                        outFile << "Healthy" << endl;
                    } else {
                        outFile << "Sick" << endl;
                    }
                    break;
                }
            }
        }
    }

    outFile.close();
    cout << "Sick animals by gender written to 'sick_animals.txt'." << endl;
}

void Database::displaySickAnimalsByLocation(const string& location) {
    ofstream outFile("sick_animals.txt");
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    for (int i = 0; i < animalCount; ++i) {
        Animal* animal = animals[i];
        string cellId = animal->getCellId();
        for (int j = 0; j < habitatCount; ++j) {
            Habitat* habitat = habitats[j];
            if (habitat->getCellId() == cellId && habitat->getLocation() == location) {
                outFile << "Animal ID: " << animal->getId() << endl;
                outFile << "Name: " << animal->getName() << endl;
                outFile << "Category: " << animal->getCategory() << endl;
                outFile << "Health Status: ";

                for (int k = 0; k < healthRecordCount; ++k) {
                    HealthRecord* healthRecord = healthRecords[k];
                    if (cellId == healthRecord->getCellId()) {
                        if (healthRecord->isFit()) {
                            outFile << "Healthy" << endl;
                        } else {
                            outFile << "Sick" << endl;
                        }
                        break;
                    }
                }
                break;
            }
        }
    }

    outFile.close();
    cout << "Sick animals by location written to 'sick_animals.txt'." << endl;
}

void Database::displaySickAnimalsBetweenDates(const string& startDate, const string& endDate) {
    ofstream outFile("sick_animals.txt");
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    for (int i = 0; i < animalCount; ++i) {
        Animal* animal = animals[i];
        string cellId = animal->getCellId();
        for (int j = 0; j < healthRecordCount; ++j) {
            HealthRecord* healthRecord = healthRecords[j];
            if (cellId == healthRecord->getCellId()) {
                string birthDate = animal->getBirthDate();
                if (birthDate >= startDate && birthDate <= endDate) {
                    outFile << "Animal ID: " << animal->getId() << endl;
                    outFile << "Name: " << animal->getName() << endl;
                    outFile << "Category: " << animal->getCategory() << endl;
                    outFile << "Health Status: ";
                    if (healthRecord->isFit()) {
                        outFile << "Healthy" << endl;
                    } else {
                        outFile << "Sick" << endl;
                    }
                    break;
                }
            }
        }
    }

    outFile.close();
    cout << "Sick animals between dates written to 'sick_animals.txt'." << endl;
}

int Database::calculateSickAnimalsFrequency() {
    int sickCount = 0;
    for (int i = 0; i < healthRecordCount; ++i) {
        if (!healthRecords[i]->isFit()) {
            sickCount++;
        }
    }
    return sickCount;
}

void Database::destroyAllRecords() {
    ofstream outFile("destroyed_records.txt");
    if (!outFile) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    for (int i = 0; i < animalCount; ++i) {
        outFile << "Destroyed Animal Record ID: " << animals[i]->getId() << endl;
        delete animals[i];
    }
    animalCount = 0;

    for (int i = 0; i < healthRecordCount; ++i) {
        outFile << "Destroyed Health Record ID: " << healthRecords[i]->getKeeperDetails() << endl;
        delete healthRecords[i];
    }
    healthRecordCount = 0;

    for (int i = 0; i < habitatCount; ++i) {
        outFile << "Destroyed Habitat Record ID: " << habitats[i]->getCellId() << endl;
        delete habitats[i];
    }
    habitatCount = 0;

    outFile.close();
    cout << "All records destroyed. Details written to 'destroyed_records.txt'." << endl;
}

int Database::countAnimalsBornBetweenDates(const string& startDate, const string& endDate) {
    int count = 0;
    for (int i = 0; i < animalCount; ++i) {
        Animal* animal = animals[i];
        string birthDate = animal->getBirthDate();
        if (birthDate >= startDate && birthDate <= endDate) {
            count++;
        }
    }
    return count;
}
