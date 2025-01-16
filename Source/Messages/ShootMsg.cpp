#include "ShootMsg.h"
#include "EndProgramMsg.h"
#include "RandomGenerator.h"
#include "RoomEnteredMsg.h"
#include "UpdateArrowLevelMsg.h"
#include "SuperBatRoomEnteredMsg.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()

using namespace std::chrono_literals;

namespace HtW
{

bool areNeighbors(const Room& from, const Room& to)
{
    for (int i = 0; i < 3; i++)
    {
        if (from.pNeighbors[i]->number == to.number)
            return true;
    }
    return false;
}
bool isValidShot(const Room& from, const Room& to)
{
    return areNeighbors(from, to);
}

void wumpusMove(Room& currentWumpusRoom, RandomGenerator& m_pRandom, Cave& m_pCave)
{
    int numberPossibleRooms = 0;
    int possibleRooms[3];

    for (int i = 0; i < 3; i++)
    {
        if (currentWumpusRoom.pNeighbors[i]->content == HtW::Room::Content::PLAYER || currentWumpusRoom.pNeighbors[i]->content == HtW::Room::Content::EMPTY)
        {
            possibleRooms[numberPossibleRooms] = i;
            numberPossibleRooms++;
        }
    }

    if (numberPossibleRooms > 0)
    {
        int   index                  = m_pRandom.GenerateUnique({0, numberPossibleRooms - 1});
        int   targetWumpusRoomNumber = currentWumpusRoom.pNeighbors[possibleRooms[index]]->number;
        Room& targetWumpusRoom       = m_pCave.getRoomByNumber(targetWumpusRoomNumber);
        currentWumpusRoom.content    = HtW::Room::Content::EMPTY;
        targetWumpusRoom.content     = HtW::Room::Content::WUMPUS;
        std::cout << "Der Wumpus erwachte und bewegte sich in einer seiner benachbarten Räume." << std::endl;
    }
}

void printDeathPlayerEndGameMessage()
{
    std::cout << "Der Wumpus kommt in deinen Raum";
    for (int j = 0; j < 3; j++)
    {
        std::this_thread::sleep_for(1s);
        std::cout << ".";
    }
    std::cout << "\nWährend der Wumpus langsam aufstand, erblickst du seine riesige Gestalt in der Dunkelheit\n" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Seine riesigen Klauen schnellten hoch.\n" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Du erstarrst vor Entsetzen" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Du versuchst zu fliehen, aber deine Füße bewegen sich nicht\n" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Der Wumpus kommt näher und näher";
    for (int j = 0; j < 3; j++)
    {
        std::this_thread::sleep_for(1s);
        std::cout << ".";
    }
    std::this_thread::sleep_for(1s);
    std::cout << "\n\nEr schaut dich mit einen gierigen Blick an und du hörst nur das dumpfe Grollen seines Magens.\n" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Mit einem gewaltigen Biss verschlingt dich der Wumpus und die Dunkelheit der Höhle verschluckt deine Schreie\n" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Die Höhle kehrte zur Stille zurück, und der Wumpus ließ sich wieder nieder, um weiter zu schlafen.\n" << std::endl;
    std::this_thread::sleep_for(3s);
}
void printDeathWumpusEndGameMessage()
{
    std::cout << "Du schießt den Pfeil, in den Raum wo sich der Wumpus befindet.";
    for (int j = 0; j < 3; j++)
    {
        std::this_thread::sleep_for(1s);
        std::cout << ".";
    }
    std::cout << "\nDu hörst ein lautes brüllen aus dem benachbarten Raum." << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Der Wumpus stolpert langsam in deinen Raum, mit einem Pfeil tief in seiner Brust." << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Er kommt dir immer näher und näher";
    for (int j = 0; j < 3; j++)
    {
        std::this_thread::sleep_for(1s);
        std::cout << ".";
    }
    std::cout << std::endl;
    std::cout << "Bis er vor dir langsam auf den Boden sackte und sein Atmen verstummt." << std::endl;
    std::this_thread::sleep_for(3s);

    int len = 0, x, y = 1; // 240 = white background, black foreground

    std::string text = "Du hast es geschafft, den Wumpus zu töten!";
    len              = text.length();
    SetConsoleTextAttribute(console, 0);
    std::cout << std::endl << std::endl << std::endl << "\t\t"; // start 3 down, 2 tabs, right
    for (x = 0; x < len; x++)
    {
        SetConsoleTextAttribute(console, y); // set color for the next print
        std::cout << text[x];
        y++;        // add 1 to y, for a new color
        if (y > 15) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
            y = 1;  // if y > 254, start colors back at white background, black chars
        Sleep(150); // Pause between letters
    }

    SetConsoleTextAttribute(console, 15); // set color to black background, white chars
    std::this_thread::sleep_for(3s);
}

void printDeathSuperBatMessage()
{
    std::cout << "Du hast die Fledermaus getroffen und besiegt!" << std::endl;
    std::this_thread::sleep_for(2s);
    std::cout << "Der Raum ist nun frei von der Fledermaus." << std::endl;
    std::this_thread::sleep_for(2s);
    std::cout << "Fortsetzung des Abenteuers..." << std::endl;
}

void printDeathGoblinMessage()
{
    std::cout << "Du hast den Goblin getroffen und besiegt!" << std::endl;
    std::this_thread::sleep_for(2s);
    std::cout << "Er hatte einen Pfeil dabei, gehe in seinen Raum um seinen Pfeil zu bekommen";
    std::this_thread::sleep_for(2s);
    std::cout << "Fortsetzung des Abenteuers..." << std::endl;
    
}


int ShootMsg::ID = -1;
ShootMsg::ShootMsg(int roomNumber)
  : roomNumber(roomNumber)
{
}

int ShootMsg::GetID() const
{
    return ShootMsg::ID;
}

void ShootMsgHandler::Process(const Message& message)
{
    const ShootMsg& msg = static_cast<const ShootMsg&>(message);

    int   room;
    Room& currentRoom = m_pCave->getRoomByContent(HtW::Room::Content::PLAYER);
    Room& targetRoom  = m_pCave->getRoomByNumber(msg.roomNumber);


    if (*m_arrows > 0 && isValidShot(currentRoom, targetRoom))
    {
        if (targetRoom.content == HtW::Room::Content::WUMPUS)
        {
            printDeathWumpusEndGameMessage();
            m_pGameLoop->Push(new EndProgramMsg());
            std::cin.get();
            return;
        }
        else
        {
            m_pGameLoop->Push(new UpdateArrowLevelMsg(false));
            room = m_pRandom->GenerateUnique(Range{0, 3});
            if (room == 3)
            {
                for (int j = 0; j < 3; j++)
                {
                    std::this_thread::sleep_for(1s);
                    std::cout << ".";
                }
                std::this_thread::sleep_for(1s);
                std::cout << "Der Wumpus ist nicht erwacht";
            }
            else
            {
                Room& currentWumpusRoom      = m_pCave->getRoomByContent(HtW::Room::Content::WUMPUS);
                int   targetWumpusRoomNumber = currentWumpusRoom.pNeighbors[room]->number;
                Room& targetWumpusRoom       = m_pCave->getRoomByNumber(targetWumpusRoomNumber);
                if (targetWumpusRoom.content == HtW::Room::Content::PLAYER)
                {
                    printDeathPlayerEndGameMessage();
                    m_pGameLoop->Push(new EndProgramMsg());
                    std::cin.get();
                }
                else
                {
                    wumpusMove(currentWumpusRoom, *m_pRandom, *m_pCave);
                    Room& playerRoom = m_pCave->getRoomByContent(HtW::Room::Content::PLAYER);
                    int   player     = playerRoom.number;
                    std::this_thread::sleep_for(3s);
                    // m_pGameLoop->Push(new RoomEnteredMsg(player));
                }
            }
        }
        if (targetRoom.content == HtW::Room::Content::SUPER_BAT)
        {
            room = m_pRandom->GenerateUnique(Range{0, 3});
            if (room == 3)
            {
                printDeathSuperBatMessage();
                targetRoom.content = HtW::Room::Content::EMPTY;
            }
            else
            {
                currentRoom.content = HtW::Room::Content::EMPTY;
                m_pGameLoop->Push(new SuperBatRoomEnteredMsg(targetRoom.number));
            }
        }
        if (targetRoom.content == HtW::Room::Content::GOBLIN)
        {
            printDeathGoblinMessage();
            targetRoom.content = HtW::Room::Content::ARROW;
            m_pGameLoop->Push(new RoomEnteredMsg(currentRoom.number));
        }
    }
    else
    {
        if (*m_arrows == 0)
        {
            std::cout << "Du hast keine Pfeile - gehe welche sammeln!";
        }
        else
        {
            std::cout << "Noob";
        }
    }
    
}
} // namespace HtW