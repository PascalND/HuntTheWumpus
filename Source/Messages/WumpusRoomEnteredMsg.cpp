#include "WumpusRoomEnteredMsg.h"
#include "EndProgramMsg.h"
#include "RoomEnteredMsg.h"
#include <chrono>
#include <iostream>
#include <thread>

namespace HtW
{
int WumpusRoomEnteredMsg::ID = -1;
WumpusRoomEnteredMsg::WumpusRoomEnteredMsg(int roomNumber)
  : roomNumber(roomNumber)
{
}

int WumpusRoomEnteredMsg::GetID() const
{
    return WumpusRoomEnteredMsg::ID;
}

void WumpusRoomEnteredMsgHandler::Process(const Message& message)
{
    const WumpusRoomEnteredMsg& msg = static_cast<const WumpusRoomEnteredMsg&>(message);
    using namespace std::chrono_literals;
    std::cout << "Der Gestank in diesem Raum ist unertr�glich" << std::endl;
    std::cout << "Der Wumpus erwachte pl�tzlich mit einem markersch�tternden Br�llen!" << std::endl;
    std::this_thread::sleep_for(5s);
    if (m_pRandom->GenerateUnique(Range{0, 3}) == 0)
    {
        std::cout << "Seine riesigen Klauen schnellten hoch.\n" << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "Du erstarrst vor Entsetzen" << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "W�hrend der Wumpus langsam aufstand, erblickst du seine riesige Gestalt in der Dunkelheit\n" << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "Du versuchst zu fliehen, aber deine F��e bewegen sich nicht\n" << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "Der Wumpus kommt n�her und n�her";
        for (int j = 0; j < 3; j++)
        {
            std::this_thread::sleep_for(1s);
            std::cout << ".";
        }
        std::this_thread::sleep_for(1s);
        std::cout << "\n\nEr schaut dich mit einen gierigen Blick an und du h�rst nur das dumpfe Grollen seines Magens.\n" << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "Mit einem gewaltigen Biss verschlingt dich der Wumpus und die Dunkelheit der H�hle verschluckt deine Schreie\n" << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "Die H�hle kehrte zur Stille zur�ck, und der Wumpus lie� sich wieder nieder, um weiter zu schlafen.\n" << std::endl;
        std::this_thread::sleep_for(3s);
        m_pGameLoop->Push(new EndProgramMsg);
        std::cin.get();
    }
    else
    {
        std::cout << "Der Wumpus hat dich nicht bemerkt und verl�sst den Raum" << std::endl;
        std::this_thread::sleep_for(3s);
        int room;
        do
        {
            room = m_pRandom->GenerateUnique(Range{0, 2});
        } while (m_pCave->getRoomByNumber(msg.roomNumber).pNeighbors[room]->content != HtW::Room::Content::EMPTY);
        int targetRoom                     = m_pCave->getRoomByNumber(msg.roomNumber).pNeighbors[room]->number;
        m_pCave->getRoomByNumber(targetRoom).content = HtW::Room::Content::WUMPUS;
        m_pGameLoop->Push(new RoomEnteredMsg(msg.roomNumber));
    }
}

} // namespace HtW