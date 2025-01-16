#pragma once
#include "Cave.h"
#include "GameLoop.h"
#include "Message.h"
#include "MessageHandlerBase.h"

namespace HtW
{
class ArrowRoomEnteredMsg : public Message
{
public:
    ArrowRoomEnteredMsg(int roomNumber, bool addArrow);
    int GetID() const override;

    // Will set in App::InitMessageHandling to guaranty unique IDs
    static int ID;
    int        roomNumber;
    bool       addArrow;
};

class ArrowRoomEnteredMsgHandler : public MessageHandlerBase
{
public:
    using MessageHandlerBase::MessageHandlerBase;
    void Process(const Message&) override;
};
} // namespace HtW