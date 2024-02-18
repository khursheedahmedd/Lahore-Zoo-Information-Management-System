//
//  Habitat.hpp
//  Lahore Zoo Information Management System
//
//  Created by Macbook on 07/07/2023.
//

#ifndef Habitat_hpp
#define Habitat_hpp
#include <string>
using namespace std;

class Habitat {
public:
    Habitat(const string& cellId, const string& area, const string& location, const string& birthDate, bool isEndangered);

    string getCellId() const;
    string getArea() const;
    string getLocation() const;
    string getBirthDate() const;
    bool isEndangered() const;

private:
    string cellId;
    string area;
    string location;
    string birthDate;
    bool endangered;
};

#endif /* Habitat_hpp */
