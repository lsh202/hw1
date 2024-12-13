#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <map>
#include <vector>
#include <string>
#include "SmartCity.h"

struct SmartCitySummary {
    int count;                         
    double totalElectricity;          
    double totalTraffic;                 
    double totalWaste;                   
    double totalRenewable;               
    double totalFacility;                

    // 평균 계산 함수
    void printSummary(const string& cityName) const {
        cout << "City: " << cityName << endl;
        cout << "Average Electricity Consumption: " << totalElectricity / count << " GWh" << endl;
        cout << "Average Traffic Congestion: " << totalTraffic / count << " %" << endl;
        cout << "Average Waste Generated: " << totalWaste / count << " tons" << endl;
        cout << "Average Renewable Energy: " << totalRenewable / count << " %" << endl;
        cout << "Average Smart Devices Per Capita: " << totalFacility / count << endl;
    }
};

void saveAveragesToFile(const map<string, SmartCitySummary>& citySummaries, const string& filename); //평균을 계산해서 저장하는 함수
vector<SmartCity> loadFromFile(const string& filename); //데이터로드함수
map<string, SmartCitySummary> makeCityTotal(const vector<SmartCity>& cities);
#endif // FILEHANDLER_H
