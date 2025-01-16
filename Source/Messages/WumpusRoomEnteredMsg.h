#pragma once
#include "Cave.h"
#include "GameLoop.h"
#include "Message.h"
#include "MessageHandlerBase.h"

namespace HtW
{
class WumpusRoomEnteredMsg : public Message
{
public:
    WumpusRoomEnteredMsg(int roomNumber);
    int GetID() const override;

    // Will set in App::InitMessageHandling to guaranty unique IDs
    static int ID;
    int        roomNumber;
};

class WumpusRoomEnteredMsgHandler : public MessageHandlerBase
{
public:
    using MessageHandlerBase::MessageHandlerBase;
    void Process(const Message&) override;
};
} // namespace HtW