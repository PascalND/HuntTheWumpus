#pragma once
#include "RandomGenerator.h"

namespace HtW
{
class RandomGeneratorImpl : public RandomGenerator
{
    // Geerbt �ber RandomGenerator
    virtual int* GenerateShuffled(const Range&) const override;
    virtual int  GenerateUnique(const Range&) const override;
};
}
