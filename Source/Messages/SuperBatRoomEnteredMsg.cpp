#include "SuperBatRoomEnteredMsg.h"
#include "RoomEnteredMsg.h"
#include <chrono>
#include <iostream>
#include <thread>

namespace HtW
{
int SuperBatRoomEnteredMsg::ID = -1;
SuperBatRoomEnteredMsg::SuperBatRoomEnteredMsg(int roomNumber)
  : roomNumber(roomNumber)
{
}

int SuperBatRoomEnteredMsg::GetID() const
{
    return SuperBatRoomEnteredMsg::ID;
}

void SuperBatRoomEnteredMsgHandler::Process(const Message& message)
{
    const SuperBatRoomEnteredMsg& msg = static_cast<const SuperBatRoomEnteredMsg&>(message);
    using namespace std::chrono_literals;
    std::cout << "Du schaust einer Super-Fledermaus tief in die Augen!" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Sie fliegt auf dich zu, und trägt dich durch die Höhle" << std::endl;
    std::this_thread::sleep_for(3s);

    int playerRoom;
    int batRoom;
    do
    {
        playerRoom = m_pRandom->GenerateUnique(Range{0, HtW::Cave::NUMBER_ROOMS - 1});
    } while (m_pCave->getRoomByNumber(playerRoom).content != HtW::Room::Content::EMPTY);
    m_pCave->getRoomByNumber(playerRoom).content     = HtW::Room::Content::PLAYER;
    m_pCave->getRoomByNumber(msg.roomNumber).content = HtW::Room::Content::EMPTY;
    do
    {
        batRoom = m_pRandom->GenerateUnique(Range{0, HtW::Cave::NUMBER_ROOMS - 1});
    } while (m_pCave->getRoomByNumber(batRoom).content != HtW::Room::Content::EMPTY);
    m_pCave->getRoomByNumber(batRoom).content = HtW::Room::Content::SUPER_BAT;
    m_pGameLoop->Push(new RoomEnteredMsg(playerRoom));
}
} // namespace HtW