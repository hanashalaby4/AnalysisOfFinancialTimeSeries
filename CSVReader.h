#ifndef _CSVREADER_
#define _CSVREADER_

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

typedef std::vector<std::pair<std::string, double>> Data;

class CSVReader {
public:
    void readCSV(const std::string& fileName, Data& data);
    double calculateAverage(const Data& data);
    std::pair<std::string, std::string> maxSubsequenceSum(const Data& data);
};

#endif // !_CSVREADER_
