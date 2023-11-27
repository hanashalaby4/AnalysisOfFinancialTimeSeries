#include "CSVReader.h"
#include "HeapClass.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Node.h"

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>

typedef std::vector<std::pair<std::string, double>> Data;

int main() {
    CSVReader reader;
    Data exchangeRates;

    reader.readCSV("euro-dollar.csv", exchangeRates);

    if (exchangeRates.empty()) {
        std::cout << "Error loading data.\n";
        exit(0);
    }

    double averageRate = reader.calculateAverage(exchangeRates);

    maxHeap MaxHeap(7000);
    minHeap MinHeap(7000);
    int N = 10; 

    std::vector<Node> nodes = createNodes(exchangeRates, averageRate);

        for (const auto& node : nodes) {
       
            MaxHeap.insertKey(node);
            MinHeap.insertKey(node);
      
    }

    std::cout << "Top " << N << " highest exchange rates:\n";
    for (int i = 0; i < N; ++i) {
        if (!MaxHeap.getNodes().empty()) {
            try {
                Node max = MaxHeap.extractMax();
                std::cout << "Date: " << max.date << ", Change in rate: " << max.rateChange << "\n";
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << "\n";
                break;
            }
        }
    }

    std::cout << "Top " << N << " lowest exchange rates:\n";
    for (int i = 0; i < N; ++i) {
        if (!MinHeap.getNodes().empty()) {
            try {
                Node min = MinHeap.extractMin();
                std::cout << "Date: " << min.date << ", Change in rate: " << min.rateChange << "\n";
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << "\n";
                break;
            }
        }
    }

    std::pair<std::string, std::string> periodOfMaxRates = reader.maxSubsequenceSum(exchangeRates);

    std::cout << "Maximum Subsequence Sum Period:\n";
    std::cout << "Start date: " << periodOfMaxRates.first << ", End date: " << periodOfMaxRates.second;

    return 0;
}
