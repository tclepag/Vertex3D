//
// Created by lepag on 1/12/2025.
//

#include "Pipeline.h"
#include <fstream>
#include <iostream>

namespace Vertex3D {
    std::vector<char> Pipeline::readFile(const std::string &filePath) {
        std::ifstream file(filePath, std::ios::ate | std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Failed to open file " << filePath << std::endl;
            return std::vector<char>();
        }

        size_t fileSize = file.tellg();
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    Pipeline::Pipeline(const std::string &vertPath, const std::string &fragPath) {
        this->createGraphicsPipeline(vertPath, fragPath);
    }


    void Pipeline::createGraphicsPipeline(const std::string &vertPath, const std::string &fragPath) {
        auto vertCode = readFile(vertPath);
        auto fragCode = readFile(fragPath);
        std::cout << "Vertex File Size" << vertCode.size() << std::endl;
        std::cout << "Fragment File Size" << fragCode.size() << std::endl;
    }


} // Vertex3D