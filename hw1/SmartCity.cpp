#include "SmartCity.h"

// 상속 클래스 생성자
SmartCity::SmartCity(string name, int year, double electricity, double traffic, double waste, double renewable, double facility)
    : City("", 0, 0.0, 0.0, 0.0) {  // 기반 클래스의 기본 생성자를 호출
    this->name = name;  
    this->year = year;
    this->electricityConsumption = electricity;
    this->trafficCongestion = traffic;
    this->wasteGenerated = waste;
    this->renewableEnergy = renewable;
    this->numOfFacility = facility;
}

// 상속된 데이터 출력 메서드
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
