#pragma once

namespace HtW
{
	struct Range
	{
		int min;
		int max;
	};

	class RandomGenerator
	{
	public:
		// Gibt alle Zahlen in dem angegebenen Bereich [min, max] zufällig durcheinander zurück
		// Das Array muss nach der Nutzung gelöscht werden
		virtual int* GenerateShuffled(const Range&) const = 0;
		// Gibt eine zufällige Zahl aus dem Bereich zurück
		virtual int GenerateUnique(const Range&) const = 0;
		virtual ~RandomGenerator() = default;

    };
    } // namespace HtW
