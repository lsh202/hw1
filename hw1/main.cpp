#include "SmartCity.h"
#include "FileHandler.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    try {
        // ���� �Է� ���� ���
        string inputFilename = "cityData.txt";
        // ���� ��� ���� ���
        string outputFilename = "averages.txt";

       
        vector<SmartCity> cities = loadFromFile(inputFilename);
        vector<City*> cityPointers;
        for (auto& city : cities) {
            cityPointers.push_back(new SmartCity(city));
        }
        for (const City* city : cityPointers) {
            city->displayData(); //�ڽ��� diplayȣ��
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


        // 3. ���ú� ��հ� ���
        cout << "\nCity Averages:\n";
        for (const auto& pair : citySummaries) {
            const string& cityName = pair.first;
            const SmartCitySummary& summary = pair.second;
            summary.printSummary(cityName);
        }

        // 4. ���ú� ��հ��� ���Ͽ� ����
        saveAveragesToFile(citySummaries, outputFilename);
        cout << "\nAverages saved to file: " << outputFilename << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
