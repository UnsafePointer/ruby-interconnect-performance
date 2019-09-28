#pragma once
#include <memory>
#include <string>
#include "Range.hpp"

const Range ramRange = Range(0x00000000, 2*1024*1024);
const Range scratchpadRange = Range(0x1f800000, 1024);
const Range biosRange = Range(0x1fc00000, 512 * 1024);
const Range memoryControlRange = Range(0x1f801000, 36);
const Range ramSizeRange = Range(0x1f801060, 4);
const Range cacheControlRange = Range(0xfffe0130, 4);
const Range soundProcessingUnitRange = Range(0x1f801c00, 640);
const Range expansion2Range = Range(0x1f802000, 66);
const Range expansion1Range = Range(0x1f000000, 512*1024);
const Range interruptRequestControlRange = Range(0x1f801070, 8);
const Range timer0RegisterRange = Range(0x1f801100, 16);
const Range timer1RegisterRange = Range(0x1f801110, 16);
const Range timer2RegisterRange = Range(0x1f801120, 16);
const Range dmaRegisterRange = Range(0x1f801080, 0x80);
const Range gpuRegisterRange = Range(0x1f801810, 8);
const Range cdromRegisterRange = Range(0x1f801800, 4);
const Range controllerRegisterRange = Range(0x1f801040, 16);

class Interconnect {
    uint32_t maskRegion(uint32_t address) const;
public:
    Interconnect();
    ~Interconnect();

    uint32_t load(uint32_t address) const;
};
