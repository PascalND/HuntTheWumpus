#pragma once
#include "Cave.h"
#include "GameLoop.h"
#include "Message.h"
#include "MessageHandlerBase.h"

namespace HtW
{
class GoblinRoomEnteredMsg : public Message
{
public:
    GoblinRoomEnteredMsg(int roomNumber);
    int GetID() const override;

    // Will set in App::InitMessageHandling to guaranty unique IDs
    static int ID;
    int        roomNumber;
};

class GoblinRoomEnteredMsgHandler : public MessageHandlerBase
{
public:
    using MessageHandlerBase::MessageHandlerBase;
    void Process(const Message&) override;
};
} // namespace HtW