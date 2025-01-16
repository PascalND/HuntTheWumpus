#pragma once
#include "Message.h"

namespace HtW
{
	class InvalidRoomMsg : public Message
	{
	public:
		int GetID() const override;

		// Will set in App::InitMessageHandling to guaranty unique IDs
		static int ID;
	};

	class InvalidRoomMsgHandler : public MessageHandler
	{
	public:

		void Process(const Message&) override;
	};
} // namespace HtW
