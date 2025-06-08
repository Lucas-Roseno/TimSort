// src/FileProcessor.cpp
#include "FileProcessor.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>

// Processa um arquivo CSV com uma estrutura de dados específica
void FileProcessor::processFile(std::unique_ptr<IDataStructure> dataStructure, const std::string& inputFilePath, const std::string& outputFilePath) {
    std::cout << "Processing file: " << inputFilePath << " with structure..." << std::endl;

    // 1. Ler dados do CSV para a estrutura de dados
    readCsv(*dataStructure, inputFilePath);

    // 2. Converter estrutura para vetor para ordenação
    std::vector<Timestamp> data = dataStructure->toVector();

    // 3. Ordenar o vetor usando TimSort e medir o tempo
    auto start_time = std::chrono::high_resolution_clock::now();
    TimSort::sort(data);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Sorting time: " << elapsed.count() << " seconds" << std::endl;

    // 4. Escrever dados ordenados de volta para um novo CSV
    writeCsv(data, outputFilePath);

    // 5. Limpar a estrutura de dados para o próximo uso
    dataStructure->clear();

    std::cout << "Processing complete. Output saved to: " << outputFilePath << std::endl;
}

// Lê timestamps de um arquivo CSV e os adiciona à estrutura de dados
void FileProcessor::readCsv(IDataStructure& dataStructure, const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening input file: " << filePath << std::endl;
        return;
    }

    std::string line;
    
    // Ler timestamps linha por linha
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        try {
            long long timestamp_value = std::stoll(line);
            dataStructure.add(Timestamp(timestamp_value));
        } catch (const std::exception& e) {
            std::cerr << "Error converting line to long long: " << line << " - " << e.what() << std::endl;
        }
    }

    file.close();
}

// Escreve timestamps ordenados de um vetor para um arquivo CSV
void FileProcessor::writeCsv(const std::vector<Timestamp>& data, const std::string& filePath) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening output file: " << filePath << std::endl;
        return;
    }

    // Escrever cabeçalho
    file << "timestamp\n";

    // Escrever timestamps ordenados
    for (const auto& ts : data) {
        file << ts.value << "\n";
    }

    file.close();
}


