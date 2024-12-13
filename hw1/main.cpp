#include "SmartCity.h"
#include "FileHandler.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    try {
        // 로컬 입력 파일 경로
        string inputFilename = "cityData.txt";
        // 로컬 출력 파일 경로
        string outputFilename = "averages.txt";

       
        vector<SmartCity> cities = loadFromFile(inputFilename);
        vector<City*> cityPointers;
        for (auto& city : cities) {
            cityPointers.push_back(new SmartCity(city));
        }
        for (const City* city : cityPointers) {
            city->displayData(); //자식의 diplay호출
        }
        for (City* city : cityPointers) {
            delete city;
        }
       
        SmartCity combined("total", 0, 0, 0, 0, 0, 0);
        for (int i = 0; i < cities.size(); i++) {
            combined = combined + cities[i];
        }
        cout << "+++++++++++++combined++++++++++++++++++"<<endl;
        combined.displayData();



        map<string, SmartCitySummary> citySummaries = makeCityTotal(cities);


        // 3. 도시별 평균값 출력
        cout << "\nCity Averages:\n";
        for (const auto& pair : citySummaries) {
            const string& cityName = pair.first;
            const SmartCitySummary& summary = pair.second;
            summary.printSummary(cityName);
        }

        // 4. 도시별 평균값을 파일에 저장
        saveAveragesToFile(citySummaries, outputFilename);
        cout << "\nAverages saved to file: " << outputFilename << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
