#include "SmartCity.h"

// ��� Ŭ���� ������
SmartCity::SmartCity(string name, int year, double electricity, double traffic, double waste, double renewable, double facility)
    : City("", 0, 0.0, 0.0, 0.0) {  // ��� Ŭ������ �⺻ �����ڸ� ȣ��
    this->name = name;  
    this->year = year;
    this->electricityConsumption = electricity;
    this->trafficCongestion = traffic;
    this->wasteGenerated = waste;
    this->renewableEnergy = renewable;
    this->numOfFacility = facility;
}

// ��ӵ� ������ ��� �޼���
void SmartCity::displayData() const {
    City::displayData();
    cout << "Renewable Energy: " << renewableEnergy << "%"
        << ", Number of facility: " << numOfFacility << endl;
}

SmartCity SmartCity::operator+(const SmartCity& other) const {
    return SmartCity(
        name, year,
        electricityConsumption + other.electricityConsumption,
        trafficCongestion + other.trafficCongestion,
        wasteGenerated + other.wasteGenerated,
        renewableEnergy + other.renewableEnergy,
        numOfFacility + other.numOfFacility
    );
}
