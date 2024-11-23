//
//  main.cpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#include <iostream>
#include "Habitat.hpp"
#include "Animal.hpp"
#include "AnimalHealth.hpp"
#include "Database.hpp"
using namespace std;

void displayMenu() {

    cout<<"\n------------- Lahore Zoo Information Management System ----------\n";
    cout << "\n\n";
    cout<<"-------------------------------------------------------"<<endl;
    cout << "1. Add an animal" << endl;
    cout << "2. Find an animal by ID" << endl;
    cout << "3. Delete an animal by ID" << endl;
    cout << "4. Add a habitat" << endl;
    cout << "5. Find a habitat by location" << endl;
    cout << "6. Add a health record" << endl;
    cout << "7. Display sick animals by category" << endl;
    cout << "8. Display sick animals by age" << endl;
    cout << "9. Display sick animals by gender" << endl;
    cout << "10. Display sick animals by location" << endl;
    cout << "11. Display sick animals between dates" << endl;
    cout << "12. Calculate sick animals frequency" << endl;
    cout << "13. Destroy all health records" << endl;
    cout << "14. Count animals born between dates" << endl;
    cout << "0. Exit" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void addAnimal(Database& database) {
    cin.ignore();
    string id, name, offspring, cellId, gender, birthDate;
    int age;
    double weight;
    AnimalCategory category;

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter offspring: ";
    cin >> offspring;
    cout << "Enter cell ID: ";
    cin >> cellId;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter weight: ";
    cin >> weight;

    int categoryNum;
    cout << "********** Animal Categories *********" << endl;
    cout << "0. Amphibians" << endl;
    cout << "1. Birds" << endl;
    cout << "2. Fish" << endl;
    cout << "3. Invertebrates" << endl;
    cout << "4. Mammals" << endl;
    cout << "5. Reptiles" << endl;
    cout << "\n\n";
    cout << "Enter category (0-5): ";
    cin >> categoryNum;
    category = static_cast<AnimalCategory>(categoryNum);

    cout << "Enter birth date: ";
    cin >> birthDate;

    Animal* animal = new Animal(id, name, offspring, cellId, gender, age, weight, category, birthDate);
    database.addAnimal(animal);

    cout << "Animal added successfully." << endl;
}


void findAnimalById(Database& database) {
    cin.ignore();
    string id;
    cout << "Enter ID: ";
    cin >> id;

    Animal* animal = database.findAnimalById(id);
    if (animal) {
        cout << "Animal found:" << endl;
        cout << "ID: " << animal->getId() << endl;
        cout << "Name: " << animal->getName() << endl;
    }
    else {
        cout << "Animal not found." << endl;
    }
}

void deleteAnimalById(Database& database) {
    string id;
    cout << "Enter ID: ";
    cin >> id;

    database.deleteAnimalById(id);
    cout << "Animal deleted." << endl;
}

void addHabitat(Database& database) {
    string cellId, area, location, birthDate;
    bool isEndangered;

    cout << "Enter cell ID: ";
    cin >> cellId;
    cin.ignore();
    cout << "Enter area: ";
    cin >> area;
    cin.ignore();
    cout << "Enter location: ";
    cin >> location;
    cin.ignore();
    cout << "Enter birth date(YYYY-MM-DD): ";
    cin >> birthDate;
    cin.ignore();
    cout << "Is endangered (0 for false, 1 for true): ";
    cin >> isEndangered;
    cin.ignore();

    Habitat* habitat = new Habitat(cellId, area, location, birthDate, isEndangered);
    database.addHabitat(habitat);

    cout << "Habitat added successfully." << endl;
}

void findHabitatByLocation(Database& database) {
    string location;
    cout << "Enter location: ";
    cin >> location;

    Habitat* habitat = database.findHabitatByLocation(location);
    if (habitat) {
        cout << "Habitat found:" << endl;
        cout << "Cell ID: " << habitat->getCellId() << endl;
        cout << "Area: " << habitat->getArea() << endl;

    }
    else {
        cout << "Habitat not found." << endl;
    }
}

void addHealthRecord(Database& database) {
    bool fitStatus;
    string keeperDetails;
    int dietaryCondition;
    string foodSupplyDetails;

    cout << "Enter fit status (0 for false, 1 for true): ";
    cin >> fitStatus;
    cin.ignore();
    cout << "Enter keeper details: ";
    getline(cin, keeperDetails);
    cout << endl;
    cout << "********* Dietary Condition *******" << endl;
    cout << "0. CANIBALS" << endl;
    cout << "1. CARNIVORE" << endl;
    cout << "2. HERBIVORE" << endl;
    cout << "3. OMNIVORE" << endl;
    cout << "4. SCAVANGERS" << endl;
    cout << "\n\n";
    cout << "Enter dietary condition (0-4): ";
    cin >> dietaryCondition;
    cin.ignore();
    cout << "Enter food supply details: ";
    getline(cin, foodSupplyDetails);

    HealthRecord* healthRecord = new HealthRecord(fitStatus, keeperDetails, static_cast<DietaryCondition>(dietaryCondition),foodSupplyDetails);
    database.addHealthRecord(healthRecord);

    cout << "Health record added successfully." << endl;
}

void displaySickAnimalsByCategory(Database& database) {
    int category;
    cout << "********** Animal Categories *********" << endl;
    cout << "0. Amphibians" << endl;
    cout << "1. Birds" << endl;
    cout << "2. Fish" << endl;
    cout << "3. Invertebrates" << endl;
    cout << "4. Mammals" << endl;
    cout << "5. Reptiles" << endl;
    cout << "\n\n";
    cout << "Enter category (0-5): ";
    cin >> category;

    database.displaySickAnimalsByCategory(static_cast<AnimalCategory>(category));
}

void displaySickAnimalsByAge(Database& database) {
    int age;
    cout << "Enter age: ";
    cin >> age;

    database.displaySickAnimalsByAge(age);
}

void displaySickAnimalsByGender(Database& database) {
    string gender;
    cout << "Enter gender: ";
    cin >> gender;

    database.displaySickAnimalsByGender(gender);
}

void displaySickAnimalsByLocation(Database& database) {
    string location;
    cout << "Enter location: ";
    cin >> location;

    database.displaySickAnimalsByLocation(location);
}

void displaySickAnimalsBetweenDates(Database& database) {
    string startDate, endDate;
    cout << "Enter start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter end date (YYYY-MM-DD): ";
    cin >> endDate;

    database.displaySickAnimalsBetweenDates(startDate, endDate);
}

void calculateSickAnimalsFrequency(Database& database) {
    int frequency = database.calculateSickAnimalsFrequency();
    cout << "Sick animals frequency: " << frequency << endl;
}

void destroyAllHealthRecords(Database& database) {
    database.destroyAllRecords();
    cout << "All health records destroyed." << endl;
}

void countAnimalsBornBetweenDates(Database& database) {
    string startDate, endDate;
    cout << "Enter start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter end date (YYYY-MM-DD): ";
    cin >> endDate;

    int count = database.countAnimalsBornBetweenDates(startDate, endDate);
    cout << "Number of animals born between dates: " << count << endl;
}

int main() {
    Database database;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addAnimal(database);
                break;
            case 2:
                findAnimalById(database);
                break;
            case 3:
                deleteAnimalById(database);
                break;
            case 4:
                addHabitat(database);
                break;
            case 5:
                findHabitatByLocation(database);
                break;
            case 6:
                addHealthRecord(database);
                break;
            case 7:
                displaySickAnimalsByCategory(database);
                break;
            case 8:
                displaySickAnimalsByAge(database);
                break;
            case 9:
                displaySickAnimalsByGender(database);
                break;
            case 10:
                displaySickAnimalsByLocation(database);
                break;
            case 11:
                displaySickAnimalsBetweenDates(database);
                break;
            case 12:
                calculateSickAnimalsFrequency(database);
                break;
            case 13:
                destroyAllHealthRecords(database);
                break;
            case 14:
                countAnimalsBornBetweenDates(database);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again. :(((((" << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);


    return 0;
}

