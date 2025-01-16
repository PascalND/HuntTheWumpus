#pragma once
#include "Cave.h"
#include "GameLoop.h"
#include "InitCaveMsg.h"
#include "Message.h"
#include "MessageHandlerBase.h"
#include "RoomEnteredMsg.h"

namespace HtW
{
class MoveMsg : public Message
{
public:
    MoveMsg(int roomNumber)
      : roomNumber(roomNumber)
    {
    }
    int GetID() const override;

    // Will set in App::InitMessageHandling to guaranty unique IDs
    static int ID;
    int        roomNumber;
};

class MoveMsgHandler : public MessageHandlerBase
{
public:
    using MessageHandlerBase::MessageHandlerBase;

    void Process(const Message&) override;
};
} // namespace HtW