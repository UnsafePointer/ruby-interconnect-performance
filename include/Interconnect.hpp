#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Range.hpp"
#include <optional>
#include <tuple>

class Interconnect {
    std::vector<Range> allRanges;

    uint32_t maskRegion(uint32_t address) const;
    std::optional<Range> binarySearch(uint32_t address, std::vector<Range> const *ranges, uint32_t bottom, uint32_t top) const;
public:
    Interconnect();
    ~Interconnect();

    uint32_t load(uint32_t address) const;
};
