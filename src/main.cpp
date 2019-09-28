#include "Interconnect.hpp"
#include <fstream>
#include <cstdint>
#include <string>
#include <memory>

int main(int argc, char* argv[]) {
    std::ifstream input = std::ifstream("input.txt");
    std::unique_ptr<Interconnect> interconnect = std::make_unique<Interconnect>();
    for(std::string line; getline(input, line);) {
        uint32_t address = stoi(line);
        std::string result = interconnect->load(address);
    }
    return 0;
}
