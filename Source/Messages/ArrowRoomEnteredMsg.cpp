#include "ArrowRoomEnteredMsg.h"
#include "EndProgramMsg.h"
#include "RandomGenerator.h"
#include "RoomEnteredMsg.h"
#include "UpdateArrowLevelMsg.h"
#include <chrono>
#include <iostream>
#include <thread>

namespace HtW
{
int ArrowRoomEnteredMsg::ID = -1;
ArrowRoomEnteredMsg::ArrowRoomEnteredMsg(int roomNumber, bool addArrow)
  : roomNumber(roomNumber)
  , addArrow(addArrow)
{
}

int ArrowRoomEnteredMsg::GetID() const
{
    return ArrowRoomEnteredMsg::ID;
}

void ArrowRoomEnteredMsgHandler::Process(const Message& message)
{
    const ArrowRoomEnteredMsg& arrowRoomMsg = static_cast<const ArrowRoomEnteredMsg&>(message);

    using namespace std::chrono_literals;

    int   roomNumber  = arrowRoomMsg.roomNumber;
    Room& currentRoom = m_pCave->getRoomByNumber(roomNumber);
    m_pGameLoop->Push(new UpdateArrowLevelMsg(true));
    m_pGameLoop->Push(new RoomEnteredMsg(roomNumber));
    //std::this_thread::sleep_for(3s);
}

} // namespace HtW