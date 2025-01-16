#pragma once
#include "Cave.h"
#include "GameLoop.h"
#include "Message.h"
#include "MessageHandlerBase.h"


namespace HtW
{
class UpdateArrowLevelMsg : public Message
{
public:
    UpdateArrowLevelMsg(bool addArrow);
    int GetID() const override;

    // Will set in App::InitMessageHandling to guaranty unique IDs
    static int ID;
    bool       addArrow;
    
};

class UpdateArrowLevelMsgHandler : public MessageHandlerBase
{
public:
    using MessageHandlerBase::MessageHandlerBase;
    void Process(const Message&) override;
    bool arrowsAvailable() const;
};
} // namespace HtW