//
// Created by lepag on 1/12/2025.
//

#ifndef PIPELINE_H
#define PIPELINE_H

#include <string>
#include <vector>

namespace Vertex3D {

class Pipeline {
public:
    Pipeline(const std::string& vertPath, const std::string& fragPath);
private:
    static std::vector<char> readFile(const std::string& filePath);
    void createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath);
};

} // Vertex3D

#endif //PIPELINE_H
