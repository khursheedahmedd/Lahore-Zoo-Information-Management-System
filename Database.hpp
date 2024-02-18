//
//  Database.hpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#ifndef Database_hpp
#define Database_hpp
#include "Habitat.hpp"
#include "AnimalHealth.hpp"
#include "Animal.hpp"
#include <string>
using namespace std;

class Database {
public:
    Database();
    ~Database();

    void addAnimal(Animal* animal);
    Animal* findAnimalById(const string& id);
    void deleteAnimalById(const string& id);

    void addHabitat(Habitat* habitat);
    Habitat* findHabitatByLocation(const string& location);

    void addHealthRecord(HealthRecord* healthRecord);

    void displaySickAnimalsByCategory(AnimalCategory category);
    void displaySickAnimalsByAge(int age);
    void displaySickAnimalsByGender(const string& gender);
    void displaySickAnimalsByLocation(const string& location);
    void displaySickAnimalsBetweenDates(const string& startDate, const string& endDate);

    int calculateSickAnimalsFrequency();
    void destroyAllRecords();

    int countAnimalsBornBetweenDates(const string& startDate, const string& endDate);
    
    void addAnimal(Database& database); 
    void findAnimalById(Database& database);
    void deleteAnimalById(Database& database);
    void addHabitat(Database& database);
    void findHabitatByLocation(Database& database);
    void addHealthRecord(Database& database);
    void displaySickAnimalsByCategory(Database& database);
    void displaySickAnimalsByAge(Database& database);
    void displaySickAnimalsByGender(Database& database);
    void displaySickAnimalsByLocation(Database& database);
    void displaySickAnimalsBetweenDates(Database& database);
    void calculateSickAnimalsFrequency(Database& database);
    void destroyAllHealthRecords(Database& database);
    void countAnimalsBornBetweenDates(Database& database);


private:
    Animal** animals;
    HealthRecord** healthRecords;
    Habitat** habitats;
    int animalCount;
    int healthRecordCount;
    int habitatCount;
    int animalCapacity;
    int healthRecordCapacity;
    int habitatCapacity;
};

#endif /* Database_hpp */
