#pragma once
#include <cstdint>
#include <optional>
#include <tuple>

class Range {
    uint32_t start;
    uint32_t length;
public:
    Range(uint32_t start, uint32_t length);
    ~Range();

    int32_t contains(uint32_t address) const;
    uint32_t offset(uint32_t address) const;
};
