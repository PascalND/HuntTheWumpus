#pragma once
#include "Room.h"
#include "RandomGenerator.h"
#include "Cave.h"

namespace HtW
{

void golbinMove(Room& currentGoblinRoom, RandomGenerator& m_pRandom, Cave& m_pCave);
void doGolbinMove(Room& currentGoblinRoom, RandomGenerator& m_pRandom, Cave& m_pCave);

}