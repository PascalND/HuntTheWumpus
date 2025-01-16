#include "RandomGeneratorImpl.h"
#include "RandomGenerator.h"
#include <random>

int* HtW::RandomGeneratorImpl::GenerateShuffled(const Range& range) const
{
    int* shuffledArray = new int[range.max - range.min + 1];
    for (int i = range.min; i <= range.max; i++)
    {
        shuffledArray[i - range.min] = i;
    }
    std::random_device random;
    std::mt19937       g(random());
    std::shuffle(shuffledArray, shuffledArray + range.max - range.min + 1, g);
    return shuffledArray;
}

int HtW::RandomGeneratorImpl::GenerateUnique(const Range& range) const
{
    std::random_device random;
    return random() % (range.max - range.min + 1) + range.min;
}
