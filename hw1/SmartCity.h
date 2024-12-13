#ifndef SMARTCITY_H
#define SMARTCITY_H

#include "City.h"

class SmartCity : public City {
private:
    double renewableEnergy;       
    double numOfFacility;   
public:
    SmartCity(string name, int year, double electricity, double traffic, double waste, double renewable, double facility);
    void displayData() const override;
    double getRenewableEnergy() const { return renewableEnergy; }
    double getNumberOffFacility() const { return numOfFacility; }
    SmartCity operator+(const SmartCity& other) const;

};
#endif // SMARTCITY_H
