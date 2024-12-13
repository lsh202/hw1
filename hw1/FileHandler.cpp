#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <iomanip> //데이터 출력 정렬


void saveAveragesToFile(const map<string, SmartCitySummary>& citySummaries, const string& filename) {
    ofstream file(filename);
    if (!file) {
        throw runtime_error("Unable to open file for writing");
    }

    // 테이블 열
    file << setw(15) << "City" << setw(20) << "Avg Electricity"
        << setw(20) << "Avg Traffic" << setw(20) << "Avg Waste"
        << setw(25) << "Avg Renewable Energy" << setw(20) << "Avg Facility" << endl;

    // 도시별 평균값 저장
    for (const auto& pair : citySummaries) {
        const string& cityName = pair.first;
        const SmartCitySummary& summary = pair.second;

        // 평균 계산 및 저장
        file << setw(15) << cityName
            << setw(20) << summary.totalElectricity / summary.count
            << setw(20) << summary.totalTraffic / summary.count
            << setw(20) << summary.totalWaste / summary.count
            << setw(25) << summary.totalRenewable / summary.count
            << setw(20) << summary.totalFacility / summary.count << endl;
    }

    file.close();
}



vector<SmartCity> loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("파일을 열 수 없습니다.");
    }

    vector<SmartCity> cities;
    string line;
    bool isFirstLine = true; // 첫 줄인지 여부를 추적하는 변수 

    while (getline(file, line)) {
        if (isFirstLine) { 
            isFirstLine = false;
            continue;
        }

        string name = "";
        string temp = "";
        int year = 0;
        double electricity = 0.0, traffic = 0.0, waste = 0.0, renewable = 0.0, facility = 0.0;

        size_t pos = 0;

        for (char c : line) {
            if (c == '\t' || c == ' ') {
                if (!temp.empty()) {
                    try {
                        if (pos == 0) name = temp;
                        else if (pos == 1) year = stoi(temp);
                        else if (pos == 2) electricity = stod(temp);
                        else if (pos == 3) traffic = stod(temp);
                        else if (pos == 4) waste = stod(temp);
                        else if (pos == 5) renewable = stod(temp);
                        else if (pos == 6) facility = stod(temp);
                    }
                    catch (const invalid_argument& e) {
                        cerr << "Invalid data format: " << temp << endl;
                        throw runtime_error("제대로 파싱하지 못했습니다: " + line);
                    }
                    temp.clear();
                    ++pos;
                }
            }
            else {
                temp += c;
            }
        }
        if (!temp.empty() && pos == 6) {  // 마지막 항목만 처리, 공백이 있어야 데이터를 삽입하는데 마지막 요소는 공백이 없음
            try {
                facility = stod(temp);
            }
            catch (const invalid_argument& e) {
                cerr << "Invalid data format: " << temp << endl;
                throw runtime_error("파싱에 실패했습니다 " + line);
            }
        }
        SmartCity city(name, year, electricity, traffic, waste, renewable, facility);
        cities.push_back(city);
    }

    file.close();
    return cities;
}



map<string, SmartCitySummary> makeCityTotal(const vector<SmartCity>& cities) {
    map<string, SmartCitySummary> citySummaries;

    for (const auto& city : cities) {
        string name = city.getName();
        if (citySummaries.find(name) == citySummaries.end()) { //도시 이름이 있는지 확인 만약 없으면 end를 반환함
            citySummaries[name] = { 0, 0.0, 0.0, 0.0, 0.0, 0.0 }; //해당 도시가 처음 들어온거라면 0으로 초기화하며 생성
        }

        citySummaries[name].count++;
        citySummaries[name].totalElectricity += city.getElectricityConsumption();
        citySummaries[name].totalTraffic += city.getTrafficCongestion();
        citySummaries[name].totalWaste += city.getWasteGenerated();
        citySummaries[name].totalRenewable += city.getRenewableEnergy();
        citySummaries[name].totalFacility += city.getNumberOffFacility();
    }

    return citySummaries; // 결과 반환
}



