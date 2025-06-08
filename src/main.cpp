#include <iostream>
#include <vector>
#include <string>

// Inclui todas as estruturas de dados e classes necessárias
#include "FileProcessor.h"
#include "IDataStructure.h"
#include "Timestamp.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticStack.h"
#include "DynamicStack.h"
#include "StaticQueue.h"
#include "DynamicQueue.h"

/**
 * @brief Função auxiliar para executar o processo de ordenação para uma estrutura de dados específica.
 * * @param dataStructure Ponteiro para a estrutura de dados a ser testada.
 * @param structureName Nome da estrutura (usado para criar os diretórios de saída).
 * @param sizes Vetor com os diferentes tamanhos de datasets a serem testados.
 * @param inputBasePath Caminho base para os arquivos de entrada.
 * @param outputBasePath Caminho base para os arquivos de saída.
 */
void runForStructure(
    IDataStructure<Timestamp>* dataStructure,
    const std::string& structureName,
    const std::vector<int>& sizes,
    const std::string& inputBasePath,
    const std::string& outputBasePath)
{
    std::cout << "========================================\n";
    std::cout << "Iniciando processamento para: " << structureName << "\n";
    std::cout << "========================================\n";

    FileProcessor processor;

    for (int size : sizes) {
        // Limpa a estrutura de dados para garantir que esteja vazia para o próximo arquivo
        dataStructure->clear();

        std::string inputFile = inputBasePath + "ratings" + std::to_string(size) + ".csv";
        std::string outputFile = outputBasePath + structureName + "/ratings" + std::to_string(size) + ".csv";

        // Chama o método correto do FileProcessor, passando o ponteiro para a estrutura
        processor.processAndSort(dataStructure, inputFile, outputFile);
        std::cout << "----------------------------------------\n";
    }
}

int main() {
    // Define os tamanhos dos datasets e os caminhos base
    std::vector<int> datasetSizes = {100, 1000, 10000, 100000, 1000000};
    std::string inputPath = "datasets/";
    std::string outputPath = "ordened/";

    // --- Cria uma instância de cada uma das 6 estruturas de dados ---
    StaticList<Timestamp> staticList;
    DynamicList<Timestamp> dynamicList;
    StaticStack<Timestamp> staticStack;
    DynamicStack<Timestamp> dynamicStack;
    StaticQueue<Timestamp> staticQueue;
    DynamicQueue<Timestamp> dynamicQueue;

    // --- Executa o processo para cada estrutura ---
    // Nota: Certifique-se que os diretórios de saída (ex: "ordened/staticList/") existem
    // antes de rodar o programa.
    
    runForStructure(&staticList, "staticList", datasetSizes, inputPath, outputPath);
    runForStructure(&dynamicList, "dynamicList", datasetSizes, inputPath, outputPath);
    runForStructure(&staticStack, "staticStack", datasetSizes, inputPath, outputPath);
    runForStructure(&dynamicStack, "dynamicStack", datasetSizes, inputPath, outputPath);
    runForStructure(&staticQueue, "staticQueue", datasetSizes, inputPath, outputPath);
    runForStructure(&dynamicQueue, "dynamicQueue", datasetSizes, inputPath, outputPath);

    std::cout << "Todos os processamentos foram finalizados." << std::endl;

    return 0;
}