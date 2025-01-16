#include "UpdateArrowLevelMsg.h"
#include "EndProgramMsg.h"
#include <chrono>
#include <iostream>
#include <thread>

namespace HtW
{
bool UpdateArrowLevelMsgHandler::arrowsAvailable() const
{
    return m_pCave->getRoomByContent(HtW::Room::Content::ARROW).number != -1;
}
int UpdateArrowLevelMsg::ID = -1;

UpdateArrowLevelMsg::UpdateArrowLevelMsg(bool addArrow)
  : addArrow(addArrow)
{
}

int UpdateArrowLevelMsg::GetID() const
{
    return UpdateArrowLevelMsg::ID;
}
void UpdateArrowLevelMsgHandler::Process(const Message& message)
{
    using namespace std::chrono_literals;
    const UpdateArrowLevelMsg& updateMsg = static_cast<const UpdateArrowLevelMsg&>(message);

    if (updateMsg.addArrow)
    {
        (*m_arrows)++;
    }
    else
    {
        if (*m_arrows > 0)
        {
            (*m_arrows)--;
        }
        if (*m_arrows < 1 && !arrowsAvailable())
        {
            std::cout << "Du hast das Spiel verloren, du hast keine Pfeile mehr!";
            m_pGameLoop->Push(new EndProgramMsg());
            std::cin.get();
        }
        else
        {
            std::cout << "\nDu hast " << *m_arrows << " Pfeile zur Verfügung.\n";
        }
    }
}

} // namespace HtW