#include "HuntTheWumpus.h"
#include "DeepPitRoomEnteredMsg.h"
#include "EndProgramMsg.h"
#include "GameLoopImpl.h"
#include "InitCaveMsg.h"
#include "InvalidRoomMsg.h"
#include "MoveMsg.h"
#include "ShootMsg.h"
#include "UpdateArrowLevelMsg.h"
#include "SuperBatRoomEnteredMsg.h"
#include "UserInputMsg.h"
#include "WumpusRoomEnteredMsg.h"
#include "ArrowRoomEnteredMsg.h"
#include "GoblinRoomEnteredMsg.h"

namespace HtW
{
HuntTheWumpus::HuntTheWumpus(RandomGenerator* pg)
  : m_pRandom(pg)
{
    InitMessageIDs();
    RegisterMessageHandler();
}

void HuntTheWumpus::Run()
{
    m_Loop.Push(new InitCaveMsg());
    m_Loop.Run();
}

void HuntTheWumpus::InitMessageIDs()
{
    EndProgramMsg::ID          = 0;
    UserInputMsg::ID           = 1;
    InitCaveMsg::ID            = 2;
    MoveMsg::ID                = 3;
    RoomEnteredMsg::ID         = 4;
    WumpusRoomEnteredMsg::ID   = 5;
    SuperBatRoomEnteredMsg::ID = 6;
    DeepPitRoomEnteredMsg::ID  = 7;
    GoblinRoomEnteredMsg::ID   = 8;
    ArrowRoomEnteredMsg::ID    = 9;
    InvalidRoomMsg::ID         = 10;
    ShootMsg::ID               = 11;
    UpdateArrowLevelMsg::ID    = 12;

    // TODO: Für jede weitere Message die ID hier aufsteigend zuweisen
}

void HuntTheWumpus::RegisterMessageHandler()
{
    m_Loop.SetHandlerCount(13);
    m_Loop.RegisterHandler(EndProgramMsg::ID, new EndProgramMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(UserInputMsg::ID, new UserInputMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(InitCaveMsg::ID, new InitCaveMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(MoveMsg::ID, new MoveMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(RoomEnteredMsg::ID, new RoomEnteredMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(WumpusRoomEnteredMsg::ID, new WumpusRoomEnteredMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(SuperBatRoomEnteredMsg::ID, new SuperBatRoomEnteredMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(DeepPitRoomEnteredMsg::ID, new DeepPitRoomEnteredMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(GoblinRoomEnteredMsg::ID, new GoblinRoomEnteredMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(ArrowRoomEnteredMsg::ID, new ArrowRoomEnteredMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(InvalidRoomMsg::ID, new InvalidRoomMsgHandler());
    m_Loop.RegisterHandler(ShootMsg::ID, new ShootMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    m_Loop.RegisterHandler(UpdateArrowLevelMsg::ID, new UpdateArrowLevelMsgHandler(&m_Cave, &m_Loop, m_pRandom, &m_arrows));
    // TODO: Für jede weitere Message den handler hier anbinden und den handler count erhöhen
}

} // namespace HtW
