// src/main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "FileProcessor.h"
#include "DynamicList.h"
#include "StaticList.h"
#include "DynamicStack.h"
#include "StaticStack.h"
#include "DynamicQueue.h"
#include "StaticQueue.h"

int main() {
    std::vector<int> dataset_sizes = {100, 1000, 10000, 100000, 1000000};
    std::string base_input_path = "../datasets/ratings";
    std::string base_output_path = "../ordened/";

    FileProcessor processor;

    for (int size : dataset_sizes) {
        std::string input_file = base_input_path + std::to_string(size) + ".csv";

        // Processar com DynamicList
        std::unique_ptr<IDataStructure> dynamicList = std::make_unique<DynamicList>();
        std::string output_dynamic_list = base_output_path + "dynamicList/ratings" + std::to_string(size) + ".csv";
        processor.processFile(std::move(dynamicList), input_file, output_dynamic_list);

        // Processar com StaticList
        // Nota: Certifique-se de que MAX_STATIC_SIZE em StaticList.h é >= ao maior tamanho de dataset.
        std::unique_ptr<IDataStructure> staticList = std::make_unique<StaticList>();
        std::string output_static_list = base_output_path + "staticList/ratings" + std::to_string(size) + ".csv";
        processor.processFile(std::move(staticList), input_file, output_static_list);

        // Processar com DynamicStack
        std::unique_ptr<IDataStructure> dynamicStack = std::make_unique<DynamicStack>();
        std::string output_dynamic_stack = base_output_path + "dynamicStack/ratings" + std::to_string(size) + ".csv";
        processor.processFile(std::move(dynamicStack), input_file, output_dynamic_stack);

        // Processar com StaticStack
        std::unique_ptr<IDataStructure> staticStack = std::make_unique<StaticStack>();
        std::string output_static_stack = base_output_path + "staticStack/ratings" + std::to_string(size) + ".csv";
        processor.processFile(std::move(staticStack), input_file, output_static_stack);

        // Processar com DynamicQueue
        std::unique_ptr<IDataStructure> dynamicQueue = std::make_unique<DynamicQueue>();
        std::string output_dynamic_queue = base_output_path + "dynamicQueue/ratings" + std::to_string(size) + ".csv";
        processor.processFile(std::move(dynamicQueue), input_file, output_dynamic_queue);

        // Processar com StaticQueue
        std::unique_ptr<IDataStructure> staticQueue = std::make_unique<StaticQueue>();
        std::string output_static_queue = base_output_path + "staticQueue/ratings" + std::to_string(size) + ".csv";
        processor.processFile(std::move(staticQueue), input_file, output_static_queue);
    }

    return 0;
}


