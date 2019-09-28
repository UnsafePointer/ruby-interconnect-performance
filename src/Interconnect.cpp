#include "Interconnect.hpp"
#include "Range.hpp"

using namespace std;

const uint32_t regionMask[8] = {
    // KUSEG: 2048MB
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    // KSEG0: 512MB
    0x7fffffff,
    // KSEG1: 512MB
    0x1fffffff,
    // KSEG2: 1024MB
    0xffffffff, 0xffffffff,
};

Interconnect::Interconnect() : allRanges() {
    Range ramRange                     = Range(0x00000000, 2*1024*1024);
    Range expansion1Range              = Range(0x1f000000, 512*1024);
    Range scratchpadRange              = Range(0x1f800000, 1024);
    Range memoryControlRange           = Range(0x1f801000, 36);
    Range controllerRegisterRange      = Range(0x1f801040, 16);
    Range ramSizeRange                 = Range(0x1f801060, 4);
    Range interruptRequestControlRange = Range(0x1f801070, 8);
    Range dmaRegisterRange             = Range(0x1f801080, 0x80);
    Range timer0RegisterRange          = Range(0x1f801100, 16);
    Range timer1RegisterRange          = Range(0x1f801110, 16);
    Range timer2RegisterRange          = Range(0x1f801120, 16);
    Range cdromRegisterRange           = Range(0x1f801800, 4);
    Range gpuRegisterRange             = Range(0x1f801810, 8);
    Range soundProcessingUnitRange     = Range(0x1f801c00, 640);
    Range expansion2Range              = Range(0x1f802000, 66);
    Range biosRange                    = Range(0x1fc00000, 512 * 1024);
    Range cacheControlRange            = Range(0xfffe0130, 4);


    allRanges.push_back(ramRange);
    allRanges.push_back(expansion1Range);
    allRanges.push_back(scratchpadRange);
    allRanges.push_back(memoryControlRange);
    allRanges.push_back(controllerRegisterRange);
    allRanges.push_back(ramSizeRange);
    allRanges.push_back(interruptRequestControlRange);
    allRanges.push_back(dmaRegisterRange);
    allRanges.push_back(timer0RegisterRange);
    allRanges.push_back(timer1RegisterRange);
    allRanges.push_back(timer2RegisterRange);
    allRanges.push_back(cdromRegisterRange);
    allRanges.push_back(gpuRegisterRange);
    allRanges.push_back(soundProcessingUnitRange);
    allRanges.push_back(expansion2Range);
    allRanges.push_back(biosRange);
    allRanges.push_back(cacheControlRange);
}

Interconnect::~Interconnect() {}

uint32_t Interconnect::maskRegion(uint32_t address) const {
    uint8_t index = address >> 29;
    return address & regionMask[index];
}

std::optional<Range> Interconnect::binarySearch(uint32_t address, std::vector<Range> const *ranges, uint32_t bottom, uint32_t top) const {
    if (ranges->size() < 1) {
        return nullopt;
    }

    uint32_t size = top - bottom;
    uint32_t middle = size / 2;
    Range range = ranges->at(middle);
    int32_t result = range.contains(address);
    if (result == 0) {
        return { range };
    }
    if (size == 1) {
        return nullopt;
    }
    if (result < 0) { // bottom half
        return binarySearch(address, ranges, bottom, bottom + middle);
    } else { // top half
        return binarySearch(address, ranges, bottom + middle, top);
    }
}

uint32_t Interconnect::load(uint32_t address) const {
    uint32_t absoluteAddress = maskRegion(address);
    optional<Range> range = binarySearch(address, &allRanges, 0, allRanges.size());
    if (range != nullopt) {
        return (*range).offset(absoluteAddress);
    } else {
        return 0;
    }
}
