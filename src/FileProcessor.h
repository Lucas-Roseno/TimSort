// src/FileProcessor.h
#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>
#include <vector>
#include <memory>
#include "IDataStructure.h"
#include "Timestamp.h"
#include "TimSort.h"

// Classe responsável por ler, ordenar e escrever arquivos CSV
class FileProcessor {
public:
    // Processa um arquivo CSV com uma estrutura de dados específica
    // dataStructure: ponteiro para a estrutura de dados a ser usada (polimorfismo)
    // inputFilePath: caminho completo para o arquivo CSV de entrada
    // outputFilePath: caminho completo para o arquivo CSV de saída
    void processFile(std::unique_ptr<IDataStructure> dataStructure, const std::string& inputFilePath, const std::string& outputFilePath);

private:
    // Lê timestamps de um arquivo CSV e os adiciona à estrutura de dados
    void readCsv(IDataStructure& dataStructure, const std::string& filePath);

    // Escreve timestamps ordenados de um vetor para um arquivo CSV
    void writeCsv(const std::vector<Timestamp>& data, const std::string& filePath);
};

#endif // FILE_PROCESSOR_H

