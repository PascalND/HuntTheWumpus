#pragma once
#include "Message.h"
#include "GameLoop.h"
#include "Cave.h"
#include "MessageHandlerBase.h"

namespace HtW
{
	class InitCaveMsg : public Message
	{
	public:
		int GetID() const override;

		//Will set in App::InitMessageHandling to guaranty unique IDs
		static int ID;
	};

	class InitCaveMsgHandler : public MessageHandlerBase
	{
	public:
      using MessageHandlerBase::MessageHandlerBase;

		void Process(const Message&) override;
	};
} // namespace HtW
