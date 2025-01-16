#include "GoblinRoomEnteredMsg.h"
#include "EndProgramMsg.h"
#include "RandomGenerator.h"
#include "RoomEnteredMsg.h"
#include "UpdateArrowLevelMsg.h"
#include "UserInputMsg.h"
#include "goblinMove.h"
#include <chrono>
#include <iostream>
#include <thread>

namespace HtW
{

int GoblinRoomEnteredMsg::ID = -1;
GoblinRoomEnteredMsg::GoblinRoomEnteredMsg(int roomNumber)
  : roomNumber(roomNumber)
{
}

int GoblinRoomEnteredMsg::GetID() const
{
    return GoblinRoomEnteredMsg::ID;
}
void GoblinRoomEnteredMsgHandler::Process(const Message& message)
{
    const GoblinRoomEnteredMsg& msg = static_cast<const GoblinRoomEnteredMsg&>(message);
    using namespace std::chrono_literals;

    if (*m_arrows == 0)
    {
        int room;
        room = m_pRandom->GenerateUnique({0, 2});
        if (room == 0)
        {
            std::cout << "\nDer Goblin ist ganz schön angepisst, dass du keine Pfeile hast.." << std::endl;
            std::this_thread::sleep_for(3s);
            std::cout << "Er greift dich an und du wurdest von einer Bierflasche zutode geprügelt" << std::endl;
            std::this_thread::sleep_for(3s);
            m_pGameLoop->Push(new EndProgramMsg);
            std::cin.get();
        }
        else
        {
            std::cout << "\nDer Goblin guckt dich fragend und betrunken an..." << std::endl;
            std::this_thread::sleep_for(3s);
            std::cout << "\nEr probiert dich anzugreifen";
            for (int j = 0; j < 3; j++)
            {
                std::this_thread::sleep_for(1s);
                std::cout << ".";
            }
            std::cout << "\nEr stolpert und fällt in den nächsten Raum" << std::endl;
            Room& currentGoblinRoom = m_pCave->getRoomByNumber(msg.roomNumber);
            HtW::doGolbinMove(currentGoblinRoom, *m_pRandom, *m_pCave);
        }
    }
    else
    {
        std::cout << "\nDer Goblin rennt auf dich zu und flüchtet mit einem Pfeil von dir aus den Raum" << std::endl;
        std::this_thread::sleep_for(3s);
        m_pGameLoop->Push(new UpdateArrowLevelMsg(false));
        m_pGameLoop->Push(new RoomEnteredMsg(msg.roomNumber));
        Room& currentGoblinRoom = m_pCave->getRoomByContent(HtW::Room::Content::GOBLIN);
        HtW::doGolbinMove(currentGoblinRoom, *m_pRandom, *m_pCave);
    }
}

} // namespace HtW