#include "CSVReader.h"

void CSVReader::readCSV(const std::string& fileName, Data& data) {
    std::ifstream file(fileName);
    std::string line, cell;
    
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string date;
        double rate;
        std::getline(lineStream, date, ',');
        lineStream >> rate;
        data.emplace_back(date, rate);
    }
}

double CSVReader::calculateAverage(const Data& data) {
    double sum = 0.0;
    for (size_t i = 0; i < data.size(); ++i) {
        const auto& entry = data[i];
        sum += entry.second;
    }
    return sum / data.size();
}

std::pair<std::string, std::string> CSVReader::maxSubsequenceSum(const Data& data) {
    double maxSum = 0.0;
    double currentSum = 0.0;
    std::pair<std::string, std::string> maxPeriod;

    int start = 0;
    int currentStart = 0;

    for (int i = 0; i < data.size(); ++i) {
        currentSum += data[i].second;

        if (currentSum < 0) {
            currentSum = 0;
            currentStart = i + 1;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxPeriod.first = data[currentStart].first;
            maxPeriod.second = data[i].first;
        }
    }

    return maxPeriod;
}
