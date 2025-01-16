#include "UserInputMsg.h"
#include "EndProgramMsg.h"
#include "MoveMsg.h"
#include "ShootMsg.h"
#include "UpdateArrowLevelMsg.h"
#include <iostream>
#include <string>

namespace HtW
{
int UserInputMsg::ID = -1;

int UserInputMsg::GetID() const
{
    return UserInputMsg::ID;
}

//void golbinMove(Room& currentGoblinRoom, RandomGenerator& m_pRandom, Cave& m_pCave)
//{
//    int   numberPossibleRooms = 0;
//    int   possibleRooms[3];
//    int   room;
//    room = m_pRandom.GenerateUnique({0, 2});
//    if (room == 2)
//    {
//        for (int i = 0; i < 3; i++)
//        {
//            if (currentGoblinRoom.pNeighbors[i]->content == HtW::Room::Content::PLAYER || currentGoblinRoom.pNeighbors[i]->content == HtW::Room::Content::EMPTY)
//            {
//                possibleRooms[numberPossibleRooms] = i;
//                numberPossibleRooms++;
//            }
//        }
//
//        if (numberPossibleRooms > 0)
//        {
//            int   index                  = m_pRandom.GenerateUnique({0, numberPossibleRooms - 1});
//            int   targetGoblinRoomNumber = currentGoblinRoom.pNeighbors[possibleRooms[index]]->number;
//            Room& targetGoblinRoom       = m_pCave.getRoomByNumber(targetGoblinRoomNumber);
//            currentGoblinRoom.content    = HtW::Room::Content::EMPTY;
//            targetGoblinRoom.content     = HtW::Room::Content::GOBLIN;
//        }
//    }
//}

void UserInputMsgHandler::Process(const Message&)
{
    std::cout << "\n(A)bbrechen?, (M)ove?, (S)hoot?" << std::endl;
    std::string buffer{};
    std::cin >> buffer;
    char choice = buffer[0];
    if (choice == 'A' or choice == 'a')
    {
        std::cout << "Game Over!";
        m_pGameLoop->Push(new EndProgramMsg);
    }
    if (choice == 'm' || choice == 'M')
    {
        int         roomNumber;
        std::string strRoomNumber;
        std::cout << "Wohin du Lauch?" << std::endl;
        std::cin >> strRoomNumber;
        try
        {
            roomNumber = std::stoi(strRoomNumber);
        }
        catch (...)
        {
            roomNumber = -1;
        }
        m_pGameLoop->Push(new MoveMsg(roomNumber));
    }
    if (choice == 'S' || choice == 's')
    {
        int         roomNumber;
        std::string strRoomNumber;
        std::cout << "Schieß doch endlich" << std::endl;
        std::cin >> strRoomNumber;
        try
        {
            roomNumber = std::stoi(strRoomNumber);
        }
        catch (...)
        {
            roomNumber = -1;
        }
        m_pGameLoop->Push(new ShootMsg(roomNumber));
    }
}

} // namespace HtW
