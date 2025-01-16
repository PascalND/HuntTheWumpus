#include "DeepPitRoomEnteredMsg.h"
#include "EndProgramMsg.h"
#include <iostream>
#include <thread>
#include <chrono>

namespace HtW
{
int DeepPitRoomEnteredMsg::ID = -1;
DeepPitRoomEnteredMsg::DeepPitRoomEnteredMsg(int roomNumber)
  : roomNumber(roomNumber)
{
}

int DeepPitRoomEnteredMsg::GetID() const
{
    return DeepPitRoomEnteredMsg::ID;
}

void DeepPitRoomEnteredMsgHandler::Process(const Message&)
{
    using namespace std::chrono_literals;
    std::cout << "Du fällst in ein tiefes Loch!" << std::endl;
    for(int i = 0; i < 10;i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::this_thread::sleep_for(1s);
            std::cout << ".";
        }
        std::this_thread::sleep_for(1s);
        std::cout << "\nDu fällst immernoch";
    }
    std::cout << "\nDu bist vor lauter langeweile gestorben!";
    m_pGameLoop->Push(new EndProgramMsg);
    std::cin.get();
}

} // namespace HtW