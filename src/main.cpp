#include "Interconnect.hpp"
#include <fstream>
#include <cstdint>
#include <string>
#include <memory>
#include <sstream>

int main(int argc, char* argv[]) {
    std::ifstream input = std::ifstream("input-big.txt");
    std::stringstream ss = std::stringstream();
    std::unique_ptr<Interconnect> interconnect = std::make_unique<Interconnect>();
    for(std::string line; getline(input, line);) {
        uint32_t address = stoi(line);
        uint32_t offset = interconnect->load(address);
        ss << std::dec << address;
        ss << ",";
        ss << std::dec << offset;
        ss << "\n";
    }
    std::ofstream myfile = std::ofstream();
    myfile.open("output.txt");
    myfile << ss.str();
    myfile.close();
    return 0;
}
