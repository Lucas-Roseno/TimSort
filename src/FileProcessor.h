#pragma once

#include <string>
#include "IDataStructure.h"
#include "Timestamp.h"

/**
 * @class FileProcessor
 * @brief Classe responsável por ler os dados de entrada, orquestrar a ordenação
 * e escrever os resultados em um arquivo de saída.
 */
class FileProcessor {
public:
    /**
     * @brief Processa um arquivo de entrada, carrega os dados em uma estrutura,
     * ordena a estrutura e salva o resultado.
     * @param dataStructure Ponteiro para a estrutura de dados a ser utilizada.
     * @param inputPath Caminho para o arquivo de entrada CSV.
     * @param outputPath Caminho para o arquivo de saída CSV.
     */
    void processAndSort(IDataStructure<Timestamp>* dataStructure, const std::string& inputPath, const std::string& outputPath);
};