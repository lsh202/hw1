#include "City.h"


City::City(string name, int year, double electricity, double traffic, double waste) {
    //�Էµ����Ͱ� �������� Ȯ��
    if (electricity < 0 || traffic < 0 || traffic > 100 || waste < 0) {
        throw invalid_argument("Invalid input values for City object.");
    }
    this->name = name;
    this->year = year;
    this->electricityConsumption = electricity;
    this->trafficCongestion = traffic;
    this->wasteGenerated = waste;
}
// �⺻ ������ ��� �޼���
void City::displayData() const {
    cout << "City: " << name << ", Year: " << year
        << ", Electricity: " << electricityConsumption << " GWh"
        << ", Traffic: " << trafficCongestion << "%"
        << ", Waste: " << wasteGenerated << " tons" << endl;
}
