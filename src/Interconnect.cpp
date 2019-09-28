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

Interconnect::Interconnect() {}

Interconnect::~Interconnect() {}

uint32_t Interconnect::maskRegion(uint32_t address) const {
    uint8_t index = address >> 29;
    return address & regionMask[index];
}

uint32_t Interconnect::load(uint32_t address) const {
    uint32_t absoluteAddress = maskRegion(address);

    std::optional<uint32_t> offset = biosRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = ramRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = interruptRequestControlRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = dmaRegisterRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = gpuRegisterRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = timer0RegisterRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = timer1RegisterRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = timer2RegisterRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = expansion1Range.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = soundProcessingUnitRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = scratchpadRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = cdromRegisterRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    offset = controllerRegisterRange.contains(absoluteAddress);
    if (offset) {
        return (*offset);
    }
    return 0;
}
