#pragma once

namespace HtW
{
	//Trennung zwischen Message und Handler, damit der Aufrufer mehr entkoppelt ist vom Bearbeiter
	class Message
	{
	public:
		//ID wird benötigt um den passenden NachrichtenHandler auszuwählen
		virtual int GetID() const = 0;
		virtual ~Message() = default;
	};

	class MessageHandler
	{
	public:
		//Abarbeitung der Nachricht
		virtual void Process(const Message&) = 0;
		virtual ~MessageHandler() = default;
	};

} // namespace HtW
