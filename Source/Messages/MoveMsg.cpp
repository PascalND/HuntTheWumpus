#include "MoveMsg.h"
#include "ArrowRoomEnteredMsg.h"
#include "DeepPitRoomEnteredMsg.h"
#include "InvalidRoomMsg.h"
#include "SuperBatRoomEnteredMsg.h"
#include "UpdateArrowLevelMsg.h"
#include "WumpusRoomEnteredMsg.h"
#include "GoblinRoomEnteredMsg.h"
#include "GameLoop.h"
#include "GameLoopImpl.h"
#include "goblinMove.h"

namespace HtW
{

bool isValidMove(HtW::Cave* cave, int roomNumber)
{
    if (roomNumber < 0 || roomNumber > 19)
    {
        return false;
    }
    HtW::Room* targetRoom = &cave->getRoomByNumber(roomNumber);
    for (int i = 0; i < 3; i++)
    {
        if (targetRoom->pNeighbors[i]->content == HtW::Room::Content::PLAYER)
        {
            return true;
        }
    }
    return false;
}

void doMove(HtW::Cave* cave, int roomNumber)
{
    cave->getRoomByContent(HtW::Room::Content::PLAYER).content = HtW::Room::Content::EMPTY;
    cave->getRoomByNumber(roomNumber).content                  = HtW::Room::Content::PLAYER;
}

HtW::Message* CreateRoomEnteredMessage(HtW::Room::Content content, int roomNumber)
{
    using CT = HtW::Room::Content;
    switch (content)
    {
    case CT::EMPTY:
        return new HtW::RoomEnteredMsg(roomNumber);
    case CT::WUMPUS:
        return new HtW::WumpusRoomEnteredMsg(roomNumber);
    case CT::SUPER_BAT:
        return new HtW::SuperBatRoomEnteredMsg(roomNumber);
    case CT::DEEP_PIT:
        return new HtW::DeepPitRoomEnteredMsg(roomNumber);
    case CT::ARROW:
        return new HtW::ArrowRoomEnteredMsg(roomNumber, false);
    case CT::GOBLIN:
        return new HtW::GoblinRoomEnteredMsg(roomNumber);
    default:
        return nullptr;
    }
}

int MoveMsg::ID = -1;

int MoveMsg::GetID() const
{
    return MoveMsg::ID;
}

void MoveMsgHandler::Process(const Message& m)
{
    const MoveMsg& msg = static_cast<const MoveMsg&>(m);
    if (isValidMove(m_pCave, msg.roomNumber))
    {
        Message* enteredMsg = CreateRoomEnteredMessage(m_pCave->getRoomByNumber(msg.roomNumber).content, msg.roomNumber);
        doMove(m_pCave, msg.roomNumber);
        Room& currentGoblinRoom = m_pCave->getRoomByContent(HtW::Room::Content::GOBLIN);
        golbinMove(currentGoblinRoom, *m_pRandom, *m_pCave);
        m_pGameLoop->Push(enteredMsg);
    }
    else
    {
        m_pGameLoop->Push(new InvalidRoomMsg);
    }
}
} // namespace HtW
