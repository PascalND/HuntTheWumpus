#pragma once
#include "GameLoopImpl.h"
#include "RandomGenerator.h"
#include "Cave.h"

namespace HtW
{
	class HuntTheWumpus
	{
	public:
		explicit HuntTheWumpus(RandomGenerator*);
		void Run();

	private:
		void InitMessageIDs();
		void RegisterMessageHandler();
		Cave m_Cave{};
		GameLoopImpl m_Loop{};
		RandomGenerator* m_pRandom;
        int              m_arrows;
	};
} // namespace HtW
