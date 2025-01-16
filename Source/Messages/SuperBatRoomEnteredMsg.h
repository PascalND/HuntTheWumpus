#pragma once
#include "Cave.h"
#include "GameLoop.h"
#include "Message.h"
#include "MessageHandlerBase.h"
#include "RandomGenerator.h"

namespace HtW
{
class SuperBatRoomEnteredMsg : public Message
{
public:
    SuperBatRoomEnteredMsg(int roomNumber);
    int GetID() const override;

    // Will set in App::InitMessageHandling to guaranty unique IDs
    static int ID;
    int        roomNumber;
};

class SuperBatRoomEnteredMsgHandler : public MessageHandlerBase
{
public:
    using MessageHandlerBase::MessageHandlerBase;
    void Process(const Message&) override;



};
} // namespace HtW