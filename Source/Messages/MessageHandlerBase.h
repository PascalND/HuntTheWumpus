#pragma once
#include "Message.h"
#include "Cave.h"
#include "GameLoop.h"
#include "RandomGenerator.h"

namespace HtW
{
	class MessageHandlerBase : public MessageHandler
	{
    public:
        MessageHandlerBase(Cave* cave, GameLoop* gameLoop, RandomGenerator* random, int* arrows)
          : m_pCave(cave)
          , m_pGameLoop(gameLoop)
          , m_pRandom(random)
          , m_arrows(arrows)
            
        {
        }

    protected:
        Cave* m_pCave;
        GameLoop* m_pGameLoop;
        RandomGenerator* m_pRandom;
        int*             m_arrows;
	};
}