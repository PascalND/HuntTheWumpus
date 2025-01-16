#pragma once
#include "RandomGenerator.h"

namespace HtW
{
class RandomGeneratorImpl : public RandomGenerator
{
    // Geerbt über RandomGenerator
    virtual int* GenerateShuffled(const Range&) const override;
    virtual int  GenerateUnique(const Range&) const override;
};
}
