#pragma once
#include "Message.h"
#include "GameLoop.h"
#include "MessageHandlerBase.h"

namespace HtW
{
	class UserInputMsg : public Message
	{
	public:
		int GetID() const override;

		static int ID;
	};

	class UserInputMsgHandler : public MessageHandlerBase
	{
	public:
		using MessageHandlerBase::MessageHandlerBase;
		void Process(const Message&) override;
	};
} // namespace HtW
