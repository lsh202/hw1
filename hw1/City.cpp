#include "City.h"


City::City(string name, int year, double electricity, double traffic, double waste) {
    //입력데이터가 적절한지 확인
    if (electricity < 0 || traffic < 0 || traffic > 100 || waste < 0) {
        throw invalid_argument("Invalid input values for City object.");
    }
    this->name = name;
    this->year = year;
    this->electricityConsumption = electricity;
    this->trafficCongestion = traffic;
    this->wasteGenerated = waste;
}
// 기본 데이터 출력 메서드
void City::displayData() const {
    cout << "City: " << name << ", Year: " << year
        << ", Electricity: " << electricityConsumption << " GWh"
        << ", Traffic: " << trafficCongestion << "%"
        << ", Waste: " << wasteGenerated << " tons" << endl;
}
