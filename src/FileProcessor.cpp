#include "FileProcessor.h"
#include "Timestamp.h"
#include "TimSort.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

void FileProcessor::processAndSort(IDataStructure<Timestamp>* dataStructure, const std::string& inputPath, const std::string& outputPath) {
    std::ifstream file(inputPath);
    if (!file.is_open()) {
        std::cerr << "Error opening input file: " << inputPath << std::endl;
        return;
    }

    std::string line;
    std::cout << "Reading data from " << inputPath << "..." << std::endl;
    
    // O novo formato não tem cabeçalho, então a leitura começa da primeira linha.
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        try {
            long long timestamp_val = std::stoll(line);
            dataStructure->push(Timestamp(timestamp_val));
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Skipping invalid line (not a number): " << line << std::endl;
        } catch (const std::out_of_range& oor) {
            std::cerr << "Skipping invalid line (number out of range): " << line << std::endl;
        }
    }
    file.close();
    std::cout << "Finished reading data. " << dataStructure->size() << " records loaded." << std::endl;

    std::cout << "Sorting the data structure directly..." << std::endl;
    TimSort<Timestamp> sorter;
    sorter.sort(dataStructure);
    std::cout << "Sort finished." << std::endl;

    std::cout << "Writing sorted data to " << outputPath << "..." << std::endl;
    std::ofstream outFile(outputPath);
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file: " << outputPath << std::endl;
        return;
    }

    // Escreve os dados ordenados, um timestamp por linha.
    for (int i = 0; i < dataStructure->size(); ++i) {
        outFile << dataStructure->get(i) << "\n";
    }

    outFile.close();
    std::cout << "Finished writing to " << outputPath << std::endl;
}