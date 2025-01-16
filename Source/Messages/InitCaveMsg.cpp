#include "InitCaveMsg.h"
#include "RandomGenerator.h"
#include "RoomEnteredMsg.h"
#include <array>
#include <iostream>

void connectNeighbors(HtW::Cave* m_pCave, int room, std::array<int, 3> neighbors)
{
    m_pCave->rooms[room].pNeighbors[0] = &m_pCave->rooms[neighbors[0]];
    m_pCave->rooms[room].pNeighbors[1] = &m_pCave->rooms[neighbors[1]];
    m_pCave->rooms[room].pNeighbors[2] = &m_pCave->rooms[neighbors[2]];
}

// int initRandomAndGetPlayer(HtW::Cave* pCave, HtW::RandomGenerator* pRandom)
//{
//     int room;
//     do
//     {
//         room = pRandom->GenerateUnique(HtW::Range{0, pCave->NUMBER_ROOMS});
//     } while (pCave->rooms[room].content != HtW::Room::Content::EMPTY);
//     pCave->rooms[room].content = HtW::Room::Content::WUMPUS;
//
//     for (int i = 0; i < 2; i++)
//     {
//         do
//         {
//             room = pRandom->GenerateUnique(HtW::Range{0, pCave->NUMBER_ROOMS});
//         } while (pCave->rooms[room].content != HtW::Room::Content::EMPTY);
//         pCave->rooms[room].content = HtW::Room::Content::SUPER_BAT;
//     }
//
//     for (int i = 0; i < 2; i++)
//     {
//         do
//         {
//             room = pRandom->GenerateUnique(HtW::Range{0, pCave->NUMBER_ROOMS});
//         } while (pCave->rooms[room].content != HtW::Room::Content::EMPTY);
//         pCave->rooms[room].content = HtW::Room::Content::DEEP_PIT;
//     }
//
//     do
//     {
//         room = pRandom->GenerateUnique(HtW::Range{0, pCave->NUMBER_ROOMS});
//     } while (pCave->rooms[room].content != HtW::Room::Content::EMPTY);
//     pCave->rooms[room].content = HtW::Room::Content::PLAYER;
//     return room;
// }


HtW::Room::Content selectContent(int value)
{
    using C = HtW::Room::Content;
    switch (value)
    {
    case 0:
        return C::PLAYER;
    case 1:
        return C::WUMPUS;
    case 2:
    case 3:
        return C::DEEP_PIT;
    case 4:
    case 5:
        return C::SUPER_BAT;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        return C::ARROW;
    case 11:
        return C::GOBLIN;
    default:
        return C::EMPTY;
    }
}

int initRandomAndGetPlayer(HtW::Cave* pCave, HtW::RandomGenerator* pRandom)
{
    int  playerRoomIndex;
    int* arr = pRandom->GenerateShuffled(HtW::Range{0, HtW::Cave::NUMBER_ROOMS - 1});
    for (int i = 0; i < pCave->NUMBER_ROOMS; i++)
    {
        pCave->rooms[i].content = selectContent(arr[i]);
        if (HtW::Room::Content::PLAYER == pCave->rooms[i].content)
        {
            playerRoomIndex = i;
        }
    }
    delete[] arr;
    return pCave->rooms[playerRoomIndex].number;
}

namespace HtW
{
int InitCaveMsg::ID = -1;

int InitCaveMsg::GetID() const
{
    return InitCaveMsg::ID;
}

void InitCaveMsgHandler::Process(const Message&)
{
    int* arr = m_pRandom->GenerateShuffled(HtW::Range{0, HtW::Cave::NUMBER_ROOMS - 1}); 
    for (int i = 0; i < HtW::Cave::NUMBER_ROOMS; i++)
    {
        m_pCave->rooms[i].number = arr[i];
    }
    delete[] arr;
    int playerRoom = initRandomAndGetPlayer(m_pCave, m_pRandom);
    // do
    //{
    //     room = m_pRandom->GenerateUnique(Range{0, HtW::Cave::NUMBER_ROOMS});
    // } while (m_pCave->rooms[room].content != HtW::Room::Content::EMPTY);
    // m_pCave->rooms[5].content  = Room::Content::WUMPUS;
    // m_pCave->rooms[12].content = Room::Content::SUPER_BAT;
    // m_pCave->rooms[18].content = Room::Content::SUPER_BAT;
    // m_pCave->rooms[1].content  = Room::Content::DEEP_PIT;
    // m_pCave->rooms[15].content = Room::Content::DEEP_PIT;
    // m_pCave->rooms[16].content = Room::Content::PLAYER;
    connectNeighbors(m_pCave, 0, {1, 4, 7});
    connectNeighbors(m_pCave, 1, {0, 2, 9});
    connectNeighbors(m_pCave, 2, {1, 3, 11});
    connectNeighbors(m_pCave, 3, {2, 4, 13});
    connectNeighbors(m_pCave, 4, {0, 3, 5});
    connectNeighbors(m_pCave, 5, {4, 6, 14});
    connectNeighbors(m_pCave, 6, {5, 7, 16});
    connectNeighbors(m_pCave, 7, {0, 6, 8});
    connectNeighbors(m_pCave, 8, {7, 9, 17});
    connectNeighbors(m_pCave, 9, {1, 8, 10});
    connectNeighbors(m_pCave, 10, {9, 11, 18});
    connectNeighbors(m_pCave, 11, {2, 10, 12});
    connectNeighbors(m_pCave, 12, {11, 13, 19});
    connectNeighbors(m_pCave, 13, {3, 12, 14});
    connectNeighbors(m_pCave, 14, {5, 13, 15});
    connectNeighbors(m_pCave, 15, {14, 16, 19});
    connectNeighbors(m_pCave, 16, {6, 15, 17});
    connectNeighbors(m_pCave, 17, {8, 16, 18});
    connectNeighbors(m_pCave, 18, {10, 17, 19});
    connectNeighbors(m_pCave, 19, {12, 15, 18});
    Print(*m_pCave);
    m_pGameLoop->Push(new RoomEnteredMsg(playerRoom));
}

} // namespace HtW
