#include "RoomEnteredMsg.h"
#include "ArrowRoomEnteredMsg.h"
#include "UpdateArrowLevelMsg.h"
#include <array>
#include <iostream>

bool isNeighborOf(HtW::Room* room, HtW::Room::Content content)
{
    for (int i = 0; i < 3; i++)
    {
        if (room->pNeighbors[i]->content == content)
            return true;
    }
    return false;
}
bool isNeighborOfWumpus(HtW::Room* room)
{
    return isNeighborOf(room, HtW::Room::Content::WUMPUS);
}

bool isNeighborOfSuperBat(HtW::Room* room)
{
    return isNeighborOf(room, HtW::Room::Content::SUPER_BAT);
}

bool isNeighborOfDeepPit(HtW::Room* room)
{
    return isNeighborOf(room, HtW::Room::Content::DEEP_PIT);
}

bool isNeighborOfGoblin(HtW::Room* room)
{
    return isNeighborOf(room, HtW::Room::Content::GOBLIN);
}

void evaluateNeighbors(HtW::Room* room)
{
    if (isNeighborOfWumpus(room))
    {
        std::cout << "\tEs riecht schrecklich" << std::endl;
    }
    if (isNeighborOfSuperBat(room))
    {
        std::cout << "\tEs raschelt" << std::endl;
    }
    if (isNeighborOfDeepPit(room))
    {
        std::cout << "\tEin kalter Windzug" << std::endl;
    }
    if (isNeighborOfGoblin(room))
    {
        std::cout << "\tDu hörst ein leises lachen" << std::endl;
    }
}

namespace HtW
{
int RoomEnteredMsg::ID = -1;

RoomEnteredMsg::RoomEnteredMsg(int roomNumber)
	: roomNumber(roomNumber)
{
}

int RoomEnteredMsg::GetID() const
{
    return RoomEnteredMsg::ID;
}

void RoomEnteredMsgHandler::Process(const Message& m)
{
	const RoomEnteredMsg& msg = static_cast<const RoomEnteredMsg&>(m);
    Print(*m_pCave);
    Room* room = &m_pCave->getRoomByNumber(msg.roomNumber);
	std::cout << "Du bist im Raum " << room->number << std::endl;
	evaluateNeighbors(room);
	std::cout << "Tunnel nach " << room->pNeighbors[0]->number << ", "
              << room->pNeighbors[1]->number << ", " 
              << room->pNeighbors[2]->number << std::endl;
    std::cout << "Du hast noch " << *m_arrows << " Pfeile zur Verfügung" << std::endl;
}
} // namespace HtW
