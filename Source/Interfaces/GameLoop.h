#pragma once
#include "Message.h"

namespace HtW
{
	class GameLoop
	{
	public:
		//Nachricht der Nachrichtschleife hinzufügen, Abarbeitung erst im nächsten Durchlauf
		virtual void Push(Message*) = 0;
		virtual ~GameLoop() = default;
	};
} // namespace HtW
