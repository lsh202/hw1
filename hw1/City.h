#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>
using namespace std;

class City {
protected:
    string name;
    int year;
    double electricityConsumption; 
    double trafficCongestion;      
    double wasteGenerated;         
public:
    City(string name, int year, double electricity, double traffic, double waste);
    virtual void displayData() const;
    virtual ~City() {};
    string getName() const { return name; }
    int getYear() const { return year; }
    double getElectricityConsumption() const { return electricityConsumption; }
    double getTrafficCongestion() const { return trafficCongestion; }
    double getWasteGenerated() const { return wasteGenerated; }

};

#endif // CITY_H
